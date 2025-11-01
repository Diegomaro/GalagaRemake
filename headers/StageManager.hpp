#pragma once
#include "Stage.hpp"

class StageManager{
    public:
        StageManager();
        ~StageManager();
        void createStage();
        void destroyStage();
        Stage* getCurrentStage();
        void advanceStage();
    private:
        int _stageCounter;
        Stage *_curStage;
};