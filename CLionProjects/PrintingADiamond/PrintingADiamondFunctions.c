//
// Created by ziegl on 2/23/2026.
//
#include <stdio.h>
#include <stdlib.h>
//prints a diamond to the screen, given a height.
//the actual height of the diamond is (2x - 1)
//where x is the specified height.

#include <stdio.h>
void printDiamond(int height) {
    int totalRows = 2 * height - 1;

    for (int row = 0; row < totalRows; row++) {

        int distFromMiddle = (row < height) ? (height - 1 - row) : (row - height + 1);
        int stars = height - distFromMiddle;
        int ticks = distFromMiddle;


        for (int i = 0; i < ticks; i++) {
            printf("`");
        }

        // Print asterisks
        for (int i = 0; i < 2 * stars - 1; i++) {
            printf("*");
        }

        // Print trailing backticks
        for (int i = 0; i < ticks; i++) {
            printf("`");
        }

        printf("\n");
    }
}

/*
void printDiamond(int height) {
    int diamondHeight = (2*height)-1;
    for (int i = 0; i < diamondHeight/2; i++) {

        for (int j = -(diamondHeight/2); j < (diamondHeight/2)+1; j++) {
         if (abs(j) <= abs(i)) {
             printf("*");
         }
            else {
                printf("'");
            }
        }
        printf("\n");
    }
    for (int i=diamondHeight/2; i>=0; i--) {
        for (int j = -(diamondHeight/2); j < (diamondHeight/2)+1; j++) {
            if (abs(j) <= abs(i)) {
                printf("*");
            }
            else {
                printf("'");
            }
        }
        printf("\n");
    }

}
*/