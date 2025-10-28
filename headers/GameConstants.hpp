#pragma once
#include <SFML/System/Time.hpp>

namespace Consts {
    namespace Window {
        inline constexpr unsigned int WIDTH = 672;  // 224 * SCALE
        inline constexpr unsigned int HEIGHT = 864; // 288 * SCALE
        inline constexpr int SCALE = 3;
    }
    namespace Sprite {
        inline constexpr unsigned int WIDTH = 16;
        inline constexpr unsigned int HEIGHT = 16;

    }
    namespace Player {
        inline constexpr float SPEED = 6.0f;
        inline constexpr int SHOOT_COOLDOWN = 30;
    }

    namespace Enemy{
        inline constexpr int DEAD_ENEMY_COUNTER = 29;
        /*30 = 5 anitick * 6 frames, but
        5 is the total animation frames, so the fifth frame should be extended and sixth skipped, so 30-1 */
    }
    namespace Timestep {
        inline const sf::Time FIXED = sf::milliseconds(1000.0f / 60.0f);
    }
}