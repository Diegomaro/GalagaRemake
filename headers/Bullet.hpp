#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Bullet : public Entity{
    public:
    sf::FloatRect getHitbox() override;
    Bullet(sf::Vector2f playerPosition);
    bool operator == (Bullet &bullet);
};