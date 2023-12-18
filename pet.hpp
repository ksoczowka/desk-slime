#pragma once

#include <raylib.h>
#include <string>

enum class PetState {
    idle = 0,
    clicked = 1
};

class Pet {
public:
    Pet();

    std::string getAnimationIdlePath() { return animationIdlePath_; }
    std::string getAnimationClickedPath() { return animationClickedPath_; }
    PetState getState() { return state_; }
    Vector2 getSize() { return size_; }
    Vector2 getPosition() { return position_; }
    Texture2D getTexture() { return texture_; }
 
    void setAnimationIdlePath(const std::string& newPath) { animationIdlePath_ = newPath; }
    void setAnimationClickedPath(const std::string& newPath) { animationClickedPath_ = newPath; }
    void setState(const PetState& newState) { state_ = newState; }
    void setSize(const Vector2& newSize) { size_ = newSize; }
    void setPosition(const Vector2& newPosition) { position_ = newPosition; }

    bool isValid();
    void makeTexture();
    void draw();


private:
    Vector2 position_;
    Texture2D texture_;
    Vector2 size_;
    PetState state_ = PetState::idle;
    std::string animationIdlePath_;
    std::string animationClickedPath_;
};