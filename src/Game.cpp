#include "Game.hpp"
#include <iostream>
#include <cmath>

using namespace GameConstants;

Game::Game(): window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game") {}

void Game::start(){
    tmp_ctr = 0;
    tmp_ctr2 = 0;
    loadSprites();
    createPlayer();
    createEnemy();
    window.setVisible(true);
    while(window.isOpen()) loop();
}

void Game::loadSprites(){
    rm.loadTexture("sprites", "media/galaga_sprites.png");
}

void Game::createPlayer(){
    player.setTexture(rm.getTexture("sprites"));
}

void Game::createEnemy(){
    enemy.setTexture(rm.getTexture("sprites"));
}

void Game::loop(){
    inputHandler();
    eventHandler();
    elapsedTime += clock.restart();
    while(elapsedTime >= TIMESTEP){
        elapsedTime -= TIMESTEP;
        updateLogic();
        if(player.shootCooldown > 0) player.shootCooldown -= 1;
        render();
    }
    /* render could go here, but given this is a simple game it doesnt need that
    FPS without constantly rendering > 1000
    FPS with constantly rendering < 600
    */
    }

void Game::updateLogic(){
    movePlayer();
    moveBullets();
    collisionHandler();
    // kill entities
}

void Game::collisionHandler(){
    //player
    // enemy bullets
    while(player.bullets.hasNext()){
        Bullet *bullet = &player.bullets.getNextNodeData();
        sf::FloatRect bulletHitbox = bullet->getHitbox();
        sf::FloatRect enemyHitbox = enemy.getHitbox();
        float bulletLowY = bulletHitbox.top;
        float bulletHighY = bulletHitbox.top + bulletHitbox.height;
        float enemyLowY = enemyHitbox.top;
        float enemyHighY = enemyHitbox.top + enemyHitbox.height;
        if(bulletLowY <= enemyHighY && bulletHighY >= enemyLowY){
            float bulletLowX = bulletHitbox.left;
            float bulletHighX = bulletHitbox.left + bulletHitbox.width;
            float enemyLowX = enemyHitbox.left;
            float enemyHighX = enemyHitbox.left + enemyHitbox.width;
            if(bulletLowX <= enemyHighX && bulletHighX >= enemyLowX){
                std::cout << "collision detected!" << std::endl;
                //collision effect
            }            
        }
    }
}

void Game::movePlayer(){
    int playerOutOfBondsPos = player.getPosition().x + player.getHitbox().width + player.getVelocity().x;
    int playerOutOfBondsNeg = player.getPosition().x + player.getVelocity().x;
    if(playerOutOfBondsPos <= WINDOW_WIDTH && player.getVelocity().x > 0){
        player.setPosition(player.getPosition() + player.getVelocity());
    } else if(playerOutOfBondsNeg > 0 && player.getVelocity().x < 0){
        player.setPosition(player.getPosition() + player.getVelocity());
    }
}

void Game::moveBullets(){
    while(player.bullets.hasNext()){
        player.bullets.addVelToNode({0,-BULLET_SPEED});
    }
}

//only once per event, some events cycle
void Game::eventHandler(){
    sf::Event event;
    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window.close();
        }
   }
}

//constatly checks, doesnt get cleaned, more consistent
void Game::inputHandler(){
    sf::Vector2f v = {0, 0};
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        v.x += -PLAYER_SPEED;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        v.x += PLAYER_SPEED;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        if(player.shootCooldown == 0){
            player.shootCooldown += 15;
            player.ShootBullet(rm.getTexture("sprites"));
        }
    }
    player.setVelocity(v);
}

void Game::render(){
    window.clear();
    window.draw(enemy);
    window.draw(player);
    renderBullets();
    window.display();
}

void Game::renderBullets(){
    while(player.bullets.hasNext()){
        window.draw(player.bullets.getNextNodeData());
    }
}