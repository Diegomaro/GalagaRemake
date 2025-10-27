#pragma once
#include <SFML/Graphics.hpp>

class Background : public sf::Sprite{
    public:
        Background();
        void changeFrame();
        void setPixelSpeed(int pixelSpeed);
    private:
        int _pixelSpeed;
        int _aniCtr;
        int _ticksPerFrame;
        int _aniSpeedCounter;
        bool _backgroundState;
};