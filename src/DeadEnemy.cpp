#include "DeadEnemy.hpp"

DeadEnemy::DeadEnemy(sf::Vector2f position): Entity() {
    setSpriteDimensions(sf::IntRect(15*16, 0, 32, 32));
    setPosition(position);
    _health = 0;

    _ticksPerFrame = 4;
    _deadCtr = (_ticksPerFrame * 6) - 1;
    _aniTotal = 5;
    _aniStartIndex = {15, 0};
}

void DeadEnemy::moveEntity(){}

int DeadEnemy::getDeadCounter(){
    return _deadCtr;
}

void DeadEnemy::subtractToDeadCounter(int subtract){
    _deadCtr -= subtract;
}

bool DeadEnemy::operator==(DeadEnemy &deadEnemy){
    if(getPosition() == deadEnemy.getPosition() && getDeadCounter() == deadEnemy.getDeadCounter()) return true;
    return false;
}