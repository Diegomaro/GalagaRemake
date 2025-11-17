#include "Enemy.hpp"
#include <iostream>
#include <cmath>

bool Enemy::_directionOffset = true;
float Enemy::_offset = 0.f;
float Enemy::_margin = 30.f;

DoubleLinkedList<Bullet> Enemy::bullets;

int Enemy::_moveCtr = 0;
int Enemy::_moveTotal = 5;

int Enemy::_spawnCtr = 0;
int Enemy::_spawnTotal = 0;
int Enemy::_spawnCooldown = 0;;


Enemy::Enemy(sf::Vector2f finalPosition, int type, const sf::Vector2f patternPositions[], const int durationTicks[], const int patternState[], const int totalPositions): Entity(){
    setPosition(patternPositions[0]);
    _type = type;
    setEnemySprite();
    _centralPosition = finalPosition;
    _health = 1;
    _idle = false;
    _returningIdle  = false;
    _movingPattern = true;
    _aniTotal = 2;
    _aniStartIndex = {6, 5};
    _ticksPerFrame = 30;
    _shootCooldown = 0;
    _canShoot = true;
    _trajectoryDurationCtr = 0;
    _trajectoryDurationTotal = 0;
    _ctrPattern = 0;
    _curVelocity = {0,0};
    _velocities = nullptr;
    setPositionsROM(patternPositions, totalPositions);
    setDurationROM(durationTicks, totalPositions);
    setStateROM(patternState, totalPositions);
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
}        static int _spawnCooldown;


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
        _offset += 3.f;
        if(_offset >= _margin){
            _directionOffset = false;
            _offset = _margin;
        }
    } else{
        _offset -= 3.f;
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

void Enemy::setTotalSpawn(int spawnTotal){
    _spawnTotal = spawnTotal;
}

void Enemy::resetSpawnCounter(){
    _spawnCtr = 0;
}

bool Enemy::canSpawn(){
    if(_spawnCooldown < 0){
        stepSpawnCooldown();
        return false;
    } else{
        resetSpawnCooldown();
        if(_spawnCtr < _spawnTotal){
            stepSpawnCounter();
            return true;
        }
        return false;
    }
}

void Enemy::stepSpawnCounter(){
    if(_spawnCtr <= _spawnTotal){
        _spawnCtr += 1;
    }
}

void Enemy::resetSpawnCooldown(){
    _spawnCooldown = 0;
}

void Enemy::stepSpawnCooldown(){
    _spawnCooldown += 1;
}

void Enemy::resetNextBullet(){
    bullets.resetNext();
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

void Enemy::stepMoveCtr(){
    _moveCtr += 1;
}

bool Enemy::canMoveInPosition(){
    if(_moveCtr >= _moveTotal){
        _moveCtr = 0;
        return true;
    }
    return false;
}

void Enemy::moveEntity(){
    if(_idle){
        sf::Vector2f tmpPosition = getPosition();
        tmpPosition.x = _centralPosition.x + _offset;
        setPosition(tmpPosition);
        return;
    } else if(_movingPattern){
        sf::Vector2f tmpPosition = getPosition();
        sf::Vector2f curVelocity = {0,0};
        if(_trajectoryDurationCtr < _trajectoryDurationTotal){
            curVelocity = _velocities[_trajectoryDurationCtr];
            _trajectoryDurationCtr += 1;
        } else{
            tmpPosition = _patternPositions[_ctrPattern];
            _ctrPattern += 1;
            if(_ctrPattern >= 100  || (_ctrPattern > 1 && _durationTicks[_ctrPattern] == 0)){
                _movingPattern = false;
                _idle = false;
                return;
            }
            sf::Vector2f destinationPosition = _patternPositions[_ctrPattern];
            _trajectoryDurationTotal = _durationTicks[_ctrPattern];
            _trajectoryDurationCtr = 0;
            int pattern = _patternState[_ctrPattern];
            sf::Vector2f differentialPosition = destinationPosition - tmpPosition;

            if(_velocities){
                delete _velocities;
                _velocities = nullptr;
            }
            _velocities = new(std::nothrow) sf::Vector2f[_trajectoryDurationTotal];
            /*
            pattern = 0, linear
            pattern = 1 inwards x
            pattern = 2 inwards 45 x
            pattern = 3 outwards y
            pattern = 4 outwards 45 y
            */
            if(pattern == 0){
                sf::Vector2f velocityDiff = {differentialPosition.x / _trajectoryDurationTotal, differentialPosition.y / _trajectoryDurationTotal};
                for(int i = 0; i < _trajectoryDurationTotal; i++){
                    _velocities[i] = velocityDiff;
                }
            } else{
                sf::Vector2f velocityDiff = {0,0};
                float angle = 0.f;
                if(pattern == 1 || pattern == 3){
                    angle = 90.f / (_trajectoryDurationTotal - 1);
                } else{
                    angle = 45.f / (_trajectoryDurationTotal - 1);
                }
                angle = (angle * 3.14159265f) / 180.f;
                sf::Vector2f sum = {0,0};
                for(int i = 0; i < _trajectoryDurationTotal; i++){
                    if(pattern == 1 || pattern == 2){
                        velocityDiff = {(differentialPosition.x * cosf(i * angle)), differentialPosition.y * sinf(i * angle)};
                    } else{
                        velocityDiff = {(differentialPosition.x * sinf(i * angle)), differentialPosition.y * cosf(i * angle)};
                    }
                    _velocities[i] = velocityDiff;
                    sum += velocityDiff;
                }
                sf::Vector2f multiplier = {differentialPosition.x/sum.x, differentialPosition.y/sum.y};
                for(int i = 0; i < _trajectoryDurationTotal; i++){
                    _velocities[i] = {_velocities[i].x * multiplier.x, _velocities[i].y * multiplier.y};
                }
            }
            moveEntity();
        }
        _curVelocity = curVelocity;
        tmpPosition.x += std::round(curVelocity.x);
        tmpPosition.y += std::round(curVelocity.y);
        if(_trajectoryDurationCtr < _trajectoryDurationTotal){
            sf::Vector2f remainder = {_curVelocity.x - std::round(_curVelocity.x), _curVelocity.y - std::round(_curVelocity.y)};
            _velocities[_trajectoryDurationCtr] += remainder;
        }
        setPosition(tmpPosition);
    } else if(_returningIdle){
        if(_trajectoryDurationCtr < _trajectoryDurationTotal){
            _curVelocity = _velocities[_trajectoryDurationCtr];
            _trajectoryDurationCtr += 1;
            sf::Vector2f tmpPosition = getPosition();
            tmpPosition.x += std::round(_curVelocity.x);
            tmpPosition.y += std::round(_curVelocity.y);
            if(_trajectoryDurationCtr < _trajectoryDurationTotal){
                sf::Vector2f remainder = {_curVelocity.x - std::round(_curVelocity.x), _curVelocity.y - std::round(_curVelocity.y)};
                _velocities[_trajectoryDurationCtr] += remainder;
            }
            setPosition(tmpPosition);
        } else{
            setPosition(_centralPosition);
            _returningIdle = false;
            _idle = true;
        }
    }else{
        if(_velocities){
            delete _velocities;
            _velocities = nullptr;
        }
        _velocities = new(std::nothrow) sf::Vector2f[30];
        sf::Vector2f posDifference = _centralPosition + - getPosition();
        //posDifference.x += _offset;
        sf::Vector2f velocityDiff = {posDifference.x / 30, posDifference.y / 30};
        for(int i = 0; i < 30; i++){
            _velocities[i] = velocityDiff;
        }
        _returningIdle = true;
        _trajectoryDurationCtr = 0;
        _trajectoryDurationTotal = 30;
    }
}

void Enemy::shoot(sf::Texture &texture, sf::Vector2f velocity){
    Bullet bullet = Bullet(getPosition(), velocity);
    bullet.setTexture(texture);
    bullets.insertTail(bullet);
}

void Enemy::setPositionsROM(const sf::Vector2f patternPositions[], int count){
    for(int i = 0; i < count; i++){
        _patternPositions[i] = patternPositions[i];
    }
    if(count < 100){
        for(int i = count; i < 100; ++i){
            _patternPositions[i] = {0,0};
        }
    }
}

void Enemy::setDurationROM(const int durationTicks[], int count){
    for(int i = 0; i < count; i++){
        _durationTicks[i] = durationTicks[i];
    }
    if(count < 100){
        for(int i = count; i < 100; ++i){
            _durationTicks[i] = 0;
        }
    }
}

void Enemy::setStateROM(const int patternState[], int count){
    for(int i = 0; i < count; i++){
        _patternState[i] = patternState[i];
    }
    if(count < 100){
        for(int i = count; i < 100; ++i){
            _patternState[i] = 0;
        }
    }
}

bool Enemy::operator==(Enemy &enemy){
    if(getPosition() == enemy.getPosition() && getVelocity() == enemy.getVelocity()) return true;
    return false;
}