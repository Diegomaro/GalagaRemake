#include "Bullet.hpp"

Bullet::Bullet(sf::Vector2f playerPosition, sf::Vector2f velocity): Entity() {
    setSpriteDimensions(sf::IntRect(17*16,7*16,16,16));
    setPosition({playerPosition.x, playerPosition.y - 8 * 3});
    setVelocity(velocity);
    _hitbox.width = 3;
    _hitbox.height = 9;
    _health = 1;
}

void Bullet::update(){}

sf::FloatRect Bullet::getHitbox(){
    _hitbox.left = getPosition().x + 7*3;
    _hitbox.top = getPosition().y + 5*3;
    return _hitbox;
}

bool Bullet::operator==(Bullet &bullet){
    if(getPosition() == bullet.getPosition()) return true;
    return false;
}