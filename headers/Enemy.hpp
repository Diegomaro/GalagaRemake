#pragma once
#include "Entity.hpp"

class Enemy: public Entity{
    public:
        Enemy(sf::Vector2f position);
        bool operator == (Enemy &enemy);

};