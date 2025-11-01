#pragma once
#include "GameConstants.hpp"
#include "DoubleLinkedList.hpp"
#include "Row.hpp"

class Wave{
    public:
        Wave(int stageNumber, int waveNumber);
        DoubleLinkedList<Row*> rows;
    private:
};