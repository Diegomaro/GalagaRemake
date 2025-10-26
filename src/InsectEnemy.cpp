#include "InsectEnemy.hpp"

InsectEnemy::InsectEnemy(){
    //_sprite_dimensions = sf::IntRect(0*16,5*16,16,16);
    _sprite_dimensions = sf::IntRect(8*16,9*16,16,16);
    setTextureRect(_sprite_dimensions);
    setScale({3, 3});
    setPosition({20*3, 0*3});
    hitbox.width = 16*3;
    hitbox.height = 16*3;
}