#include "Stage.hpp"

Stage::Stage(int stageCounter){
    if(stageCounter == 1){
        createWaves(3);
    }
    else if(stageCounter == 2){
        createWaves(2);
    }
    else if(stageCounter == 3){
        //bonus stage
    }
    else if(stageCounter % 4 == 0){
        createWaves(1);
    } else if(stageCounter % 4 == 1){
        createWaves(2);
    } else if(stageCounter % 4 == 2){
        createWaves(3);
    } else if(stageCounter % 4 == 3){
        //bonus stage
    }
}

void Stage::createWaves(int stage){
    switch(stage){
        case 1:{
            waves.insertTail(new Wave(1,1));
            waves.insertTail(new Wave(1,2));
            waves.insertTail(new Wave(1,3));
            waves.insertTail(new Wave(1,4));
            waves.insertTail(new Wave(1,5));
        }break;
        case 2:{
            waves.insertTail(new Wave(2,1));
            waves.insertTail(new Wave(2,2));
            waves.insertTail(new Wave(2,3));
            waves.insertTail(new Wave(2,4));
            waves.insertTail(new Wave(2,5));
        }break;
        case 3:{
            waves.insertTail(new Wave(3,1));
            waves.insertTail(new Wave(3,2));
            waves.insertTail(new Wave(3,3));
            waves.insertTail(new Wave(3,4));
            waves.insertTail(new Wave(3,5));
        }break;
    }
    //bonus stage
}