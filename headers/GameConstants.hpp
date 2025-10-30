#pragma once
#include <SFML/System/Time.hpp>
#include <random>

namespace gm {
    namespace Window {
        inline constexpr unsigned int WIDTH = 672;  // 224 * SCALE
        inline constexpr unsigned int HEIGHT = 864; // 288 * SCALE
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
        inline constexpr float X_POS = (112-8)*3;
        inline constexpr float Y_POS = 260*3;
    }
    namespace Bullet {
        inline constexpr float UP_BORDER = -5;
        inline constexpr float DOWN_BORDER = 869;
        inline constexpr float SPEED = 10.0f;
    }
    namespace Enemy{
        enum class Points : int {
            One = 50,
            Two = 70,
            Three = 90
        };
        inline constexpr int SHOOT_COOLDOWN = 100;
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