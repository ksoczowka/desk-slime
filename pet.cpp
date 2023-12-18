#include "pet.hpp"

Pet::Pet() {
    position_ = {0, 0}; // prevent bugs from not getting position
    size_ = {1, 1}; // prevent bugs from 0x0px size of the sprite
}

void Pet::setState(const PetState& newState) { 
    state_ = newState;
    makeTexture();
}

void Pet::makeTexture() {
    texture_ = textureMap_.at(state_);

    texture_.height = size_.y;
    texture_.width = size_.x;
    
}

void Pet::draw() {
    DrawTexture(texture_, position_.x, position_.y, WHITE);
}

void Pet::loadAllTextures() {
    for(const auto& [key, value] : spritePathMap_) {
        Texture2D buff = LoadTexture(value.c_str());
        textureMap_.emplace(std::make_pair(key, buff));
    }
}