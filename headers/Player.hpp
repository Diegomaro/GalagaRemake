#pragma once
#include "Entity.hpp"
#include "DoubleLinkedList.hpp"
#include "Bullet.hpp"
#include "GameConstants.hpp"

class Player : public Entity {
    public:
        Player();
        void reactivate();
        void deactivate();
        void setCanMove(bool canMove);
        bool getCanMove();
        void setIsAlive(bool isAlive);
        bool getIsAlive();
        void resetShootCooldown();
        void stepShootCooldown();
        int getShootCooldown();
        void resetRespawnCooldown();
        void stepRespawnCooldown();
        int getRespawnCooldown();
        bool hasNextBullet();
        Bullet &getNextBullet();
        void deleteBullet(Bullet *bullet);
        void clearBullets();

        void moveEntity() override;
        void shoot(sf::Texture &texture, sf::Vector2f velocity);
    private:
        bool _canMove;
        bool _isAlive;;
        bool _hidden;
        int _shootCooldown;
        int _respawnCooldown;
        DoubleLinkedList<Bullet> bullets;
};