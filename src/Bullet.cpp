#include "Bullet.hpp"

Bullet::Bullet(sf::Vector2f entityPosition, sf::Vector2f velocity): Entity() {
    setSpriteDimensions(sf::IntRect(17*16,7*16,16,16));
    if(velocity.y > 0) {
        setPosition({entityPosition.x, entityPosition.y + 8 * 3});
    } else {
        setPosition({entityPosition.x, entityPosition.y - 8 * 3});
    }
    setVelocity(velocity);
    _hitbox.width = 3;
    _hitbox.height = 9;
    _health = 1;
}

void Bullet::moveEntity(){
    move(_velocity);
}

sf::FloatRect Bullet::getHitbox(){
    _hitbox.left = getPosition().x + 7 * gm::Window::SCALE;
    _hitbox.top = getPosition().y + 5 * gm::Window::SCALE;
    return _hitbox;
}

bool Bullet::operator==(Bullet &bullet){
    if(getPosition() == bullet.getPosition()) return true;
    return false;
}