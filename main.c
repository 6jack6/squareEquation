#include "sqFunc.h"

int main() {
    int currentMode = 0;
    printf("Enter 0 for testing mode or 1 for working mode\n");

    while(1) {
        while(scanf("%d", &currentMode) != 1) {
            while (getchar() != '\n') continue;
            printf("Inappropriate data. Please, repeat\n");
        }
        switch(currentMode) {
            case 0:
                return testing();
            case 1: {
                double a = 0, b = 0, c = 0;
                enterData(&a, &b, &c);
                return answPrint(a, b, c);
            }
            default :
                printf("Wrong request, please, repeat\n");
                break;
        }
    }
}

