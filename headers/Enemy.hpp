#pragma once
#include "Entity.hpp"
#include "Bullet.hpp"
#include "DoubleLinkedList.hpp"

class Enemy: public Entity{
    public:
        Enemy(sf::Vector2f position, int type);
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
        bool _canShoot;
        sf::Vector2f _centralPosition;
        int _shootCooldown;

        static int _moveCtr;
        static int _moveTotal;
        static DoubleLinkedList<Bullet> bullets;
        static bool _directionOffset;
        static float _offset;
        static float _margin;
};