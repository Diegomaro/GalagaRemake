#pragma once
#include <string>
#include <SFML/Graphics.hpp>
class Entity: public sf::Sprite {
    public:
        virtual void setVelocity(sf::Vector2f velocity);
        virtual sf::Vector2f getVelocity();
        virtual void setSpriteDimensions(sf::IntRect spriteDimensions);
        virtual sf::IntRect getSpriteDimensions();
        virtual void setSprite(int xPos, int yPos);
    protected:
        sf::Vector2f _velocity;
        sf::IntRect _sprite_dimensions;
};