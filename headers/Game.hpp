#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"
#include "Player.hpp"
#include "InsectEnemy.hpp"
#include "GameConstants.hpp"
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
    private:
        sf::RenderWindow window;
        sf::Time elapsedTime;
        sf::Clock clock;
        Player player;
        InsectEnemy enemy;
        ResourceManager rm;
        int tmp_ctr;
        int tmp_ctr2;
};