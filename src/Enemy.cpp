#include "Enemy.hpp"
#include <iostream>

bool Enemy::_directionOffset = true;
float Enemy::_offset = 0.f;
float Enemy::_margin = 20.f;

Enemy::Enemy(sf::Vector2f position): Entity(){
    setSpriteDimensions(sf::IntRect(6*16,5*16,16,16));
    setPosition(position);
    _centralPosition = position;
    _health = 1;
    _idle = true;
    _aniTotal = 2;
    _aniStartIndex = {6, 5};
    _ticksPerFrame = 30;
}

void Enemy::setCentralPosition(sf::Vector2f centralPosition){
    _centralPosition = centralPosition;
}

sf::Vector2f Enemy::getCentralPosition(){
    return _centralPosition;
}

void Enemy::setIdle(bool idle){
    _idle = idle;
}

bool Enemy::getIdle(){
    return _idle;
}

void Enemy::stepOffset(){
    if(_directionOffset){
        _offset += 1.f;
        if(_offset >= _margin){
            _directionOffset = false;
            _offset = _margin;
        }
    } else{
        _offset -= 1.f;
        if(_offset <= -_margin){
            _directionOffset = true;
            _offset = -_margin;
        }
    }
}

void Enemy::resetOffset(){
    _offset = 0.f;
}

float Enemy::getOffset(){
    return _offset;
}

void Enemy::moveEntity(){
    if(_idle){
        sf::Vector2f tmpPosition = getPosition();
        tmpPosition.x = _centralPosition.x + _offset;
        setPosition(tmpPosition);
    }
}

bool Enemy::operator==(Enemy &enemy){
    if(getPosition() == enemy.getPosition()) return true;
    return false;
}