#include "StageManager.hpp"

StageManager::StageManager(): _stageCounter(1), _curStage(nullptr){
    createStage();
}

StageManager::~StageManager(){
    destroyStage();
}

void StageManager::createStage(){
    _curStage = new(std::nothrow) Stage(_stageCounter);
}

void StageManager::destroyStage(){
    if(_curStage){
        delete _curStage;
    }
    _curStage = nullptr;
}

Stage* StageManager::getCurrentStage(){
    return _curStage;
}

void StageManager::advanceStage(){
    _stageCounter += 1;
    destroyStage();
    createStage();
}