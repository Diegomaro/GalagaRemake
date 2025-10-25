#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"
#include "Player.hpp"
#include "InsectEnemy.hpp"

class Game{
    public:
        Game();
        void start();
        void loop();
        void updateLogic();
        void eventHandler();
        void handleInput();
        void render();
    private:
        void loadSprites();
        void createPlayer();
        void createEnemy();
        void checkPlayerCollisionWithWalls();
        void moveBullets();
        void renderBullets();
        sf::RenderWindow window;
        sf::Time elapsedTime;
        sf::Clock clock;
        int ctr;
        Player player;
        InsectEnemy enemy;

        ResourceManager rm;
        const sf::Time timestep = sf::milliseconds(16.6667f);
        const float SCALE = 3;
        const int animationTick = 5;
};