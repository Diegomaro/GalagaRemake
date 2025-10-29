#include "Entity.hpp"

Entity::Entity(): _sprite_dimensions(0, 0, 16, 16),
                _hitbox(0, 0, 16*3, 16*3),
                _velocity(0.f, 0.f),
                _health(0),
                _aniStartIndex(0, 0),
                _ticksPerFrame(5),
                _aniTickCtr(0),
                _aniTotal(1),
                _aniCtr(0){
    setTextureRect(_sprite_dimensions);
    setScale({gm::Window::SCALE, gm::Window::SCALE});
}

void Entity::setSpriteDimensions(sf::IntRect spriteDimensions){
    _sprite_dimensions = spriteDimensions;
    setTextureRect(_sprite_dimensions);
}

sf::IntRect Entity::getSpriteDimensions(){
    return _sprite_dimensions;
}

sf::FloatRect Entity::getHitbox(){
    _hitbox.left = getPosition().x;
    _hitbox.top = getPosition().y;
    return _hitbox;
}

void Entity::setVelocity(sf::Vector2f velocity){
    _velocity = velocity;
}
sf::Vector2f Entity::getVelocity(){
    return _velocity;
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

void Entity::setAniStartIndex(sf::Vector2i aniStartIndex){
    _aniStartIndex = aniStartIndex;
}

sf::Vector2i Entity::getAniStartIndex(){
    return _aniStartIndex;
}

void Entity::setTickPerFrame(int ticksPerFrame){
    _ticksPerFrame = ticksPerFrame;
}

int Entity::getTicksPerFrame(){
    return _ticksPerFrame;
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

void Entity::setAniTotal(int aniTotal){
    _aniTotal = aniTotal;
}

int Entity::getAniTotal(){
    return _aniTotal;
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

bool Entity::collisionCheck(Entity *entity2){
    sf::FloatRect hitbox1 = getHitbox();
    sf::FloatRect hitbox2 = entity2->getHitbox();
    float hitbox1LowY = hitbox1.top;
    float hitbox1HighY = hitbox1.top + hitbox1.height;
    float hitbox2LowY = hitbox2.top;
    float hitboxwHighY = hitbox2.top + hitbox2.height;
    if(hitbox1LowY <= hitboxwHighY && hitbox1HighY >= hitbox2LowY){
        float hitbox1LowX = hitbox1.left;
        float hitbox1HighX = hitbox1.left + hitbox1.width;
        float hitbox2LowX = hitbox2.left;
        float hitboxwHighX = hitbox2.left + hitbox2.width;
        if(hitbox1LowX <= hitboxwHighX && hitbox1HighX >= hitbox2LowX){
            return true;
        }
    }
    return false;
}