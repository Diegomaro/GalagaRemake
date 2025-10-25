#pragma once
#include "Entity.hpp"
#include "DoubleLinkedList.hpp"
#include "Bullet.hpp"

class Player : public Entity {
    public:
        Player();
        void ShootBullet(sf::Texture &texture);
        DoubleLinkedList<Bullet> bullets;
    private:
};