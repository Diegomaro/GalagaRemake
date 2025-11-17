#include "Game.hpp"
#include <iostream>
#include <cmath>

Game::Game():
    window(sf::VideoMode(gm::Window::WIDTH, gm::Window::HEIGHT), "Game"),
    elapsedTime(sf::Time::Zero),
    points(0),
    stage(nullptr),
    wave(nullptr),
    row(nullptr) {}

void Game::start(){
    loadSprites();
    createPlayer();
    createBackground();
    createStage();
    window.setVisible(true);
    Enemy::setTotalSpawn(8);
    while(window.isOpen()){
        loop();
    }
}

void Game::loadSprites(){
    rm.loadTexture("sprites", "media/game_sprites.png");
    rm.loadTexture("background", "media/background.png");
}

void Game::createPlayer(){
    player.setTexture(rm.getTexture("sprites"));
}

bool Game::createNextEnemy(){
    if(row->enemies.hasNext()){
        Enemy *nextEnemy = row->enemies.getNextNodeData();
        nextEnemy->setTexture(rm.getTexture("sprites"));
        enemies.insertTail(*nextEnemy);
    } else{
        if(wave->rows.hasNext()){
            row = wave->rows.getNextNodeData();
            createNextEnemy();
        } else{
            if(stage->waves.hasNext()){
                wave = stage->waves.getNextNodeData();
                createNextEnemy();
            } else{
                return false;
                std::cout << "Finished!" << std::endl;
            }
        }
     }
    return true;
}

bool Game::createNextRow(){
    bool rowCreated = false;
    while(row->enemies.hasNext()){
        rowCreated = true;
        Enemy *nextEnemy = row->enemies.getNextNodeData();
        nextEnemy->setTexture(rm.getTexture("sprites"));
        enemies.insertTail(*nextEnemy);
    }
    if(!rowCreated){
        if(wave->rows.hasNext()){
            row = wave->rows.getNextNodeData();
            createNextRow();
        } else{
            if(stage->waves.hasNext()){
                wave = stage->waves.getNextNodeData();
                createNextRow();
            } else{
                return false;
                std::cout << "Finished!" << std::endl;
            }
        }
    }
    return true;
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

void Game::createStage(){
    stage = stageManager.getCurrentStage();
    if(stage->waves.hasNext()){
        wave = stage->waves.getNextNodeData();
        if(wave->rows.hasNext()){
            row = wave->rows.getNextNodeData();
        }
    }
}

void Game::loop(){
    eventHandler();
    inputHandler();
    elapsedTime += clock.restart();
    while(elapsedTime >= gm::Timestep::FIXED){
        elapsedTime -= gm::Timestep::FIXED;
        updateLogic();
        updateAnimations();
        render();
    }
}

void Game::inputHandler(){
    if(player.getIsAlive()){
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
    updateEnemyCreation();
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
            player.reactivate();
        }
    }
}

void Game::updateEnemyCreation(){
    if(Enemy::canSpawn()){
        createNextEnemy();
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
    deadEntities.resetNext();
}

void Game::updateShootColdown(){
    while(enemies.hasNext()){
        enemies.getNextNodeData().stepShootCooldown();
    }
    enemies.resetNext();
    player.stepShootCooldown();
}

void Game::moveEntities(){
    //player
    player.moveEntity();
    //player bullets
    while(player.hasNextBullet()){
        Bullet * bullet = &player.getNextBullet();
        bullet->moveEntity();
        if(bullet->getPosition().y < gm::Bullet::UP_BORDER){
            player.deleteBullet(bullet);
        }
    }
    player.resetNextBullet();
    //enemies
    Enemy::stepMoveCtr();
    if(Enemy::canMoveInPosition()){
        Enemy::stepOffset();
    }
    while(enemies.hasNext()){
        enemies.getNextNodeData().moveEntity();
    }
    enemies.resetNext();
    //enemy bullets

    while(Enemy::hasNextBullet()){
        Bullet *bullet = &Enemy::getNextBullet();
        bullet->moveEntity();
        if(bullet->getPosition().y > gm::Bullet::DOWN_BORDER){
            Enemy::deleteBullet(bullet);
        }
    }
    Enemy::resetNextBullet();
}

void Game::updateEnemiesShoot(){
    sf::Vector2f playerCenter = { (player.getPosition().x + player.getHitbox().width/2), player.getPosition().y + (player.getHitbox().height/2)};
    while(enemies.hasNext()){
        Enemy* enemy = &enemies.getNextNodeData();
        if(enemy->getShootCooldown() == 0 && enemy->getCanShoot() && player.getIsAlive()){
            enemy->resetShootCooldown();
            int x = gm::randomInt(0,2); //fix this number
            if(x == 0){
                sf::Vector2f enemyCenter = { (enemy->getPosition().x + enemy->getHitbox().width/2), enemy->getPosition().y + (enemy->getHitbox().height/2)};
                sf::Vector2f distance = playerCenter - enemyCenter;
                float fracDis = 0;
                if(distance.y != 0){
                    fracDis = gm::Bullet::SPEED/distance.y;
                }
                if(distance.x != 0){
                    distance.x = distance.x * 0.60; //fix this number
                }
                float xSpeed = fracDis * distance.x;
                enemy->shoot(rm.getTexture("sprites"), {xSpeed, gm::Bullet::SPEED});
            }
        }
    }
    enemies.resetNext();
}

void Game::collisionHandler(){
    //player hits enemy

    // enemy bullets
    while(Enemy::hasNextBullet() && player.getIsAlive()){
        Bullet *bullet = &Enemy::getNextBullet();
        if(player.collisionCheck(bullet)){
            bullet->modifyHealth(-1);
            if(bullet->getHealth() <= 0){
                Enemy::deleteBullet(bullet);
            }
            player.modifyHealth(-1);
            if(player.getHealth() <= 0){
                createDeadPlayer(player.getPosition());
                player.deactivate();
                std::cout << "finished game!" << std::endl;
            } else{
                std::cout << "player killed!" << std::endl;
                //addPoints();
                createDeadPlayer(player.getPosition());
                player.deactivate();
            }
        }
    }
    Enemy::resetNextBullet();
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
        player.resetNextBullet();
    }
    enemies.resetNext();
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
    player.resetNextBullet();

    while(enemies.hasNext()){
        window.draw(enemies.getNextNodeData());
    }
    enemies.resetNext();

    while(Enemy::hasNextBullet()){
        window.draw(Enemy::getNextBullet());
    }
    Enemy::resetNextBullet();

    while(deadEntities.hasNext()){
        window.draw(deadEntities.getNextNodeData());
    }
    deadEntities.resetNext();

    if(!player.getHidden()){
        window.draw(player);
    }
}

void Game::updateAnimations(){
    while(deadEntities.hasNext()){
        deadEntities.getNextNodeData().updateAnimation();
    }
    deadEntities.resetNext();
    while(enemies.hasNext()){
        if(enemies.getNextNodeData().updateAnimation());
    }
    enemies.resetNext();
    background.changeFrame();
}