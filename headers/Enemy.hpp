#pragma once
#include "Entity.hpp"

class Enemy: public Entity{
    public:
        Enemy(sf::Vector2f position);
        void update() override;
        bool operator == (Enemy &enemy);

    private:
        sf::IntRect origin();
};