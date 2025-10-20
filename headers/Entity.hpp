#pragma once
#include <string>
#include <ResourceManager.hpp>

class Entity{
    public:
        Entity(ResourceManager& rm, std::string fileName, std::string mTextureKey);
        std::string getTextureKey();
    private:
        sf::Sprite entity;
        std::string textureKey;
        sf::Vector2i pos;
        sf::Vector2i vel;
};