#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"

class Game{
    public:
        Game();
        void start();
        void loop();
        void updateLogic();
        void eventHandler();
        void render();
    private:
        void createPlayer();
        void createLantern();
        sf::RenderWindow window;
        sf::Time elapsedTime;
        sf::Clock clock;
        int ctr;

        sf::Sprite player;
        sf::Sprite lantern;

        ResourceManager rm;
        //EntityManager em;
};