#include "Game.hpp"
#include <iostream>
#include <cmath>


Game::Game(): window(sf::VideoMode(gm::Window::WIDTH, gm::Window::HEIGHT), "Game"), elapsedTime(sf::Time::Zero), offset(0) {}

void Game::start(){
    loadSprites();
    createPlayer();
    createBackground();
    createEnemy({20*3, 6*3});
    createEnemy({40*3, 0*3});
    window.setVisible(true);
    while(window.isOpen()) loop();
}

void Game::loadSprites(){
    rm.loadTexture("sprites", "media/game_sprites.png");
    rm.loadTexture("background", "media/background.png");
}

void Game::createPlayer(){
    player.setTexture(rm.getTexture("sprites"));
}

void Game::createEnemy(sf::Vector2f position){
    Enemy enemy(position);
    enemy.setTexture(rm.getTexture("sprites"));
    enemies.insertTail(enemy);
}

void Game::createDeadEnemy(sf::Vector2f position){
    DeadEnemy deadEnemy(position);
    deadEnemy.move({- 8 * gm::Window::SCALE, - 8 * gm::Window::SCALE});
    deadEnemy.setTexture(rm.getTexture("sprites"));
    deadEnemies.insertTail(deadEnemy);
}

void Game::createBackground(){
    background.setTexture(rm.getTexture("background"));
}


void Game::loop(){
    eventHandler();
    inputHandler();
    elapsedTime += clock.restart();
    bool updated = false;
    while(elapsedTime >= gm::Timestep::FIXED){
        elapsedTime -= gm::Timestep::FIXED;
        updateLogic();
        updateAnimations();
        updated = true;
    }
    if(updated) render();
}

void Game::inputHandler(){
    sf::Vector2f v = {0, 0};
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        v.x += -gm::Player::SPEED;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        v.x += gm::Player::SPEED;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        if(player.getShootCooldown() == 0){
            player.resetShootCooldown();
            player.shoot(rm.getTexture("sprites"));
        }
    }
    player.setVelocity(v);
}

void Game::eventHandler(){
    sf::Event event;
    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window.close();
        }
   }
}

void Game::updateLogic(){
    updateDeadEnemies();
    updateShootColdown();
    moveEntities();
    updateEnemiesShoot();
    collisionHandler();
}

void Game::updateShootColdown(){
    while(enemies.hasNext()){
        enemies.getNextNodeData().stepShootCooldown();
    }
    player.stepShootCooldown();
}

void Game::moveEntities(){
    //player
    player.moveEntity();
    //bullets
    while(player.hasNextBullet()){
        Bullet * bullet = &player.getNextBullet();
        bullet->moveEntity();
        if(bullet->getPosition().y < gm::Bullet::UP_BORDER){
            player.deleteBullet(*bullet);
        }
    }
    //enemies
    Enemy::stepOffset();
    while(enemies.hasNext()){
        Enemy &enemy = enemies.getNextNodeData();
        while(enemy.hasNextBullet()){
            Bullet *bullet = &enemy.getNextBullet();
            bullet->moveEntity();
            if(bullet->getPosition().y > gm::Bullet::DOWN_BORDER){
                enemy.deleteBullet(*bullet);
            }
        }
        enemy.moveEntity();
    }
}

void Game::updateEnemiesShoot(){
    while(enemies.hasNext()){
        Enemy* enemy = &enemies.getNextNodeData();
        if(enemy->getShootCooldown() == 0 && enemy->getCanShoot()){
            enemy->resetShootCooldown();
            int x = gm::randomInt(0,1);
            if(x == 0){
                std::cout << "shooting!" << std::endl;
                enemy->shoot(rm.getTexture("sprites"));
            }
        }
    }
}

void Game::updateDeadEnemies(){
    while(deadEnemies.hasNext()){
        DeadEnemy *deadEnemy = &deadEnemies.getNextNodeData();
        deadEnemy->reduceDeathCounter();
        if(deadEnemy->getDeathCounter() <= 0){
            deadEnemies.deleteNode(*deadEnemy);
        }
    }
}

void Game::collisionHandler(){
    //player hits enemy

    // enemy bullets
    bool playerIsAlive = true;
    while(enemies.hasNext()){
        Enemy *enemy = &enemies.getNextNodeData();
        playerIsAlive = true;
        while(enemy->hasNextBullet() && playerIsAlive){
            Bullet *bullet = &enemy->getNextBullet();
            if(player.collisionCheck(bullet)){
                bullet->modifyHealth(-1);
                if(bullet->getHealth() <= 0){
                    enemy->deleteBullet(*bullet);
                }
                player.modifyHealth(-1);
                if(player.getHealth() <= 0){
                    std::cout << "player killed!" << std::endl;
                    playerIsAlive = false;
                }
            }
        }
    }
    //player bullets
    bool enemyIsAlive = true;
    while(enemies.hasNext()){
        Enemy *enemy = &enemies.getNextNodeData();
        enemyIsAlive = true;
        while(player.hasNextBullet() && enemyIsAlive){
            Bullet *bullet = &player.getNextBullet();
            if(enemy->collisionCheck(bullet)){
                    bullet->modifyHealth(-1);
                    if(bullet->getHealth() <= 0){
                        player.deleteBullet(*bullet);
                    }
                    enemy->modifyHealth(-1);
                    if(enemy->getHealth() <= 0){
                        createDeadEnemy(enemy->getPosition());
                        enemies.deleteNode(*enemy);
                        enemyIsAlive = false;
                    }
            }
        }
    }
}

void Game::render(){
    window.clear();
    window.draw(background);
    renderEntities();
    window.draw(player);
    window.display();
}

void Game::renderEntities(){
    while(player.hasNextBullet()){
        window.draw(player.getNextBullet());
    }
    while(enemies.hasNext()){
        Enemy &enemy = enemies.getNextNodeData();
        while(enemy.hasNextBullet()){
            window.draw(enemy.getNextBullet());
        }
        window.draw(enemy);
    }
    while(deadEnemies.hasNext()){
        window.draw(deadEnemies.getNextNodeData());
    }
}

void Game::updateAnimations(){
    while(deadEnemies.hasNext()){
        deadEnemies.getNextNodeData().updateAnimation();
    }
    while(enemies.hasNext()){
        enemies.getNextNodeData().updateAnimation();
    }
    background.changeFrame();
}