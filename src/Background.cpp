#include "Background.hpp"

Background::Background(): _aniCtr(0), _aniSpeedCounter(0), _backgroundState(false), _pixelSpeed(2), _ticksPerFrame(2) {
    setTextureRect({0, 288, gm::Background::WIDTH, gm::Background::HEIGHT});
    setScale({gm::Window::SCALE, gm::Window::SCALE});
    setPosition({0, 0});
}

void Background::changeFrame(){
    if(_aniSpeedCounter < _ticksPerFrame){
        _aniSpeedCounter += 1;
        return;
    } else{
        _aniSpeedCounter = 0;
    }
    sf::IntRect backgroundCopy = getTextureRect();

    if(_aniCtr > 5){
        _aniCtr = 0;
        if(_backgroundState == false){
            backgroundCopy.top += 576;
            _backgroundState = true;
        } else if(_backgroundState == true){
            backgroundCopy.top -= 576;
            _backgroundState = false;
        }
    }
    if(_backgroundState == false){
        if(backgroundCopy.top - _pixelSpeed < 0) backgroundCopy.top += 288;
        backgroundCopy.top -= _pixelSpeed;
    } else{
        if(backgroundCopy.top - _pixelSpeed < 576) backgroundCopy.top += 288;
        backgroundCopy.top -= _pixelSpeed;
    }
    _aniCtr += 1;
    setTextureRect(backgroundCopy);
}

void Background::setPixelSpeed(int pixelSpeed){
    _pixelSpeed = pixelSpeed;
}