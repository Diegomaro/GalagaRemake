#include "Game.hpp"
#include <iostream>
#include <cmath>

using namespace GameConstants;

Game::Game(): window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game"), elapsedTime(sf::Time::Zero), offset(0) {}

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
    deadEnemy.move({- 8 * SCALE, - 8 * SCALE});
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
    while(elapsedTime >= TIMESTEP){
        elapsedTime -= TIMESTEP;
        updateLogic();
        render();
        updateAnimations();
    }
}

void Game::inputHandler(){
    sf::Vector2f v = {0, 0};
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        v.x += -PLAYER_SPEED;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        v.x += PLAYER_SPEED;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        if(player.shootCooldown == 0){
            player.shootCooldown += SHOOT_COOLDOWN;
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
    movePlayer();
    moveBullets();
    moveEnemies();
    decreaseDeadEnemyCounter();
    collisionHandler();
}

void Game::movePlayer(){
    int playerOutOfBondsPos = player.getPosition().x + player.getHitbox().width + player.getVelocity().x;
    int playerOutOfBondsNeg = player.getPosition().x + player.getVelocity().x;
    if(playerOutOfBondsPos <= WINDOW_WIDTH && player.getVelocity().x > 0){
        player.move(player.getVelocity());
    } else if(playerOutOfBondsNeg > 0 && player.getVelocity().x < 0){
        player.move(player.getVelocity());
    }
}

void Game::moveBullets(){
    while(player.bullets.hasNext()){
        Bullet *bullet = &player.bullets.getNextNodeData();
        bullet->move(bullet->getVelocity());
    }
}

void Game::moveEnemies(){
    Enemy *enemy = nullptr;
    enemy->stepOffset();
    while(enemies.hasNext()){
        Enemy *enemy = &enemies.getNextNodeData();
        enemy->moveEntity();
    }
}

void Game::decreaseDeadEnemyCounter(){
    while(deadEnemies.hasNext()){
        DeadEnemy *deadEnemy = &deadEnemies.getNextNodeData();
        deadEnemy->subtractToDeadCounter(1);
        if(deadEnemy->getDeadCounter() <= 0){
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
            sf::FloatRect bulletHitbox = bullet->getHitbox();
            sf::FloatRect enemyHitbox = enemy->getHitbox();
            if(collisionChecker(bulletHitbox, enemyHitbox)){
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

bool Game::collisionChecker(sf::FloatRect hitbox1, sf::FloatRect hitbox2){
    float hitbox1LowY = hitbox1.top;
    float hitbox1HighY = hitbox1.top + hitbox1.height;
    float hitbox2LowY = hitbox2.top;
    float hitboxwHighY = hitbox2.top + hitbox2.height;
    if(hitbox1LowY <= hitboxwHighY && hitbox1HighY >= hitbox2LowY){
        float hitbox1LowX = hitbox1.left;
        float hitbox1HighX = hitbox1.left + hitbox1.width;
        float hitbox2LowX = hitbox2.left;
        float hitboxwHighX = hitbox2.left + hitbox2.width;
        if(hitbox1LowX <= hitboxwHighX && hitbox1HighX >= hitbox2LowX){
            return true;
        }
    }
    return false;
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