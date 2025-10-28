#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Entity: public sf::Sprite {
    public:
    //setters & getters
        void setSpriteDimensions(sf::IntRect spriteDimensions);
        sf::IntRect getSpriteDimensions();
        virtual sf::FloatRect getHitbox();
        void setVelocity(sf::Vector2f velocity);
        sf::Vector2f getVelocity();
        void setHealt(int health);
        void modifyHealth(int health);
        int getHealth();
        //initial position for animation at [0,0]
        void setAniStartIndex(sf::Vector2i aniStartIndex);
        sf::Vector2i getAniStartIndex();
        // ticks per animation frame
        void setTickPerFrame(int ticksPerFrame);
        int getTicksPerFrame();
        //counter for advancing each animation frame
        void stepAniTickCtr();
        void resetAniTickCtr();
        int getAniTickCtr();
        //total animations frames
        int getAniTotal();
        void setAniTotal(int aniTotal);
        //counter for advancing animations frames
        void stepAniCtr();
        void resetAniCtr();
        int getAniCtr();
        //move and update entity
        virtual void moveEntity() = 0;
        void updateAnimation();
        bool collisionCheck(Entity *entity2);
    protected:
        Entity();
        sf::IntRect _sprite_dimensions;
        sf::FloatRect _hitbox;
        sf::Vector2f _velocity;
        int _health;

        int _ticksPerFrame;
        int _aniTickCtr;
        int _aniTotal;
        int _aniCtr;
        sf::Vector2i _aniStartIndex;
};