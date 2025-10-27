#include "DeadEnemy.hpp"

DeadEnemy::DeadEnemy(sf::Vector2f position) {
    _sprite_dimensions = sf::IntRect(15*16, 0, 32, 32);
    setTextureRect(_sprite_dimensions);
    setScale({3, 3});
    setPosition(position);
    _deadCtr = GameConstants::DEAD_ENEMY_COUNTER;
    _aniTickCount = 0;
    _aniIndex = 5;
    _aniCount = 0;
    _hitbox.width = 32;
    _hitbox.height = 32;
    _health = 0;
    _aniStartIndex = {15, 0};
}

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