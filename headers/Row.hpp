#pragma once
#include "DoubleLinkedList.hpp"
#include "Enemy.hpp"
#include <SFML/Graphics.hpp>

class Row{
    public:
        Row(const bool mixed, const int type[], const int minAmount, const int x_grid[], const int y_grid[]);
        DoubleLinkedList<Enemy*> enemies;
    private:
        static sf::Vector2f startPos;
};