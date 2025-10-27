#pragma once
#include "Entity.hpp"

class Enemy: public Entity{
    public:
        Enemy(sf::Vector2f position);
        void setCentralPosition(sf::Vector2f centraPosition);
        sf::Vector2f getCentralPosition();
        void setIdle(bool idle); // probably not needed
        bool getIdle();
        void stepOffset();
        void resetOffset();
        float getOffset();
        void moveEntity() override;
        bool operator == (Enemy &enemy);


    private:
        static bool _directionOffset;
        static float _offset;
        static float _margin;
        sf::Vector2f _centralPosition;
        bool _idle;
};