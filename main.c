#include "raylib.h"

int main(void) {
    InitWindow(1000,1000,"Window");
    int x=50,y=850;
    int gameWon = 0;
    SetTargetFPS(60);
    int currentMaze = 1;
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

                        if (x + 20 > wallX && x - 20 < wallX + 100 &&
                            y + 20 > wallY && y - 20 < wallY + 100) {

                            int overlapLeft  = (x + 20) - wallX;
                            int overlapRight = (wallX + 100) - (x - 20);
                            int overlapTop   = (y + 20) - wallY;
                            int overlapBottom= (wallY + 100) - (y - 20);

                            int minOverlap = overlapLeft;
                            if (overlapRight < minOverlap)  minOverlap = overlapRight;
                            if (overlapTop < minOverlap)    minOverlap = overlapTop;
                            if (overlapBottom < minOverlap) minOverlap = overlapBottom;

                            if (minOverlap == overlapLeft)       x = wallX - 20;
                            else if (minOverlap == overlapRight) x = wallX + 100 + 20;
                            else if (minOverlap == overlapTop)   y = wallY - 20;
                            else                                 y = wallY + 100 + 20;
                            }
                    }
                }
            }

        // in logic section



        BeginDrawing();
        ClearBackground(RAYWHITE);

  if (currentMaze==1) {
      for (int row = 0; row < 10; row++) {
          for (int col = 0; col < 10; col++) {
              if (maze[row][col] == 1) {
                  DrawRectangle(col * 100, row * 100, 90, 90, BLACK);
              }
          }
      }
  }
   else if (currentMaze==2) {
       if (currentMaze == 2 && x < 1000) {
           for (int row = 0; row < 10; row++) {
               for (int col = 0; col < 10; col++) {
                   if (maze2[row][col] == 1) {
                       DrawRectangle(col * 100, row * 100, 90, 90, BLACK);
                   }
               }
           }
       }
   }
        if (gameWon) {
            DrawText("YOU WIN!!", 200, 400, 100, GREEN);
        } else {
            // all your normal drawing code
            DrawCircle(x, y, 20, BLACK);
            // draw maze etc
        }
        DrawText(TextFormat("x: %d y: %d", x, y), 10, 10, 20, GREEN);
       // DrawLine(0,300,400,300,RED);
       // DrawLine(500,0,500,800,RED);
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