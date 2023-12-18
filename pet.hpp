#pragma once

#include <raylib.h>
#include <string>
#include <map>

enum class PetState {
    center = 0,
    left = 1,
    right = 2,
    up = 3,
    down = 4,
    upLeft = 5,
    upRight = 6,
    downLeft = 7,
    downRight = 8
};

class Pet {
public:
    Pet();

    PetState getState() { return state_; }

    std::map<PetState, std::string> getSpritePathMap() { return spritePathMap_; }

    Texture2D getTexture() { return texture_; }

    Vector2 getPosition() { return position_; }
    Vector2 getSize() { return size_; }
 
    
    void setState(const PetState& newState);
    
    void setSpritePathMap(const std::map<PetState, std::string>& newMap) { spritePathMap_ = newMap; }
    
    void setPosition(const Vector2& newPosition) { position_ = newPosition; }
    void setSize(const Vector2& newSize) { size_ = newSize; }

    void onClick();
    void onRelease();

    // Converts image from path to the Texture2D. todo: make it private and auto
    void makeTexture();
    // Use in raylib drawing mode! Draws pet on the screen with proper settings.
    void draw();


    void loadAllTextures();

    void secret();
private:
    int clickCount_;

    PetState state_ = PetState::center;

    std::map<PetState, std::string> spritePathMap_;
    std::map<PetState, Texture2D> textureMap_;

    Texture2D texture_;

    Vector2 position_;
    Vector2 size_;
};