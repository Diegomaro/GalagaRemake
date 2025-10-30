#include "DeadEntity.hpp"

DeadEntity::DeadEntity(sf::Vector2f position,sf::IntRect startIndex, int ticksPerFrame, int aniTotal): Entity() {
    setSpriteDimensions(sf::IntRect(startIndex.left*16, startIndex.top*16, startIndex.height, startIndex.height));
    setPosition(position);
    _health = 0;

    _ticksPerFrame = ticksPerFrame;
    _deathCounter = (_ticksPerFrame * aniTotal);
    _aniTotal = aniTotal;
    _aniStartIndex.x = startIndex.left;
    _aniStartIndex.y = startIndex.top;
}

void DeadEntity::moveEntity(){}

int DeadEntity::getDeathCounter(){
    return _deathCounter;
}


void DeadEntity::reduceDeathCounter(){
    _deathCounter -= 1;
}

void DeadEntity::subtractToDeathCounter(int subtract){
    _deathCounter -= subtract;
}

bool DeadEntity::operator==(DeadEntity &deadEntity){
    if(getPosition() == deadEntity.getPosition() && getDeathCounter() == deadEntity.getDeathCounter()) return true;
    return false;
}