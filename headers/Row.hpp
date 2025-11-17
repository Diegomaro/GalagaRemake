#pragma once
#include "DoubleLinkedList.hpp"
#include "Enemy.hpp"
#include <SFML/Graphics.hpp>

class Row{
    public:
        Row(const bool mixed, const int type[], const int enemyAmount, const int posAmount, const int x_pos[], const int y_pos[], const int duration[], const int state[],const int x_grid[], const int y_grid[]);
        DoubleLinkedList<Enemy*> enemies;
        //void resetNextAcceleration();
        //bool hasNextAcceleration();
        //sf::Vector2f getNextAcceleration();

    private:
        static sf::Vector2f startPos;
        static sf::Vector2f acceleration[];
        static sf::Vector2f durationTicks[];
};