#include "Enemy.hpp"
#include <iostream>

bool Enemy::_directionOffset = true;
float Enemy::_offset = 0.f;
float Enemy::_margin = 30.f;
DoubleLinkedList<Bullet> Enemy::bullets;

Enemy::Enemy(sf::Vector2f position, int type): Entity(){
    setPosition(position);
    _type = type;
    setEnemySprite();
    _centralPosition = position;
    _health = 1;
    _idle = true;
    _aniTotal = 2;
    _aniStartIndex = {6, 5};
    _ticksPerFrame = 30;
    _shootCooldown = 0;
    _idle = true;
    _canShoot = true;
}

void Enemy::setEnemySprite(){
    switch(_type){
        case 2:{
            setSpriteDimensions(sf::IntRect(6*16, 3*16, 16, 16));
        }break;
        case 4:{
            setSpriteDimensions(sf::IntRect(6*16, 4*16, 16, 16));
        }break;
        case 5:{
            setSpriteDimensions(sf::IntRect(6*16, 5*16, 16, 16));
        }break;
    }
}

void Enemy::setType(int type){
    _type = type;
}

int Enemy::getType(){
    return _type;
}

void Enemy::resetShootCooldown(){
    _shootCooldown = gm::Enemy::SHOOT_COOLDOWN;
}

void Enemy::stepShootCooldown(){
    if(_shootCooldown <= 0){

        _shootCooldown = 0;
    } else{
        _shootCooldown -= 1;

    }
}

int Enemy::getShootCooldown(){
    return _shootCooldown;
}

void Enemy::setCentralPosition(sf::Vector2f centralPosition){
    _centralPosition = centralPosition;
}

sf::Vector2f Enemy::getCentralPosition(){
    return _centralPosition;
}

void Enemy::setIdle(bool idle){
    _idle = idle;
}

bool Enemy::getIdle(){
    return _idle;
}

void Enemy::setCanShoot(bool canShoot){
    _canShoot = canShoot;
}
bool Enemy::getCanShoot(){
    return _canShoot;
}

void Enemy::stepOffset(){
    if(_directionOffset){
        _offset += 1.f;
        if(_offset >= _margin){
            _directionOffset = false;
            _offset = _margin;
        }
    } else{
        _offset -= 1.f;
        if(_offset <= -_margin){
            _directionOffset = true;
            _offset = -_margin;
        }
    }
}

void Enemy::resetOffset(){
    _offset = 0.f;
}

float Enemy::getOffset(){
    return _offset;
}

bool Enemy::hasNextBullet(){
    return bullets.hasNext();
}

Bullet &Enemy::getNextBullet(){
    return bullets.getNextNodeData();
}

void Enemy::deleteBullet(Bullet *bullet){
    bullets.deleteNode(bullet);
}

void Enemy::moveEntity(){
    if(_idle){
        sf::Vector2f tmpPosition = getPosition();
        tmpPosition.x = _centralPosition.x + _offset;
        setPosition(tmpPosition);
    }
}

void Enemy::shoot(sf::Texture &texture, sf::Vector2f velocity){
    Bullet bullet = Bullet(getPosition(), velocity);
    bullet.setTexture(texture);
    bullets.insertTail(bullet);
}

bool Enemy::operator==(Enemy &enemy){
    if(getPosition() == enemy.getPosition()) return true;
    return false;
}