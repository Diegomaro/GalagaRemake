#include "ResourceManager.hpp"

ResourceManager::~ResourceManager(){
    textureMap.clear();
}

bool ResourceManager::loadTexture(std::string name, std::string fileName){
    sf::Texture texture;
    if(!texture.loadFromFile(fileName)){
        std::cout << "Could not find file!" << std::endl;
        return false;
    }
    texture.setSmooth(false);
    textureMap.insert({name, texture});
    return true;
}

sf::Texture& ResourceManager::getTexture(std::string name){
    return textureMap[name];
}