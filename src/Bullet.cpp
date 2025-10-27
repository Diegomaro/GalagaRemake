#include "Bullet.hpp"

Bullet::Bullet(sf::Vector2f playerPosition, sf::Vector2f velocity){
    _sprite_dimensions = sf::IntRect(17*16,7*16,16,16);
    _hitbox.width = 1*3;
    _hitbox.height = 3*3;
    setTextureRect(_sprite_dimensions);
    setScale({3,3});
    setPosition({playerPosition.x, playerPosition.y - 8 * 3});
    setVelocity(velocity);
    _health = 1;
}

sf::FloatRect Bullet::getHitbox(){
    _hitbox.left = getPosition().x + 7*3;
    _hitbox.top = getPosition().y + 5*3;
    return _hitbox;
}

bool Bullet::operator==(Bullet &bullet){
    if(getPosition() == bullet.getPosition()) return true;
    return false;
}

