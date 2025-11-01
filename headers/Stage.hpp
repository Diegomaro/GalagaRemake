#pragma once
#include "DoubleLinkedList.hpp"
#include "Wave.hpp"

class Stage{
    public:
        Stage(int stageCounter);
        DoubleLinkedList<Wave*> waves;
    private:
        void createWaves(int stage);
};