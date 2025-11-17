#pragma once
#include "Entity.hpp"
#include "Bullet.hpp"
#include "DoubleLinkedList.hpp"

class Enemy: public Entity{
    public:
        Enemy(sf::Vector2f finalPosition, int type, const sf::Vector2f patternPositions[], const int durationTicks[], const int patternState[], const int totalPositions);
        void setEnemySprite();
        void setType(int type);
        int getType();
        void setCentralPosition(sf::Vector2f centraPosition);
        sf::Vector2f getCentralPosition();
        void resetShootCooldown();
        void stepShootCooldown();
        int getShootCooldown();
        void setIdle(bool idle);
        bool getIdle();
        void setCanShoot(bool canShoot);
        bool getCanShoot();

        static void setTotalSpawn(int spawnTotal);
        static void resetSpawnCounter();
        static bool canSpawn();
        static void stepSpawnCounter();
        static void resetSpawnCooldown();
        static void stepSpawnCooldown();

        static void resetNextBullet();
        static bool hasNextBullet();
        static Bullet &getNextBullet();
        static void deleteBullet(Bullet *bullet);

        static void stepMoveCtr();
        static bool canMoveInPosition();

        void moveEntity() override;
        void shoot(sf::Texture &texture, sf::Vector2f velocity);

        bool operator == (Enemy &enemy);

        static void stepOffset();
        static void resetOffset();
        static float getOffset();
    private:
        int _type;
        bool _idle;
        bool _returningIdle;
        bool _movingPattern;


        bool _canShoot;
        int _shootCooldown;
        static DoubleLinkedList<Bullet> bullets;

        sf::Vector2f _centralPosition;

        static int _spawnCtr;
        static int _spawnTotal;
        static int _spawnCooldown;

        static int _moveCtr;
        static int _moveTotal;

        static bool _directionOffset;
        static float _offset;
        static float _margin;

        sf::Vector2f _patternPositions[100];
        int _durationTicks[100];
        int _patternState[100];
        int _ctrPattern;

        sf::Vector2f _curVelocity;
        sf::Vector2f *_velocities;

        int _trajectoryDurationCtr;
        int _trajectoryDurationTotal;

        void setPositionsROM(const sf::Vector2f patternPositions[], int count);
        void setDurationROM(const int durationTicks[], int count);
        void setStateROM(const int patternState[], int count);
};