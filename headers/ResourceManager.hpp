#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class ResourceManager {
    public:
    bool loadTexture(std::string name, std::string fileName);
    sf::Texture& getTexture(std::string name);
    private:
        std::map<std::string, sf::Texture> textureMap;
};