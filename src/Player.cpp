#include "Player.hpp"

Player::Player(): Entity(), shootCooldown(0) {
    setSpriteDimensions(sf::IntRect(6*16,0*16,16,16));
    setPosition({(112-8)*3, 260*3});
    _health = 3;
}

void Player::update(){}

void Player::ShootBullet(sf::Texture &texture){
    Bullet bullet = Bullet(getPosition(), {0, -10.0f});
    bullet.setTexture(texture);
    bullets.insertTail(bullet);
}