#include "Row.hpp"

sf::Vector2f Row::startPos = {gm::Enemy::ORIGIN_X, gm::Enemy::ORIGIN_Y};

Row::Row(const bool mixed, const int type[], const int amount, const int x_grid[], const int y_grid[]){
    if(!mixed){
        for(int i = 0; i < amount; i++){
            sf::Vector2f position = startPos;
            position.x += x_grid[i] * gm::Sprite::WIDTH * gm::Window::SCALE;
            position.y += y_grid[i] * gm::Sprite::HEIGHT * gm::Window::SCALE;
            enemies.insertTail(new Enemy(position, type[0]));
        }
    } else{
        bool typeSwitch = false;
        for(int i = 0; i < amount; i++){
            sf::Vector2f position = startPos;
            position.x += x_grid[i] * gm::Sprite::WIDTH * gm::Window::SCALE;
            position.y += y_grid[i] * gm::Sprite::HEIGHT * gm::Window::SCALE;
            enemies.insertTail(new Enemy(position, type[typeSwitch]));
            typeSwitch = !typeSwitch;
        }
    }
}