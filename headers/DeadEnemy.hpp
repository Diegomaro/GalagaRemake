#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "GameConstants.hpp"

class DeadEnemy : public Entity {
    public:
        DeadEnemy(sf::Vector2f position);
        void moveEntity() override;
        void reduceDeathCounter();
        void subtractToDeathCounter(int subtract);
        int getDeathCounter();
        bool operator == (DeadEnemy &deadEnemy);
    private:
        int _deathCounter;
};