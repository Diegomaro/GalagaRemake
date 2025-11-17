#include "Row.hpp"

sf::Vector2f Row::startPos = {gm::Enemy::ORIGIN_X, gm::Enemy::ORIGIN_Y};


Row::Row(const bool mixed, const int type[], const int enemyAmount, const int posAmount, const int x_pos[], const int y_pos[], const int duration[], const int state[],const int x_grid[], const int y_grid[]){
    sf::Vector2f positions [posAmount];
    for(int i = 0; i < posAmount; i++){
        positions[i] = {x_pos[i] * gm::Sprite::WIDTH * gm::Window::SCALE, y_pos[i] * gm::Sprite::HEIGHT * gm::Window::SCALE};
    }
    if(!mixed){
        for(int i = 0; i < enemyAmount; i++){
            sf::Vector2f finalPosition = startPos;
            finalPosition.x += x_grid[i] * gm::Sprite::WIDTH * gm::Window::SCALE;
            finalPosition.y += y_grid[i] * gm::Sprite::HEIGHT * gm::Window::SCALE;
            enemies.insertTail(new Enemy(finalPosition, type[0], positions, duration, state, enemyAmount));

        }
    } else{
        bool typeSwitch = false;
        for(int i = 0; i < enemyAmount; i++){
            sf::Vector2f finalPosition = startPos;
            finalPosition.x += x_grid[i] * gm::Sprite::WIDTH * gm::Window::SCALE;
            finalPosition.y += y_grid[i] * gm::Sprite::HEIGHT * gm::Window::SCALE;
            enemies.insertTail(new Enemy(finalPosition, type[typeSwitch], positions, duration, state, enemyAmount));

            typeSwitch = !typeSwitch;
        }
    }
}