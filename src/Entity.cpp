#include "Entity.hpp"

void Entity::setVelocity(sf::Vector2f velocity){
    _velocity = velocity;
}
sf::Vector2f Entity::getVelocity(){
    return _velocity;
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