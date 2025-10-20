#include "ResourceManager.hpp"

bool ResourceManager::loadTexture(std::string name, std::string fileName){
    sf::Texture texture;
    if(!texture.loadFromFile(fileName)){
        std::cout << "Could not find file!" << std::endl;
        return false;
    }
    textureMap.insert({name, texture});
    return true;
}

sf::Texture& ResourceManager::getTexture(std::string name){
    return textureMap[name];
}