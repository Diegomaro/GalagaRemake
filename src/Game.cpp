#include "Game.hpp"
#include <iostream>
#include <cmath>


Game::Game(): window(sf::VideoMode(gm::Window::WIDTH, gm::Window::HEIGHT), "Game"), elapsedTime(sf::Time::Zero), offset(0) {}

Game::~Game(){
    /*window.close();
    deadEntities.clear();
    enemies.clear();
    player.clearBullets();*/
}
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
    DeadEntity deadEntity(position, {15, 0, 32, 32}, 5, 5);
    deadEntity.move({- 8 * gm::Window::SCALE, - 8 * gm::Window::SCALE});
    deadEntity.setTexture(rm.getTexture("sprites"));
    deadEntities.insertTail(deadEntity);
}

void Game::createDeadPlayer(sf::Vector2f position){
    DeadEntity deadEntity(position, {7, 0, 32, 32}, 10, 4);
    deadEntity.move({- 8 * gm::Window::SCALE, - 8 * gm::Window::SCALE});
    deadEntity.setTexture(rm.getTexture("sprites"));
    deadEntities.insertTail(deadEntity);
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
    if(!player.getIsAlive()){
        return;
    }
    sf::Vector2f v = {0, 0};
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        v.x += -gm::Player::SPEED;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        v.x += gm::Player::SPEED;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        if(player.getShootCooldown() == 0){
            player.resetShootCooldown();
            player.shoot(rm.getTexture("sprites"), {0, -gm::Bullet::SPEED});
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
    updatePlayer();
    updateDeadEntities();
    updateShootColdown();
    moveEntities();
    updateEnemiesShoot();
    collisionHandler();
}

void Game::updatePlayer(){
    if(!player.getIsAlive()){
        player.stepRespawnCooldown();
        if(player.getRespawnCooldown() <= 0){
            player.setIsAlive(true);
            player.setPosition({gm::Player::X_POS, gm::Player::Y_POS});
            player.setHidden(false);
        }
    }
}

void Game::updateDeadEntities(){
    while(deadEntities.hasNext()){
        DeadEntity *deadEntity = &deadEntities.getNextNodeData();
        deadEntity->reduceDeathCounter();
        if(deadEntity->getDeathCounter() <= 0){
            deadEntities.deleteNode(deadEntity);
        }
    }
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
            player.deleteBullet(bullet);
        }
    }
    //enemies
    Enemy::stepOffset();
    while(Enemy::hasNextBullet()){
        Bullet *bullet = &Enemy::getNextBullet();
        bullet->moveEntity();
        if(bullet->getPosition().y > gm::Bullet::DOWN_BORDER){
            Enemy::deleteBullet(bullet);
        }
    }
    while(enemies.hasNext()){
        enemies.getNextNodeData().moveEntity();
    }
}

void Game::updateEnemiesShoot(){
    while(enemies.hasNext()){
        Enemy* enemy = &enemies.getNextNodeData();
        if(enemy->getShootCooldown() == 0 && enemy->getCanShoot()){
            enemy->resetShootCooldown();
            int x = gm::randomInt(0,3); //fix this number
            if(x == 0){
                std::cout << "shooting!" << std::endl;
                enemy->shoot(rm.getTexture("sprites"), {0,gm::Bullet::SPEED});
            }
        }
    }
}

void Game::collisionHandler(){
    //player hits enemy

    // enemy bullets
    bool playerIsAlive = true;
    while(Enemy::hasNextBullet() && playerIsAlive){
        Bullet *bullet = &Enemy::getNextBullet();
        if(player.collisionCheck(bullet)){
            bullet->modifyHealth(-1);
            if(bullet->getHealth() <= 0){
                Enemy::deleteBullet(bullet);
            }
            player.modifyHealth(-1);
            if(player.getHealth() <= 0){
                createDeadPlayer(player.getPosition());
                std::cout << "player killed!" << std::endl;
                std::cout << "finished game!" << std::endl;
                playerIsAlive = false;
            } else{
                player.setPosition({500,0});
                player.setCanMove(false);
                createDeadPlayer(player.getPosition());
                player.setHidden(true);
                player.resetRespawnCooldown();
                player.setPosition({50000,0});
                player.setIsAlive(false);
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
                        player.deleteBullet(bullet);
                    }
                    enemy->modifyHealth(-1);
                    if(enemy->getHealth() <= 0){
                        createDeadEnemy(enemy->getPosition());
                        enemies.deleteNode(enemy);
                        enemies.resetNext();
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
    window.display();
}

void Game::renderEntities(){
    while(player.hasNextBullet()){
        window.draw(player.getNextBullet());
    }

    while(enemies.hasNext()){
        window.draw(enemies.getNextNodeData());
    }

    while(Enemy::hasNextBullet()){
        window.draw(Enemy::getNextBullet());
    }

    while(deadEntities.hasNext()){
        window.draw(deadEntities.getNextNodeData());
    }

    if(!player.getHidden()){
        window.draw(player);
    }
}

void Game::updateAnimations(){
    while(deadEntities.hasNext()){
        deadEntities.getNextNodeData().updateAnimation();
    }

    while(enemies.hasNext()){
        enemies.getNextNodeData().updateAnimation();
    }
    background.changeFrame();
}