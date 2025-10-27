#pragma once
#include <SFML/System/Time.hpp>
namespace GameConstants
{
    inline constexpr unsigned int WINDOW_WIDTH = 672;  // 224 * SCALE
    inline constexpr unsigned int WINDOW_HEIGHT = 864; // 288 * SCALE
    inline constexpr int SCALE = 3;
    inline constexpr float PLAYER_SPEED = 6.0f;
    inline constexpr float BULLET_SPEED = 10.0f;
    inline constexpr int SHOOT_COOLDOWN = 30;
    inline const sf::Time TIMESTEP = sf::milliseconds(1000.0f / 60.0f);
    inline constexpr int ANIMATION_TICK = 5;
    inline constexpr int DEAD_ENEMY_COUNTER = 29;
    /*30 = 5 anitick * 6 frames, but we only want
    5 frames, but the fifth frame should be extended, so 30-1
    */

}