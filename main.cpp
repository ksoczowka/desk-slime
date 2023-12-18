#include <map>
#include <raylib.h>

#include "pet.hpp"

#include <iostream>
int main() {
    InitWindow(256, 256, "Desk Slime");
    SetTargetFPS(60);

    std::map<PetState, std::string> spritePaths = {
        {PetState::center, "./sprites/center.png"},
        {PetState::left, "./sprites/left.png"},
        {PetState::right, "./sprites/right.png"},
        {PetState::up, "./sprites/up.png"},
        {PetState::down, "./sprites/down.png"},
        {PetState::upLeft, "./sprites/up-left.png"},
        {PetState::upRight, "./sprites/up-right.png"},
        {PetState::downLeft, "./sprites/down-left.png"},
        {PetState::downRight, "./sprites/down-right.png"}
    };

    Pet pet;

    pet.setSize({128, 128});
    pet.setPosition({64, 64});
    pet.setSpritePathMap(spritePaths);
    
    pet.loadAllTextures();
    
    pet.setState(PetState::center);

    // Loading a static background image and resizing it to fill the window
    Texture2D bg = LoadTexture("./sprites/background.png");
    bg.height = 256;
    bg.width = 256;

    while(!WindowShouldClose()) {
        auto mouseX = GetMouseX();
        auto mouseY = GetMouseY();
        if(mouseY < 88) {
            if(mouseX < 72) {
                pet.setState(PetState::upLeft);
            } else if(mouseX > 184) {
                pet.setState(PetState::upRight);
            } else {
                pet.setState(PetState::up);
            }
        } else if(mouseY > 176) {
            if(mouseX < 72) {
                pet.setState(PetState::downLeft);
            } else if(mouseX > 184) {
                pet.setState(PetState::downRight);
            } else {
                pet.setState(PetState::down);
            }
    } else {
        if(mouseX < 72) {
            pet.setState(PetState::left);
        } else if(mouseX > 184) {
            pet.setState(PetState::right);
        } else {
            pet.setState(PetState::center);
        }
    }
        
        BeginDrawing();
        DrawTexture(bg, 0, 0, WHITE);
        pet.draw();

        EndDrawing();
    }

    CloseWindow();
}