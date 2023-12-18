#include "pet.hpp"

Pet::Pet() {
    position_ = {0, 0}; // prevent bugs from not getting position
    size_ = {1, 1}; // prevent bugs from 0x0px size of the sprite
}

Pet::Pet(Vector2 size, Vector2 position, std::map<PetState, std::string> spritePathMap) : size_(size), position_(position), spritePathMap_(spritePathMap) {
    loadAllTextures();
    state_ = PetState::center;
    makeTexture();

    origin_.x = ((2.f * position_.x) + size_.x) / 2.f;
    origin_.y = ((2.f * position_.y) + size_.y) / 2.f;
}

void Pet::setState(const PetState& newState) { 
    state_ = newState;
    makeTexture();
}

void Pet::onClick(const int& destination) {
        if(origin_.x > destination && position_.x > -8) {
            position_.x--;
            origin_.x--;
        } else if(origin_.x < destination && position_.x + size_.x < 264) {
            position_.x++;
            origin_.x++;
        }
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