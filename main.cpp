#include <raylib.h>

#include "pet.hpp"

int main() {
    InitWindow(256, 256, "Desk Slime");
    SetTargetFPS(60);

    Pet pet;

    pet.setSize({128, 128});
    pet.setPosition({64, 124});
    pet.setAnimationIdlePath("./sprites/static.png");
    pet.setState(PetState::idle);

    pet.makeTexture();

    Texture2D bg = LoadTexture("./sprites/background.png");
    bg.height = 256;
    bg.width = 256;

    while(!WindowShouldClose()) {
        
        
        BeginDrawing();
        ClearBackground(YELLOW);
        DrawTexture(bg, 0, 0, WHITE);
        pet.draw();

        EndDrawing();
    }

    CloseWindow();
}