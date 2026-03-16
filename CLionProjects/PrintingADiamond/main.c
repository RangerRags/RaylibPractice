#include <stdio.h>
#include "PrintingADiamondFunctions.h"
int main(void) {
    int x;
    printf("How tall?\n");
    scanf("%d", &x);
    printDiamond(x);
    return 0;
}