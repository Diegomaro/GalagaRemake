#include "Entity.hpp"

Entity::Entity(ResourceManager& rm, std::string fileName, std::string mTextureKey): pos({0,0}), vel({0,0}), textureKey(mTextureKey){
    rm.loadTexture(textureKey, fileName);
    entity.setTexture(rm.getTexture(textureKey));
}

std::string Entity::getTextureKey(){
    return textureKey;
}
