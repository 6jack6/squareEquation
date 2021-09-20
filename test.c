//
// Created by Asus on 10.09.2021.
//

#include "sqFunc.h"

struct testData {
    double a;
    double b;
    double c;

    double x1;
    double x2;
    int rootsNum;
};

int testing() {
    struct testData data[] = {
            {1, 4, 4, -2, 0, 1},
            {1, 1, 1, 0, 1, 0},
            {1, -5, 6, 3, 2, 2},
            {0, 0, 0, 0, 0, infRoots},
            {0, 2, 4, -2, 0, 1},
    };

    int n = (sizeof(data)) / (sizeof(data[0]));
    int indic = 0;
    for (int i = 0; i < n; i++) {
        if (testIsCorrect(i, data[i]. a, data[i]. b, data[i]. c,
                          data[i].rootsNum, data[i].x1, data[i].x2) == testFailed) {
            indic = testFailed;
        }
    }
    return indic;
}

int testIsCorrect(const int i, const double a, const double b, const double c,
                  const int rootsNum, const double dataX1, const double dataX2) {
    double x1 = 0, x2 = 0;
    int answers = squareEquationRootsNum(a, b, c, &x1, &x2);

    if((equality(x1, dataX1, Epsilon)) && (equality(x2, dataX2, Epsilon)) && (answers == rootsNum)) {
        printf("Test number %d has been completed correctly\n\n", i + 1);
    }
    else {
        return testFailure(i, x1, x2, answers, rootsNum, dataX1, dataX2);
    }
    return 0;
}

int testFailure (const int i, const double x1, const double x2, const int answers,
                 const int rootsNum, const double dataX1, const double dataX2) {
    printf("Test number %d has been failed:\n\n", i + 1);
    printf("Received answer:\n\n1st root: %lg\n2nd Root: %lg\nNumber of roots: %d\n\n", x1, x2, answers);
    printf("Right answer:\n\n1st root: %lg\n2nd Root: %lg\nNumber of roots: %d\n\n", dataX1, dataX2, rootsNum);
    return testFailed;
}
