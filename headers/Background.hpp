#pragma once
#include <SFML/Graphics.hpp>

class Background : public sf::Sprite{
    public:
        Background();
        void changeFrame();
        void setPixelSpeed(int pixelSpeed);
    private:
        int _pixelSpeed;
        int _aniCounter;
        int _aniSpeed;
        int _aniSpeedCounter;
        bool _backgroundState;
};