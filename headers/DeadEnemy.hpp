#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "GameConstants.hpp"

class DeadEnemy : public Entity {
    public:
        DeadEnemy(sf::Vector2f position);
        void update() override;
        void subtractToDeadCounter(int subtract);
        int getDeadCounter();
        bool operator == (DeadEnemy &deadEnemy);
    private:
        int _deadCtr;
};