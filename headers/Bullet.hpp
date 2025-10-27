#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Bullet : public Entity{
    public:
        Bullet(sf::Vector2f playerPosition, sf::Vector2f velocity);
        void moveEntity() override;
        sf::FloatRect getHitbox() override;
        bool operator == (Bullet &bullet);
};