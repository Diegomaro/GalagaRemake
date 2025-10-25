#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Bullet : public Entity{
    public:
        Bullet(sf::Vector2f playerPosition);
};