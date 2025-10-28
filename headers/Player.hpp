#pragma once
#include "Entity.hpp"
#include "DoubleLinkedList.hpp"
#include "Bullet.hpp"
#include "GameConstants.hpp"

class Player : public Entity {
    public:
        Player();
        void moveEntity() override;
        void ShootBullet(sf::Texture &texture);
        DoubleLinkedList<Bullet> bullets;
        int shootCooldown;
    private:
};