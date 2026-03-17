#include "raylib.h"

int main(void) {
    InitWindow(800,800,"Window");
    int x=300,y=350;
    SetTargetFPS(60);
    int maze[10][10]={
        {1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,1,0,1,0,1,1}
    ,{1,0,0,0,1,0,1,0,1,1},
    {1,1,1,1,1,1,1,1,1,1}
    ,{1,0,0,0,1,0,1,0,1,1},
    {1,0,0,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1}
    ,{1,0,0,0,1,0,1,0,1,1}
    ,{1,0,0,0,1,0,1,0,1,1},
    {1,0,1,0,1,0,1,0,1,1}};
    while (!WindowShouldClose()) {

        if (x>=800) {
            x=0;
        }
        if (x<=-1) {
            x=800;
        }
        if (y>=800) {
            y=0;
        }
        if (y<=-1) {
            y=800;
        }
        if (IsKeyDown(KEY_D)) {
            x+=10;
        }
        if (IsKeyDown(KEY_A)) {
            x-=10;
        }

        if (IsKeyDown(KEY_S)) {
            y+=10;
        }
        if (IsKeyDown(KEY_W)) {
            y-=10;
        }
        if (x < 400) {
            if (y + 20 > 300 && y+20 <320 ) {
                y = 280;  // coming from above, push up
            }
            if (y - 20 < 300 && y-20 > 280) {
                y = 320;  // coming from below, push down
            }
        }


        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText(TextFormat("x: %d y: %d", x, y), 10, 10, 20, BLACK);
        //DrawText("Suck My Balls",350,350,20,BLUE);
        DrawLine(0,300,400,300,RED);
       // DrawLine(500,0,500,800,RED);
        DrawCircle(x,y,20,BLACK);
        EndDrawing();
    }
    CloseWindow();





    return 0;
}
























/*{
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
*/