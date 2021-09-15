//
// Created by Asus on 10.09.2021.
//

#include "sqFunc.h"

int answPrint (double a, double b, double c) {
    double x1 = 0, x2 = 0;
    int answers = 0;
    answers = squareEquationRootsNum(a, b, c, &x1, &x2);

    switch(answers) {
        case 0:
            printf("No roots");
            break;
        case 1:
            printf("The only root is %lg", x1);
            break;
        case 2:
            printf("The first root is %lg, the second root is %lg", x1, x2);
            break;
        case infRoots:
            printf("Any answer");
            break;
        default:
            printf("The number of roots cannot be defined");
            return rootsDefiningError;
    }
    return 0;
}

void enterData (double *a, double *b, double *c) {
    enterCoefficient(&a, 'a');
    enterCoefficient(&b, 'b');
    enterCoefficient(&c, 'c');
}

void enterCoefficient (double *coef, char name) {
    printf("Enter %c\n", &name);
    scanf("%lg", &coef);
}

int squareEquationRootsNum (double a, double b, double c, double *x1, double *x2) {
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    double d = 0;
    if(equality(a, 0, Epsilon)) {
        return linearEquationRootsNum(b, c, x1);
    }
    else{
        d = b * b - 4 * a * c;
        if(d < 0) {
            return 0;
        }

        if(equality(d, 0, Epsilon)) {
            *x1 = - b / (2 * a);
            return 1;
        }

        if(d > 0) {//ax^2 + bx = 0; x = 0; ax + b = 0;
            if (equality(c, 0, Epsilon)) {
                *x1 = 0;
                linearEquationRootsNum(a, b, &x2);
                if (*x1 < *x2) {
                    swap(&x1, &x2);
                }
                return 2;
            }
            else {
                d = sqrt(d);
                *x1 = (-b + d) / (2 * a);
                *x2 = (-b - d) / (2 * a);
                return 2;
            }
        }
    }
}

int linearEquationRootsNum (double b, double c, double *x1) {
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != NULL);

    if(equality(b, 0, Epsilon)) {
        if (equality(c, 0, Epsilon)) {
            return infRoots;
        }
        return 0;
    }
    /* if(b != 0) */
    *x1 = (-c) / b;
    return 1;
}
//isnan
int equality (double num1, double num2, double accurancy) {
    assert(isfinite(num1));
    assert(isfinite(num2));
    assert(isfinite(accurancy));

    return fabs(num1 - num2) <= accurancy;
}

void swap (double *num1, double *num2) {
    double tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}