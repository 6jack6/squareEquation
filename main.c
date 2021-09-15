#include "sqFunc.h"

int main() {
    int currentMode = 0;
    printf("Enter 0 for testing mode or 1 for working mode\n");

    int flag = 1;
    while(flag == 1) {
        scanf("%d", &currentMode);
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
                flag = 1;
                break;
        }
    }
}

