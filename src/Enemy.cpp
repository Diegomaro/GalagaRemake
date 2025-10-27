#include "Enemy.hpp"

Enemy::Enemy(sf::Vector2f position): Entity(){
    setSpriteDimensions(sf::IntRect(6*16,5*16,16,16));
    setPosition(position);

    _health = 1;
    _aniTotal = 2;
    _aniStartIndex = {6, 5};
    _ticksPerFrame = 30;

}

void Enemy::update(){}

bool Enemy::operator==(Enemy &enemy){
    if(getPosition() == enemy.getPosition()) return true;
    return false;
}