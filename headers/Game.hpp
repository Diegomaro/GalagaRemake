#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "DeadEntity.hpp"
#include "Background.hpp"
#include "GameConstants.hpp"
#include "DoubleLinkedList.hpp"
#include "StageManager.hpp"

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
        bool createNextEnemy();
        bool createNextRow();
        void createDeadPlayer(sf::Vector2f position);
        void createDeadEnemy(sf::Vector2f position);
        void createBackground();
        void createStage();

        void moveEntities();

        void updatePlayer();
        void updateEnemyCreation();
        void updateShootColdown();
        void updateEnemiesShoot();
        void updateDeadEntities();
        void collisionHandler();

        void renderEntities();
        void updateAnimations();
    private:
        sf::RenderWindow window;
        sf::Clock clock;
        sf::Time elapsedTime;

        ResourceManager rm;
        int points;

        Player player;
        DoubleLinkedList<Enemy> enemies;
        DoubleLinkedList<DeadEntity> deadEntities;
        StageManager stageManager;
        Stage *stage;
        Wave *wave;
        Row *row;

        Background background;
};