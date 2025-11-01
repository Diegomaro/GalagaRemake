#pragma once
#include <SFML/Graphics.hpp>
#include "GameConstants.hpp"

class Background : public sf::Sprite{
    public:
        Background();
        void changeFrame();
        void setPixelSpeed(int pixelSpeed);
    private:
        bool _backgroundState;
        int _pixelSpeed;
        int _aniCtr;
        int _aniSpeedCounter;
        int _ticksPerFrame;
};