#pragma once
#include <string>
#include <SFML/Graphics.hpp>
class Entity: public sf::Sprite {
    public:
        virtual void moveEntity() = 0;
        virtual sf::FloatRect getHitbox();
        void setVelocity(sf::Vector2f velocity);
        sf::Vector2f getVelocity();
        void setHealt(int health);
        void modifyHealth(int health);
        int getHealth();

        void setTickPerFrame(int ticksPerFrame);
        int getTicksPerFrame();

        void stepAniCtr();
        void resetAniCtr();
        int getAniCtr();
        void setAniTotal(int aniTotal);
        int getAniTotal();

        void stepAniTickCtr();
        void resetAniTickCtr();
        int getAniTickCtr();

        void setAniStartIndex(sf::Vector2i aniStartIndex);
        sf::Vector2i getAniStartIndex();

        void updateAnimation();

        void setSprite(int xPos, int yPos);
        void setSpriteDimensions(sf::IntRect spriteDimensions);
        sf::IntRect getSpriteDimensions();
    protected:
        Entity();
        sf::IntRect _sprite_dimensions;
        sf::FloatRect _hitbox;
        sf::Vector2f _velocity;

        int _ticksPerFrame;
        int _aniCtr; //aniCount
        int _aniTotal; //aniIndex
        int _aniTickCtr; //aniTickCount
        sf::Vector2i _aniStartIndex;
        int _health;
};