#include "Player.hpp"

Player::Player(): Entity(), _shootCooldown(0) {
    setSpriteDimensions(sf::IntRect(6*16,0*16,16,16));
    setPosition({(112-8)*3, 260*3});
    _health = 3;
    _isAlive = true;
}

void Player::setCanMove(bool canMove){
    _canMove = canMove;
}

bool Player::getCanMove(){
    return _canMove;
}

void Player::setIsAlive(bool isAlive){
    _isAlive = isAlive;
}

bool Player::getIsAlive(){
    return _isAlive;
}

void Player::resetShootCooldown(){
    _shootCooldown = gm::Player::SHOOT_COOLDOWN;
}

void Player::stepShootCooldown(){
    if(_shootCooldown <= 0) {
        _shootCooldown = 0;
    }
    else _shootCooldown -= 1;
}

int Player::getShootCooldown(){
    return _shootCooldown;
}

void Player::resetRespawnCooldown(){
    _respawnCooldown = gm::Player::RESPAWN_COOLDOWN;
}

void Player::stepRespawnCooldown(){
if(_respawnCooldown <= 0){
    _respawnCooldown = 0;
} else{
    _respawnCooldown -= 1;
}
}

int Player::getRespawnCooldown(){
    return _respawnCooldown;
}

bool Player::hasNextBullet(){
    return bullets.hasNext();
}

Bullet &Player::getNextBullet(){
    return bullets.getNextNodeData();
}

void Player::deleteBullet(Bullet *bullet){
    bullets.deleteNode(bullet);
}

void Player::clearBullets(){
    bullets.clear();
}

void Player::moveEntity(){
    int playerOutOfBondsPos = getPosition().x + getHitbox().width + getVelocity().x;
    int playerOutOfBondsNeg = getPosition().x + getVelocity().x;
    if(playerOutOfBondsPos <= gm::Window::WIDTH && getVelocity().x > 0){
        move(getVelocity());
    } else if(playerOutOfBondsNeg > 0 && getVelocity().x < 0){
        move(getVelocity());
    }
}

void Player::shoot(sf::Texture &texture, sf::Vector2f velocity){
    Bullet bullet = Bullet(getPosition(), velocity);
    bullet.setTexture(texture);
    bullets.insertTail(bullet);
}