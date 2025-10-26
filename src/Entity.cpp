#include "Entity.hpp"

void Entity::setVelocity(sf::Vector2f velocity){
    _velocity = velocity;
}
sf::Vector2f Entity::getVelocity(){
    return _velocity;
}

sf::FloatRect Entity::getHitbox(){
    _hitbox.left = getPosition().x;
    _hitbox.top = getPosition().y;
    return _hitbox;
}

void Entity::setHealt(int health){
    _health = health;
}

void Entity::modifyHealth(int health){
    _health += health;
}

int Entity::getHealth(){
    return _health;
}

void Entity::setSprite(int xPos, int yPos){
    _sprite_dimensions.top = yPos*16;
    _sprite_dimensions.left = xPos*16;
    setTextureRect(_sprite_dimensions);
}

void Entity::setSpriteDimensions(sf::IntRect spriteDimensions){
    _sprite_dimensions = spriteDimensions;
}

sf::IntRect Entity::getSpriteDimensions(){
    return _sprite_dimensions;
}