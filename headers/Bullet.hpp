#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Bullet : public Entity{
    public:
    Bullet(sf::Vector2f playerPosition, sf::Vector2f velocity);
    sf::FloatRect getHitbox() override;
    void addVelocity(sf::Vector2f velocity);
    bool operator == (Bullet &bullet);
};