#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "GameConstants.hpp"

class DeadEntity : public Entity {
    public:
        DeadEntity(sf::Vector2f position,sf::IntRect startIndex, int ticksPerFrame, int aniTotal);
        void moveEntity() override;
        void reduceDeathCounter();
        void subtractToDeathCounter(int subtract);
        int getDeathCounter();
        bool operator == (DeadEntity &deadEntity);
    private:
        int _deathCounter;
};