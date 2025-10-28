#include "Game.hpp"
#include <iostream>
#include <cmath>


Game::Game(): window(sf::VideoMode(Consts::Window::WIDTH, Consts::Window::HEIGHT), "Game"), elapsedTime(sf::Time::Zero), offset(0) {}

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
    deadEnemy.move({- 8 * Consts::Window::SCALE, - 8 * Consts::Window::SCALE});
    deadEnemy.setTexture(rm.getTexture("sprites"));
    deadEnemies.insertTail(deadEnemy);
}

void Game::createBackground(){
    background.setTexture(rm.getTexture("background"));
}


void Game::loop(){
    inputHandler();
    eventHandler();
    elapsedTime += clock.restart();
    while(elapsedTime >= Consts::Timestep::FIXED){
        elapsedTime -= Consts::Timestep::FIXED;
        updateLogic();
        render();
        updateAnimations();
    }
}

void Game::inputHandler(){
    sf::Vector2f v = {0, 0};
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        v.x += -Consts::Player::SPEED;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        v.x += Consts::Player::SPEED;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        if(player.shootCooldown == 0){
            player.shootCooldown += Consts::Player::SHOOT_COOLDOWN;
            player.ShootBullet(rm.getTexture("sprites"));
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
    if(player.shootCooldown > 0) player.shootCooldown -= 1;
    moveEntities();
    updateDeadEnemies();
    collisionHandler();
}

void Game::moveEntities(){
    //player
    player.moveEntity();
    //bullets
    while(player.bullets.hasNext()){
        player.bullets.getNextNodeData().moveEntity();
    }
    //enemies
    Enemy *enemy = nullptr;
    enemy->stepOffset();
    while(enemies.hasNext()){
        enemies.getNextNodeData().moveEntity();
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

    //player bullets
    bool enemyIsAlive = true;
    while(enemies.hasNext()){
        Enemy *enemy = &enemies.getNextNodeData();
        enemyIsAlive = true;
        while(player.bullets.hasNext() && enemyIsAlive){
            Bullet *bullet = &player.bullets.getNextNodeData();
            if(enemy->collisionCheck(bullet)){
                std::cout << "collision detected!" << std::endl;
                    bullet->modifyHealth(-1);
                    if(bullet->getHealth() <= 0){
                        player.bullets.deleteNode(*bullet);
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
    while(player.bullets.hasNext()){
        window.draw(player.bullets.getNextNodeData());
    }
    while(enemies.hasNext()){
        window.draw(enemies.getNextNodeData());
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