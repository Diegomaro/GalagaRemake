#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "DeadEnemy.hpp"
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
        void createEnemy(sf::Vector2f position);
        void createDeadEnemy(sf::Vector2f position);
        void createBackground();

        void moveEntities();

        void updateShootColdown();
        void updateEnemiesShoot();
        void updateDeadEnemies();
        void collisionHandler();

        void updateAnimations();
        void renderEntities();
    private:
        sf::RenderWindow window;
        sf::Time elapsedTime;
        sf::Clock clock;

        int offset;

        ResourceManager rm;

        Player player;
        Background background;
        DoubleLinkedList<Enemy> enemies;
        DoubleLinkedList<DeadEnemy> deadEnemies;
};