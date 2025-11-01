#pragma once
#include <SFML/System/Time.hpp>
#include <random>

namespace gm {
    namespace Window {
        inline constexpr int WIDTH = 672;  // 224 * SCALE
        inline constexpr int HEIGHT = 864; // 288 * SCALE
        inline constexpr float SCALE = 3.f;
    }
    namespace Background {
        inline constexpr unsigned int WIDTH = 224;
        inline constexpr unsigned int HEIGHT = 288;
    }
    namespace Sprite {
        inline constexpr unsigned int WIDTH = 16;
        inline constexpr unsigned int HEIGHT = 16;
    }
    namespace Player {
        inline constexpr float SPEED = 6.0f;
        inline constexpr int SHOOT_COOLDOWN = 30;
        inline constexpr int RESPAWN_COOLDOWN = 100;
        inline constexpr float X_POS = (112-8) * gm::Window::SCALE;
        inline constexpr float Y_POS = 260 * gm::Window::SCALE;
    }
    namespace Bullet {
        inline constexpr float UP_BORDER = -5;
        inline constexpr float DOWN_BORDER = 869;
        inline constexpr float SPEED = 10.0f;
    }
    namespace Enemy{
        inline constexpr int SHOOT_COOLDOWN = 100;
        inline constexpr float ORIGIN_X = 32*gm::Window::SCALE;
        inline constexpr float ORIGIN_Y = 25*gm::Window::SCALE;
        enum class Type : int {
            null = 0,
            galaxian = 2,
            butterfly = 4,
            bee = 5

        };
        enum class Points : int {
            One = 50,
            Two = 70,
            Three = 90
        };
    }

    namespace Stage {
        namespace Scene_1{
            namespace Wave_1{
                inline constexpr int count = 2;
                namespace Row_1{
                    inline constexpr bool MIXED = false;
                    int constexpr TYPE[1] = {4};
                    int constexpr MIN_AMOUNT = 4;
                    int constexpr GRID_FINAL_POS_X[4] = {4, 4, 5 ,5};
                    int constexpr GRID_FINAL_POS_Y[4] = {2, 3, 2, 3};
                }
                namespace Row_2{
                    inline constexpr bool MIXED = false;
                    int constexpr TYPE[1] = {5};
                    int constexpr MIN_AMOUNT = 4;
                    int constexpr GRID_FINAL_POS_X[4] = {4, 4, 5, 5};
                    int constexpr GRID_FINAL_POS_Y[4] = {4, 5, 4, 5};
                }
            }
            namespace Wave_2{
                inline constexpr int count = 2;
                namespace Row_1{
                    inline constexpr bool MIXED = false;
                    int constexpr TYPE[1] = {2};
                    int constexpr MIN_AMOUNT = 4;
                    int constexpr GRID_FINAL_POS_X[4] = {3, 4, 5, 6};
                    int constexpr GRID_FINAL_POS_Y[4] = {1, 1, 1 ,1};
                }
                namespace Row_2{
                    inline constexpr bool MIXED = false;
                    int constexpr TYPE[1] = {4};
                    int constexpr MIN_AMOUNT = 4;
                    int constexpr GRID_FINAL_POS_X[4] = {3, 3, 6, 6};
                    int constexpr GRID_FINAL_POS_Y[4] = {2, 3, 2, 3};
                }
            }
            namespace Wave_3{
                inline constexpr int count = 2;
                namespace Row_1{
                    inline constexpr bool MIXED = false;
                    int constexpr TYPE[1] = {4};
                    int constexpr MIN_AMOUNT = 4;
                    int constexpr GRID_FINAL_POS_X[4] = {1, 1, 2, 2};
                    int constexpr GRID_FINAL_POS_Y[4] = {2, 3, 2, 3};
                }
                namespace Row_2{
                    inline constexpr bool MIXED = false;
                    int constexpr TYPE[1] = {4};
                    int constexpr MIN_AMOUNT = 4;
                    int constexpr GRID_FINAL_POS_X[4] = {7, 7, 8, 8};
                    int constexpr GRID_FINAL_POS_Y[4] = {2, 3, 2, 3};
                }
            }
            namespace Wave_4{
                inline constexpr int count = 2;
                namespace Row_1{
                    inline constexpr bool MIXED = false;
                    int constexpr TYPE[1] = {5};
                    int constexpr MIN_AMOUNT = 4;
                    int constexpr GRID_FINAL_POS_X[4] = {2, 2, 3, 3};
                    int constexpr GRID_FINAL_POS_Y[4] = {4, 5, 4, 5};
                }
                namespace Row_2{
                    inline constexpr bool MIXED = false;
                    int constexpr TYPE[1] = {5};
                    int constexpr MIN_AMOUNT = 4;
                    int constexpr GRID_FINAL_POS_X[4] = {6, 6, 7, 7};
                    int constexpr GRID_FINAL_POS_Y[4] = {4, 5, 4, 5};
                }
            }
            namespace Wave_5{
                inline constexpr int count = 2;
                namespace Row_1{
                    inline constexpr bool MIXED = false;
                    int constexpr TYPE[1] = {5};
                    int constexpr MIN_AMOUNT = 4;
                    int constexpr GRID_FINAL_POS_X[4] = {0, 0, 1, 1};
                    int constexpr GRID_FINAL_POS_Y[4] = {4, 5, 4, 5};
                }
                namespace Row_2{
                    inline constexpr bool MIXED = false;
                    int constexpr TYPE[1] = {5};
                    int constexpr MIN_AMOUNT = 4;
                    int constexpr GRID_FINAL_POS_X[4] = {8, 8, 9, 9};
                    int constexpr GRID_FINAL_POS_Y[4] = {4, 5, 4, 5};
                }
            }
        }
        namespace Scene_2{
            namespace Wave_1{
                inline constexpr int count = 2;
                namespace Row_1{
                    inline constexpr bool MIXED = false;
                    int constexpr TYPE[1] = {4};
                    int constexpr MIN_AMOUNT = 4;
                    int constexpr GRID_FINAL_POS_X[4] = {4, 4, 5 ,5};
                    int constexpr GRID_FINAL_POS_Y[4] = {2, 3, 2, 3};
                }
                namespace Row_2{
                    inline constexpr bool MIXED = false;
                    int constexpr TYPE[1] = {5};
                    int constexpr MIN_AMOUNT = 4;
                    int constexpr GRID_FINAL_POS_X[4] = {4, 4, 5 ,5};
                    int constexpr GRID_FINAL_POS_Y[4] = {4, 5, 4, 5};
                }
            }
            namespace Wave_2{
                inline constexpr int count = 2;
                namespace Row_1{
                    inline constexpr bool MIXED = false;
                    int constexpr TYPE[1] = {4};
                    int constexpr MIN_AMOUNT = 4;
                    int constexpr GRID_FINAL_POS_X[4] = {3, 3, 6, 6};
                    int constexpr GRID_FINAL_POS_Y[4] = {2, 3, 2, 3};
                }
                namespace Row_2{
                    inline constexpr bool MIXED = false;
                    int constexpr TYPE[1] = {2};
                    int constexpr MIN_AMOUNT = 4;
                    int constexpr GRID_FINAL_POS_X[4] = {3, 4, 5, 6};
                    int constexpr GRID_FINAL_POS_Y[4] = {1, 1, 1, 1};
                }
            }
            namespace Wave_3{
                inline constexpr int count = 2;
                namespace Row_1{
                    inline constexpr bool MIXED = false;
                    int constexpr TYPE[1] = {4};
                    int constexpr MIN_AMOUNT = 4;
                    int constexpr GRID_FINAL_POS_X[4] = {1, 1, 2, 2};
                    int constexpr GRID_FINAL_POS_Y[4] = {2, 3, 2, 3};
                }
                namespace Row_2{
                    inline constexpr bool MIXED = false;
                    int constexpr TYPE[1] = {4};
                    int constexpr MIN_AMOUNT = 4;
                    int constexpr GRID_FINAL_POS_X[4] = {7, 7, 8, 8};
                    int constexpr GRID_FINAL_POS_Y[4] = {2, 3, 2, 3};
                }
            }
            namespace Wave_4{
                inline constexpr int count = 2;
                namespace Row_1{
                    inline constexpr bool MIXED = false;
                    int constexpr TYPE[1] = {5};
                    int constexpr MIN_AMOUNT = 4;
                    int constexpr GRID_FINAL_POS_X[4] = {2, 2, 3, 3};
                    int constexpr GRID_FINAL_POS_Y[4] = {4, 5, 4, 5};
                }
                namespace Row_2{
                    inline constexpr bool MIXED = false;
                    int constexpr TYPE[1] = {5};
                    int constexpr MIN_AMOUNT = 4;
                    int constexpr GRID_FINAL_POS_X[4] = {6, 6, 7, 7};
                    int constexpr GRID_FINAL_POS_Y[4] = {4, 5, 4, 5};
                }
            }
            namespace Wave_5{
                inline constexpr int count = 2;
                namespace Row_1{
                    inline constexpr bool MIXED = false;
                    int constexpr TYPE[1] = {5};
                    int constexpr MIN_AMOUNT = 4;
                    int constexpr GRID_FINAL_POS_X[4] = {0, 0, 1, 1};
                    int constexpr GRID_FINAL_POS_Y[4] = {4, 5, 4, 5};
                }
                namespace Row_2{
                    inline constexpr bool MIXED = false;
                    int constexpr TYPE[1] = {5};
                    int constexpr MIN_AMOUNT = 4;
                    int constexpr GRID_FINAL_POS_X[4] = {8, 8, 9, 9};
                    int constexpr GRID_FINAL_POS_Y[4] = {4, 5, 4, 5};
                }
            }

        }
        namespace Scene_3{
            namespace Wave_1{
                inline constexpr int count = 2;
                namespace Row_1{
                    inline constexpr bool MIXED = false;
                    int constexpr TYPE[1] = {4};
                    int constexpr MIN_AMOUNT = 4;
                    int constexpr GRID_FINAL_POS_X[4] = {4, 5, 4 ,5};
                    int constexpr GRID_FINAL_POS_Y[4] = {2, 2, 3, 3};
                }
                namespace Row_2{
                    inline constexpr bool MIXED = false;
                    int constexpr TYPE[1] = {5};
                    int constexpr MIN_AMOUNT = 4;
                    int constexpr GRID_FINAL_POS_X[4] = {4, 5, 4, 5};
                    int constexpr GRID_FINAL_POS_Y[4] = {4, 4, 5, 5};
                }
            }
            namespace Wave_2{
                inline constexpr int count = 1;
                namespace Row_1{
                    inline constexpr bool MIXED = true;
                    int constexpr TYPE[2] = {2,4};
                    int constexpr MIN_AMOUNT = 8;
                    int constexpr GRID_FINAL_POS_X[8] = {3, 3, 4, 3, 5, 6, 6, 6};
                    int constexpr GRID_FINAL_POS_Y[8] = {1, 2, 1, 3, 1, 2, 1, 3};
                }
            }
            namespace Wave_3{
                inline constexpr int count  = 1;
                namespace Row_1{
                    inline constexpr bool MIXED = false;
                    int constexpr TYPE[1] = {4};
                    int constexpr MIN_AMOUNT = 8;
                    int constexpr GRID_FINAL_POS_X[8] = {1, 1, 2, 2, 7, 7, 8, 8};
                    int constexpr GRID_FINAL_POS_Y[8] = {2, 3, 2, 3, 2, 3, 2, 3};
                }
            }
            namespace Wave_4{
                inline constexpr int count = 1;
                namespace Row_1{
                    inline constexpr bool MIXED = false;
                    int constexpr TYPE[1] = {5};
                    int constexpr MIN_AMOUNT = 8;
                    int constexpr GRID_FINAL_POS_X[8] = {2, 2, 3, 3, 6, 6, 7, 7};
                    int constexpr GRID_FINAL_POS_Y[8] = {4, 5, 4, 5, 4, 5, 4, 5};
                }
            }
            namespace Wave_5{
                inline constexpr int count = 1;
                namespace Row_1{
                    inline constexpr bool MIXED = false;
                    int constexpr TYPE[1] = {5};
                    int constexpr MIN_AMOUNT = 8;
                    int constexpr GRID_FINAL_POS_X[8] = {0, 0, 1, 1, 8, 8, 9, 9};
                    int constexpr GRID_FINAL_POS_Y[8] = {4, 5, 4, 5, 4, 5, 4, 5};
                }
            }
        }
    }

    namespace Timestep {
        inline const sf::Time FIXED = sf::milliseconds(1000.0f / 60.0f);
    }
    inline std::mt19937& rng() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        return gen;
    }
    inline int randomInt(int min, int max) {
        std::uniform_int_distribution<int> dist(min, max);
        return dist(rng());
    }
}