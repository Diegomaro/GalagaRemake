#pragma once
#include "Entity.hpp"
#include "Bullet.hpp"
#include "DoubleLinkedList.hpp"

class Enemy: public Entity{
    public:
        Enemy(sf::Vector2f position);
        void setCentralPosition(sf::Vector2f centraPosition);
        sf::Vector2f getCentralPosition();
        void resetShootCooldown();
        void stepShootCooldown();
        int getShootCooldown();
        void setIdle(bool idle);
        bool getIdle();
        void setCanShoot(bool canShoot);
        bool getCanShoot();
        bool hasNextBullet();
        Bullet &getNextBullet();
        void deleteBullet(Bullet bullet);

        void moveEntity() override;
        void shoot(sf::Texture &texture);

        bool operator == (Enemy &enemy);

        static void stepOffset();
        static void resetOffset();
        static float getOffset();
    private:
        bool _idle;
        bool _canShoot;
        DoubleLinkedList<Bullet> bullets;
        sf::Vector2f _centralPosition;
        int _shootCooldown;

        static bool _directionOffset;
        static float _offset;
        static float _margin;
};