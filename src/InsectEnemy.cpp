#include "InsectEnemy.hpp"

InsectEnemy::InsectEnemy(){
    _sprite_dimensions = sf::IntRect(0*16,5*16,16,16);
    setTextureRect(_sprite_dimensions);
    setScale({3, 3});
} 