#include "Bullet.hpp"

Bullet::Bullet(sf::Vector2f playerPosition){
    _sprite_dimensions = sf::IntRect(17*16,7*16,16,16);
    setTextureRect(_sprite_dimensions);
    setScale({3,3});
    setPosition(playerPosition);
    setVelocity({0,-1});
}