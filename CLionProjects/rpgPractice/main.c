#include <stdio.h>
#include "raylib.h"
#include "rpgFunctions.h"

int main(void) {
    int x=0,y=0;
    Camera2D camera = {0};
    camera.target = (Vector2){x, y};    // what the camera follows
    camera.offset = (Vector2){500, 500}; // center of screen
    camera.zoom = 1.0f;
int overWorld[100][100]={};
    for(int i=0;i<100;i++) {
        overWorld[0][i]=1;
        overWorld[99][i]=1;
        overWorld[i][0]=1;
        overWorld[i][99]=1;
    }
    SetTargetFPS(60);


    InitWindow(1000,1000,"RPG");
    while (!WindowShouldClose()) {
        BeginDrawing();
        BeginMode2D(camera);
        ClearBackground(RAYWHITE);
        for (int i=0;i<100;i++) {
            for (int j=0;j<100;j++) {
                if (overWorld[i][j]==1) {
                    DrawRectangle(i*100,j*100,100,100,BLACK);
                }
            }
        }
         x= characterMovementX(x);
         y= characterMovementY(y);
        DrawCircle(x,y,50,BLACK);
        camera.target = (Vector2){x, y};

        EndDrawing();
    }
    CloseWindow();

    return 0;
}
