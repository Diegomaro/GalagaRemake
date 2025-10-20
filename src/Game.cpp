#include "Game.hpp"
#include <iostream>

Game::Game(): window(sf::VideoMode(800,600), "Game"), ctr(0) {}

void Game::start(){
    createPlayer();
    createLantern();
    window.setVisible(true);
    while(window.isOpen()){
        eventHandler();
        loop();
    }
}

void Game::createPlayer(){
    sf::Texture texture;
    rm.loadTexture("player", "media/batChibi.png");
    player.setTexture(rm.getTexture("player"));
    player.setScale({5,5});
}

void Game::createLantern(){
    sf::Texture texture;
    rm.loadTexture("lantern", "media/lantern.png");
    lantern.setTexture(rm.getTexture("lantern"));
    lantern.setPosition({lantern.getPosition().x + 50, lantern.getPosition().y + 50});
    lantern.setScale({5,5});
}

void Game::loop(){
    elapsedTime += clock.restart();
    render();
    if(elapsedTime >= sf::milliseconds(16.6667)){
    ctr++;
        elapsedTime -= elapsedTime;
        updateLogic();
    }
}

void Game::updateLogic(){
}

void Game::eventHandler(){
    sf::Event event;
    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window.close();
        }
    }
}

void Game::render(){
    window.clear();
    window.draw(player);
    window.draw(lantern);
    window.display();
}