#include "Bullet.hpp"

Bullet::Bullet(sf::Vector2f playerPosition){
    _sprite_dimensions = sf::IntRect(17*16,7*16,16,16);
    hitbox.width = 1*3;
    hitbox.height = 3*3;
    setTextureRect(_sprite_dimensions);
    setScale({3,3});
    setPosition({playerPosition.x, playerPosition.y - 8 * 3});
    setVelocity({0,0});
}

sf::FloatRect Bullet::getHitbox(){
    hitbox.left = getPosition().x + 7*3;
    hitbox.top = getPosition().y + 5*3;
    return hitbox;
}