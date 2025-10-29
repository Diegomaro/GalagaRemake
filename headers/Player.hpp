#pragma once
#include "Entity.hpp"
#include "DoubleLinkedList.hpp"
#include "Bullet.hpp"
#include "GameConstants.hpp"

class Player : public Entity {
    public:
        Player();
        void resetShootCooldown();
        void stepShootCooldown();
        int getShootCooldown();
        bool hasNextBullet();
        Bullet &getNextBullet();
        void deleteBullet(Bullet bullet);

        void moveEntity() override;
        void shoot(sf::Texture &texture);
    private:
        int _shootCooldown;
        DoubleLinkedList<Bullet> bullets;
};