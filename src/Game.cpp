#include "Game.hpp"
#include <iostream>
#include <cmath>

Game::Game(): window(sf::VideoMode(224*3, 288*3), "Game"), ctr(0) {}

void Game::start(){
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
    eventHandler();
    handleInput();
    elapsedTime += clock.restart();
    while(elapsedTime >= timestep){
        ctr++;
        elapsedTime -= timestep;
        updateLogic();
    }
    render();
}

void Game::updateLogic(){
    checkPlayerCollisionWithWalls();
    moveBullets();
}

void Game::checkPlayerCollisionWithWalls(){
    int playerOutOfBondsPos = player.getPosition().x + player.getScale().x*player.getLocalBounds().width + player.getVelocity().x;
    int playerOutOfBondsNeg = player.getPosition().x + player.getVelocity().x;
    
    if(playerOutOfBondsPos < (224+2)*3 && player.getVelocity().x > 0){
        player.setPosition(player.getPosition() + player.getVelocity());
    } else if(playerOutOfBondsNeg > 0 && player.getVelocity().x < 0){
        player.setPosition(player.getPosition() + player.getVelocity());
    }
}

void Game::moveBullets(){
    while(player.bullets.hasNext()){
        player.bullets.addVelToNode({0,-5});
    }
}


//only once per event
void Game::eventHandler(){
    sf::Event event;
    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window.close();
        } 
        else if(event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            player.ShootBullet(rm.getTexture("sprites"));
        }
    }
}

//constatly checks, doesnt get cleaned, more consistent
void Game::handleInput(){
    sf::Vector2f v = {0, 0};
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) v.x += -5;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) v.x += 5;
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