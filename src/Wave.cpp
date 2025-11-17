#include "Wave.hpp"

Wave::Wave(int stageNumber, int waveNumber){
    namespace Stage = gm::Stage;
    switch (stageNumber){
        case 1:{
            using namespace Stage::Scene_1;
            switch (waveNumber){
                case 1:{
                    using namespace Wave_1;
                    rows.insertTail(new Row(Row_1::MIXED, Row_1::TYPE, Row_1::MIN_ENEMY_AMOUNT,Row_1::TOTAL_POSITIONS, Row_1::GRID_POS_X, Row_1::GRID_POS_Y, Row_1::DURATION_TICKS, Row_1::TRAJECTORY, Row_1::GRID_FINAL_POS_X, Row_1::GRID_FINAL_POS_Y));
                    if(count != 1){
                        rows.insertTail(new Row(Row_2::MIXED, Row_2::TYPE, Row_2::MIN_ENEMY_AMOUNT, Row_2::TOTAL_POSITIONS,Row_2::GRID_POS_X, Row_2::GRID_POS_Y, Row_1::DURATION_TICKS, Row_1::TRAJECTORY, Row_2::GRID_FINAL_POS_X, Row_2::GRID_FINAL_POS_Y));
                    }
                }break;
                case 2:{
                    using namespace Wave_2;
                    rows.insertTail(new Row(Row_1::MIXED, Row_1::TYPE, Row_1::MIN_ENEMY_AMOUNT, Row_1::TOTAL_POSITIONS,Row_1::GRID_POS_X, Row_1::GRID_POS_Y, Row_1::DURATION_TICKS, Row_1::TRAJECTORY, Row_1::GRID_FINAL_POS_X, Row_1::GRID_FINAL_POS_Y));
                    if(count != 1){
                        rows.insertTail(new Row(Row_2::MIXED, Row_2::TYPE, Row_2::MIN_ENEMY_AMOUNT, Row_2::TOTAL_POSITIONS,Row_2::GRID_POS_X, Row_2::GRID_POS_Y, Row_1::DURATION_TICKS, Row_1::TRAJECTORY, Row_2::GRID_FINAL_POS_X, Row_2::GRID_FINAL_POS_Y));
                    }
                }break;
                case 3:{
                    using namespace Wave_3;
                    rows.insertTail(new Row(Row_1::MIXED, Row_1::TYPE, Row_1::MIN_ENEMY_AMOUNT, Row_1::TOTAL_POSITIONS,Row_1::GRID_POS_X, Row_1::GRID_POS_Y, Row_1::DURATION_TICKS, Row_1::TRAJECTORY, Row_1::GRID_FINAL_POS_X, Row_1::GRID_FINAL_POS_Y));
                    if(count != 1){
                        rows.insertTail(new Row(Row_2::MIXED, Row_2::TYPE, Row_2::MIN_ENEMY_AMOUNT, Row_2::TOTAL_POSITIONS,Row_2::GRID_POS_X, Row_2::GRID_POS_Y, Row_1::DURATION_TICKS, Row_1::TRAJECTORY, Row_2::GRID_FINAL_POS_X, Row_2::GRID_FINAL_POS_Y));
                    }
                }break;
                case 4:{
                    using namespace Wave_4;
                    rows.insertTail(new Row(Row_1::MIXED, Row_1::TYPE, Row_1::MIN_ENEMY_AMOUNT, Row_1::TOTAL_POSITIONS,Row_1::GRID_POS_X, Row_1::GRID_POS_Y, Row_1::DURATION_TICKS, Row_1::TRAJECTORY, Row_1::GRID_FINAL_POS_X, Row_1::GRID_FINAL_POS_Y));
                    if(count != 1){
                        rows.insertTail(new Row(Row_2::MIXED, Row_2::TYPE, Row_2::MIN_ENEMY_AMOUNT, Row_2::TOTAL_POSITIONS,Row_2::GRID_POS_X, Row_2::GRID_POS_Y, Row_1::DURATION_TICKS, Row_1::TRAJECTORY, Row_2::GRID_FINAL_POS_X, Row_2::GRID_FINAL_POS_Y));
                    }
                }break;
                case 5:{
                    using namespace Wave_5;
                    rows.insertTail(new Row(Row_1::MIXED, Row_1::TYPE, Row_1::MIN_ENEMY_AMOUNT, Row_1::TOTAL_POSITIONS,Row_1::GRID_POS_X, Row_1::GRID_POS_Y, Row_1::DURATION_TICKS, Row_1::TRAJECTORY, Row_1::GRID_FINAL_POS_X, Row_1::GRID_FINAL_POS_Y));
                    if(count != 1){
                        rows.insertTail(new Row(Row_2::MIXED, Row_2::TYPE, Row_2::MIN_ENEMY_AMOUNT, Row_2::TOTAL_POSITIONS,Row_2::GRID_POS_X, Row_2::GRID_POS_Y, Row_1::DURATION_TICKS, Row_1::TRAJECTORY, Row_2::GRID_FINAL_POS_X, Row_2::GRID_FINAL_POS_Y));
                    }
                }break;
            }
        }break;
        case 2:{
            using namespace Stage::Scene_2;
            switch (waveNumber){
                case 1:{
                    using namespace Wave_1;
                    rows.insertTail(new Row(Row_1::MIXED, Row_1::TYPE, Row_1::MIN_ENEMY_AMOUNT, Row_1::TOTAL_POSITIONS,Row_1::GRID_POS_X, Row_1::GRID_POS_Y, Row_1::DURATION_TICKS, Row_1::TRAJECTORY, Row_1::GRID_FINAL_POS_X, Row_1::GRID_FINAL_POS_Y));
                    if(count != 1){
                        rows.insertTail(new Row(Row_2::MIXED, Row_2::TYPE, Row_2::MIN_ENEMY_AMOUNT, Row_2::TOTAL_POSITIONS,Row_2::GRID_POS_X, Row_2::GRID_POS_Y, Row_1::DURATION_TICKS, Row_1::TRAJECTORY, Row_2::GRID_FINAL_POS_X, Row_2::GRID_FINAL_POS_Y));
                    }
                }break;
                case 2:{
                    using namespace Wave_2;
                    rows.insertTail(new Row(Row_1::MIXED, Row_1::TYPE, Row_1::MIN_ENEMY_AMOUNT, Row_1::TOTAL_POSITIONS,Row_1::GRID_POS_X, Row_1::GRID_POS_Y, Row_1::DURATION_TICKS, Row_1::TRAJECTORY, Row_1::GRID_FINAL_POS_X, Row_1::GRID_FINAL_POS_Y));
                    if(count != 1){
                        rows.insertTail(new Row(Row_2::MIXED, Row_2::TYPE, Row_2::MIN_ENEMY_AMOUNT, Row_2::TOTAL_POSITIONS,Row_2::GRID_POS_X, Row_2::GRID_POS_Y, Row_1::DURATION_TICKS, Row_1::TRAJECTORY, Row_2::GRID_FINAL_POS_X, Row_2::GRID_FINAL_POS_Y));
                    }
                }break;
                case 3:{
                    using namespace Wave_3;
                    rows.insertTail(new Row(Row_1::MIXED, Row_1::TYPE, Row_1::MIN_ENEMY_AMOUNT, Row_1::TOTAL_POSITIONS,Row_1::GRID_POS_X, Row_1::GRID_POS_Y, Row_1::DURATION_TICKS, Row_1::TRAJECTORY, Row_1::GRID_FINAL_POS_X, Row_1::GRID_FINAL_POS_Y));
                    if(count != 1){
                        rows.insertTail(new Row(Row_2::MIXED, Row_2::TYPE, Row_2::MIN_ENEMY_AMOUNT, Row_2::TOTAL_POSITIONS,Row_2::GRID_POS_X, Row_2::GRID_POS_Y, Row_1::DURATION_TICKS, Row_1::TRAJECTORY, Row_2::GRID_FINAL_POS_X, Row_2::GRID_FINAL_POS_Y));
                    }
                }break;
                case 4:{
                    using namespace Wave_4;
                    rows.insertTail(new Row(Row_1::MIXED, Row_1::TYPE, Row_1::MIN_ENEMY_AMOUNT, Row_1::TOTAL_POSITIONS,Row_1::GRID_POS_X, Row_1::GRID_POS_Y, Row_1::DURATION_TICKS, Row_1::TRAJECTORY, Row_1::GRID_FINAL_POS_X, Row_1::GRID_FINAL_POS_Y));
                    if(count != 1){
                        rows.insertTail(new Row(Row_2::MIXED, Row_2::TYPE, Row_2::MIN_ENEMY_AMOUNT, Row_2::TOTAL_POSITIONS,Row_2::GRID_POS_X, Row_2::GRID_POS_Y, Row_1::DURATION_TICKS, Row_1::TRAJECTORY, Row_2::GRID_FINAL_POS_X, Row_2::GRID_FINAL_POS_Y));
                    }
                }break;
                case 5:{
                    using namespace Wave_5;
                    rows.insertTail(new Row(Row_1::MIXED, Row_1::TYPE, Row_1::MIN_ENEMY_AMOUNT, Row_1::TOTAL_POSITIONS,Row_1::GRID_POS_X, Row_1::GRID_POS_Y, Row_1::DURATION_TICKS, Row_1::TRAJECTORY, Row_1::GRID_FINAL_POS_X, Row_1::GRID_FINAL_POS_Y));
                    if(count != 1){
                        rows.insertTail(new Row(Row_2::MIXED, Row_2::TYPE, Row_2::MIN_ENEMY_AMOUNT, Row_2::TOTAL_POSITIONS,Row_2::GRID_POS_X, Row_2::GRID_POS_Y, Row_1::DURATION_TICKS, Row_1::TRAJECTORY, Row_2::GRID_FINAL_POS_X, Row_2::GRID_FINAL_POS_Y));
                    }
                }break;
            }
        }break;
        case 3:{
            using namespace Stage::Scene_3;
            switch (waveNumber){
                case 1:{
                    using namespace Wave_1;
                    rows.insertTail(new Row(Row_1::MIXED, Row_1::TYPE, Row_1::MIN_ENEMY_AMOUNT, Row_1::TOTAL_POSITIONS,Row_1::GRID_POS_X, Row_1::GRID_POS_Y, Row_1::DURATION_TICKS, Row_1::TRAJECTORY, Row_1::GRID_FINAL_POS_X, Row_1::GRID_FINAL_POS_Y));
                    if(count != 1){
                        rows.insertTail(new Row(Row_2::MIXED, Row_2::TYPE, Row_2::MIN_ENEMY_AMOUNT, Row_2::TOTAL_POSITIONS,Row_2::GRID_POS_X, Row_2::GRID_POS_Y, Row_1::DURATION_TICKS, Row_1::TRAJECTORY, Row_2::GRID_FINAL_POS_X, Row_2::GRID_FINAL_POS_Y));
                    }
                }break;
                case 2:{
                    using namespace Wave_2;
                    rows.insertTail(new Row(Row_1::MIXED, Row_1::TYPE, Row_1::MIN_ENEMY_AMOUNT, Row_1::TOTAL_POSITIONS,Row_1::GRID_POS_X, Row_1::GRID_POS_Y, Row_1::DURATION_TICKS, Row_1::TRAJECTORY, Row_1::GRID_FINAL_POS_X, Row_1::GRID_FINAL_POS_Y));

                }break;
                case 3:{
                    using namespace Wave_3;
                    rows.insertTail(new Row(Row_1::MIXED, Row_1::TYPE, Row_1::MIN_ENEMY_AMOUNT, Row_1::TOTAL_POSITIONS,Row_1::GRID_POS_X, Row_1::GRID_POS_Y, Row_1::DURATION_TICKS, Row_1::TRAJECTORY, Row_1::GRID_FINAL_POS_X, Row_1::GRID_FINAL_POS_Y));
                }break;
                case 4:{
                    using namespace Wave_4;
                    rows.insertTail(new Row(Row_1::MIXED, Row_1::TYPE, Row_1::MIN_ENEMY_AMOUNT, Row_1::TOTAL_POSITIONS,Row_1::GRID_POS_X, Row_1::GRID_POS_Y, Row_1::DURATION_TICKS, Row_1::TRAJECTORY, Row_1::GRID_FINAL_POS_X, Row_1::GRID_FINAL_POS_Y));
                }break;
                case 5:{
                    using namespace Wave_5;
                    rows.insertTail(new Row(Row_1::MIXED, Row_1::TYPE, Row_1::MIN_ENEMY_AMOUNT, Row_1::TOTAL_POSITIONS,Row_1::GRID_POS_X, Row_1::GRID_POS_Y, Row_1::DURATION_TICKS, Row_1::TRAJECTORY, Row_1::GRID_FINAL_POS_X, Row_1::GRID_FINAL_POS_Y));
                }break;
            }
        }break;
    }
}