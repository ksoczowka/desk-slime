#include "pet.hpp"

Pet::Pet() {
    position_ = {0, 0};
    size_ = {1, 1};
}

bool Pet::isValid() {
    if(animationIdlePath_ == "") {
        return false;
    }
    if(animationClickedPath_ == "") {
        return false;
    }

    return true;
}

void Pet::makeTexture() {
    texture_ = LoadTexture(animationIdlePath_.c_str());

    texture_.height = size_.y;
    texture_.width = size_.x;
}

void Pet::draw() {
    DrawTexture(texture_, position_.x, position_.y, WHITE);
}