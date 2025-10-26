#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Background.hpp"
#include "GameConstants.hpp"
#include "DoubleLinkedList.hpp"

class Game{
    public:
        Game();
        void start();
        void loop();
        void updateLogic();
        void eventHandler();
        void inputHandler();
        void render();
    private:
        void loadSprites();
        void createPlayer();
        void createEnemy(sf::Vector2f enemyPosition);
        void createBackgrounds();

        void collisionHandler();
        void movePlayer();
        void moveBullets();
        void renderBullets();
        void renderEnemies();
        void renderBackgrounds();
    private:
        sf::RenderWindow window;
        sf::Time elapsedTime;
        sf::Clock clock;
        ResourceManager rm;
        Player player;
        Background background1;
        Background background2;
        DoubleLinkedList<Enemy> enemies;
};