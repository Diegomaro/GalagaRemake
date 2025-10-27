#pragma once
#include <string>
#include <SFML/Graphics.hpp>
class Entity: public sf::Sprite {
    public:
        virtual void setVelocity(sf::Vector2f velocity);
        virtual sf::Vector2f getVelocity();
        virtual sf::FloatRect getHitbox();
        virtual void setHealt(int health);
        virtual void modifyHealth(int health);
        virtual int getHealth();

        virtual void stepAniCount();
        virtual void resetAniCount();
        virtual int getAniCount();
        virtual int getAniIndex();


        virtual void stepAniTickCount();
        virtual void resetAniTickCount();
        virtual int getAniTickCount();

        virtual void setAniStartIndex(sf::Vector2i aniStartIndex);
        virtual sf::Vector2i getAniStartIndex();

        virtual void setSpriteDimensions(sf::IntRect spriteDimensions);
        virtual sf::IntRect getSpriteDimensions();
        virtual void setSprite(int xPos, int yPos);
    protected:
        sf::Vector2f _velocity;
        sf::IntRect _sprite_dimensions;
        sf::FloatRect _hitbox;
        int _health;
        int _aniIndex;
        int _aniCount;
        int _aniTickCount;
        sf::Vector2i _aniStartIndex;
};