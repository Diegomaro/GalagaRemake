#include "Player.hpp"

Player::Player(){
    _sprite_dimensions = sf::IntRect(6*16,0*16,16,16);
    setTextureRect(_sprite_dimensions);
} 

void Player::ShootBullet(){

}