#include "Player.hpp"

Player::Player(): shootCooldown(0) {
    _sprite_dimensions = sf::IntRect(6*16,0*16,16,16);
    setTextureRect(_sprite_dimensions);
    setScale({3, 3});
    setPosition({(112-8)*3, 260*3});
    hitbox.width = 16*3;
    hitbox.height = 16*3;
}

void Player::ShootBullet(sf::Texture &texture){
    Bullet bullet = Bullet(getPosition());
    bullet.setTexture(texture);
    bullets.insertTail(bullet);
}