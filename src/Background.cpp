#include "Background.hpp"

Background::Background(): _aniCounter(0), _aniSpeedCounter(0), _backgroundState(false), _pixelSpeed(1), _aniSpeed(1) {
    setTextureRect({0, 288, 224, 288});
    setScale({3, 3});
    setPosition({0, 0});

}

void Background::changeFrame(){
    if(_aniSpeedCounter > _aniSpeed){
        _aniSpeedCounter = 0;
    } else{
        _aniSpeedCounter +=1;
        return;
    }
    sf::IntRect backgroundCopy = getTextureRect();

    if(_aniCounter > 10){
        _aniCounter = 0;
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
    _aniCounter += 1;
    setTextureRect(backgroundCopy);
}

void Background::setPixelSpeed(int pixelSpeed){
    _pixelSpeed = pixelSpeed;
}