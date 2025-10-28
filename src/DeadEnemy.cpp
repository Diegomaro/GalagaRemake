#include "DeadEnemy.hpp"

DeadEnemy::DeadEnemy(sf::Vector2f position): Entity() {
    setSpriteDimensions(sf::IntRect(15*16, 0, 32, 32));
    setPosition(position);
    _health = 0;

    _ticksPerFrame = 4;
    _deathCounter = (_ticksPerFrame * 6) - 1;
    _aniTotal = 5;
    _aniStartIndex = {15, 0};
}

void DeadEnemy::moveEntity(){}

int DeadEnemy::getDeathCounter(){
    return _deathCounter;
}


void DeadEnemy::reduceDeathCounter(){
    _deathCounter -= 1;
}

void DeadEnemy::subtractToDeathCounter(int subtract){
    _deathCounter -= subtract;
}

bool DeadEnemy::operator==(DeadEnemy &deadEnemy){
    if(getPosition() == deadEnemy.getPosition() && getDeathCounter() == deadEnemy.getDeathCounter()) return true;
    return false;
}