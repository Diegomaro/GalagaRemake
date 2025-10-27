#include "Entity.hpp"

Entity::Entity(): _sprite_dimensions(0, 0, 16, 16),
                _hitbox(0, 0, 16*3, 16*3),
                _velocity(0.f, 0.f),
                _ticksPerFrame(5),
                _aniStartIndex(0, 0),
                _aniCtr(0),
                _aniTotal(1),
                _aniTickCtr(0),
                _health(0){
    setTextureRect(_sprite_dimensions);
    setScale({3.f, 3.f});
}

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

void Entity::setTickPerFrame(int ticksPerFrame){
    _ticksPerFrame = ticksPerFrame;
}

int Entity::getTicksPerFrame(){
    return _ticksPerFrame;
}

void Entity::stepAniCtr(){
    _aniCtr += 1;
}

void Entity::resetAniCtr(){
    _aniCtr = 0;
}

int Entity::getAniCtr(){
    return _aniCtr;
}

int Entity::getAniTotal(){
    return _aniTotal;
}

void Entity::stepAniTickCtr(){
    _aniTickCtr += 1;
}

void Entity::resetAniTickCtr(){
    _aniTickCtr = 0;
}

int Entity::getAniTickCtr(){
    return _aniTickCtr;
}

void Entity::setAniStartIndex(sf::Vector2i aniStartIndex){
    _aniStartIndex = aniStartIndex;
}

sf::Vector2i Entity::getAniStartIndex(){
    return _aniStartIndex;
}

void Entity::updateAnimation(){
    if(getAniTickCtr() < getTicksPerFrame()){
        stepAniTickCtr();
    } else{
        resetAniTickCtr();
        stepAniCtr();
        if(getAniCtr() >= getAniTotal()){
            resetAniCtr();
        }
        sf::IntRect entityRect = getTextureRect();
        entityRect.left = ((getAniStartIndex().x)*16 + (getAniCtr()*entityRect.width));
        setTextureRect(entityRect);
    }
}

void Entity::setSprite(int xPos, int yPos){
    _sprite_dimensions.top = yPos * 16;
    _sprite_dimensions.left = xPos * 16;
    setTextureRect(_sprite_dimensions);
}

void Entity::setSpriteDimensions(sf::IntRect spriteDimensions){
    _sprite_dimensions = spriteDimensions;
    setTextureRect(_sprite_dimensions);
}

sf::IntRect Entity::getSpriteDimensions(){
    return _sprite_dimensions;
}