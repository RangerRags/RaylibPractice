#include "raylib.h"

int main(void) {
    InitWindow(1000,1000,"Window");
    int x=50,y=850;
    int gameWon = 0;
    SetTargetFPS(60);
    int lastDirection = 0;
    int currentMaze = 1;
    Camera2D camera = {0};
    camera.target = (Vector2){x, y};    // what the camera follows
    camera.offset = (Vector2){500, 500}; // center of screen
    camera.zoom = 1.0f;
    Texture2D wallTexture = LoadTexture("purpleBrick.png");
    Texture2D guyUP = LoadTexture("guyUP.png");
    Texture2D guyDOWN = LoadTexture("guyDOWN.png");
    Texture2D guyLEFT = LoadTexture("guyLEFT.png");
    Texture2D guyRIGHT = LoadTexture("guyRIGHT.png");
    int maze[10][10] = {
        {1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,1,0,0,0,0,1},
        {1,0,1,0,0,0,1,0,1,1},
        {1,0,1,1,1,0,1,0,0,1},
        {1,0,0,0,1,0,0,1,0,1},
        {1,1,1,0,1,1,0,1,0,1},
        {1,0,0,0,0,1,0,1,0,1},
        {1,0,1,1,0,1,1,1,0,1},
        {0,0,0,1,0,0,0,1,0,0},
        {1,1,1,1,1,1,1,1,1,1}
    };
    int maze2[10][10] = {
        {1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,1,1,1,1,1,1,0,1},
        {1,0,1,0,0,0,0,1,0,1},
        {1,0,1,0,1,1,0,1,0,1},
        {1,0,0,0,1,0,0,0,0,1},
        {1,1,1,0,1,0,1,1,0,1},
        {1,0,0,0,1,0,1,0,0,1},
        {0,0,1,1,1,0,0,0,0,0},
        {1,1,1,1,1,1,1,1,1,1}
    };
    while (!WindowShouldClose()) {
        if (x<=-1) {
            x=0;
            y=850;
        }
       /* if (x>=1000) {
            x=0;
        }
        if (x<=-1) {
            x=1000;
        }
        if (y>=1000) {
            y=0;
        }
        if (y<=-1) {
            y=1000;
        }
        */
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
       /* if (x < 400) {
            if (y + 20 > 300 && y+20 <320 ) {
                y = 280;  // coming from above, push up
            }
            if (y - 20 < 300 && y-20 > 280) {
                y = 320;  // coming from below, push down
            }
        }
*/
        if (x >= 1000 && currentMaze == 1) {
            currentMaze = 2;
            x = 50; y = 850;
        }
        if (x >= 1000 && currentMaze == 2) {
            gameWon = 1;
        }
        int (*activeMaze)[10] = (currentMaze == 1) ? maze : maze2;
            for (int row = 0; row < 10; row++) {
                for (int col = 0; col < 10; col++) {
                    if (activeMaze[row][col] == 1) {
                        int wallX= col * 100;
                        int wallY = row * 100;

                        if (x + 30 > wallX && x - 30 < wallX + 100 &&
     y + 30 > wallY && y - 30 < wallY + 100) {

                            int overlapLeft   = (x + 30) - wallX;
                            int overlapRight  = (wallX + 100) - (x - 30);
                            int overlapTop    = (y + 30) - wallY;
                            int overlapBottom = (wallY + 100) - (y - 30);

                            int minOverlap = overlapLeft;
                            if (overlapRight < minOverlap)  minOverlap = overlapRight;
                            if (overlapTop < minOverlap)    minOverlap = overlapTop;
                            if (overlapBottom < minOverlap) minOverlap = overlapBottom;

                            if (minOverlap == overlapLeft)       x = wallX - 30;
                            else if (minOverlap == overlapRight) x = wallX + 100 + 30;
                            else if (minOverlap == overlapTop)   y = wallY - 30;
                            else                                 y = wallY + 100 + 30;
                            }
                    }
                }
            }
        BeginDrawing();
        ClearBackground(BLACK);
        BeginMode2D(camera);

      for (int row = 0; row < 10; row++) {
          for (int col = 0; col < 10; col++) {
              if (activeMaze[row][col] == 1) {
                  Rectangle dest = {col * 100, row * 100, 100, 100};
                  Rectangle source = {0, 0, wallTexture.width, wallTexture.height};
                  DrawTexturePro(wallTexture, source, dest, (Vector2){0, 0}, 0, WHITE);
              }
          }
      }
        if (gameWon) {
            DrawText("YOU WIN!!", 200, 400, 100, GREEN);
            camera.target = (Vector2){500, 500};
        } else {
            if (IsKeyDown(KEY_D)) lastDirection = 3;
            else if (IsKeyDown(KEY_A)) lastDirection = 2;
            else if (IsKeyDown(KEY_S)) lastDirection = 0;
            else if (IsKeyDown(KEY_W)) lastDirection = 1;

            Texture2D *currentTexture;
            if (lastDirection == 0) currentTexture = &guyDOWN;
            else if (lastDirection == 1) currentTexture = &guyUP;
            else if (lastDirection == 2) currentTexture = &guyLEFT;
            else currentTexture = &guyRIGHT;

            Rectangle source = {0, 0, currentTexture->width, currentTexture->height};
            Rectangle dest = {x - 30, y - 30, 60, 60};
            DrawTexturePro(*currentTexture, source, dest, (Vector2){0, 0}, 0, WHITE);
            camera.target = (Vector2){x, y};
        }

        DrawText(TextFormat("x: %d y: %d", x, y), 10, 10, 20, GREEN);
       // DrawLine(0,300,400,300,RED);
       // DrawLine(500,0,500,800,RED);
        EndMode2D();
        EndDrawing();
    }
    UnloadTexture(wallTexture);
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