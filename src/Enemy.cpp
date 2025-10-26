#include "Enemy.hpp"

Enemy::Enemy(sf::Vector2f position){
    _sprite_dimensions = sf::IntRect(0*16,5*16,16,16);
    setTextureRect(_sprite_dimensions);
    setScale({3, 3});
    setPosition(position);
    _hitbox.width = 16*3;
    _hitbox.height = 16*3;
    _health = 1;
}

bool Enemy::operator==(Enemy &enemy){
    if(getPosition() == enemy.getPosition()) return true;
    return false;
}