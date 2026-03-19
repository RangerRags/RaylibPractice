//
// Created by ziegl on 3/18/2026.
//
#include "raylib.h"
#include "rpgFunctions.h"
int characterMovementX(int x) {
    if (IsKeyDown(KEY_D)) {
        x+=10;
    }
    if (IsKeyDown(KEY_A)) {
        x-=10;
    }
    return x;
}
int characterMovementY(int y) {
    if (IsKeyDown(KEY_S)) {
        y+=10;
    }
    if (IsKeyDown(KEY_W)) {
        y-=10;
    }return y;
}