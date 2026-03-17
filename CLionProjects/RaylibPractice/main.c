#include "raylib.h"

int main(void)
{
    Texture2D Sprite;
    Sound sound;;
    int posX=-Sprite.width;

   InitWindow(800, 600, "raylib window");
   InitAudioDevice();
    Sprite = LoadTexture("snake.png");
    sound = LoadSound("535890__jerimee__coin-jump.wav");
    SetTargetFPS(20);
    while (!WindowShouldClose()) {
        posX += GetFrameTime()*300;
        if (posX > 800) {
            posX = -100;
        }

        Rectangle spriteRect={posX, 200, Sprite.width, Sprite.height};
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            if (CheckCollisionPointRec(GetMousePosition(),spriteRect)) {
                PlaySound(sound);
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(Sprite,posX, 200, BLUE);
        //DrawCircle(posX,10,200,GREEN);
        EndDrawing();
    }
    CloseAudioDevice();
    CloseWindow();

    return 0;
}