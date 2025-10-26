#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
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

        void collisionHandler();
        void movePlayer();
        void moveBullets();
        void renderBullets();
        void renderEnemies();
    private:
        sf::RenderWindow window;
        sf::Time elapsedTime;
        sf::Clock clock;
        Player player;
        DoubleLinkedList<Enemy> enemies;
        ResourceManager rm;
        int tmp_ctr;
        int tmp_ctr2;
};