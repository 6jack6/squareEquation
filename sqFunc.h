//
// Created by Asus on 10.09.2021.
//

#ifndef UNTITLED2_SQFUNC_H
#define UNTITLED2_SQFUNC_H

#include <stdio.h>
#include <math.h>
#include <assert.h>

#define Epsilon 1e-5

enum {
    infRoots = -1,
    rootsDefiningError = -1,
    testFailed = 1,
};

//---------------------------------------------
//! Prints the answer of the square equation
//!
//! \param [in] a a-coefficient
//! \param [in] b b-coefficient
//! \param [in] c c-coefficient
//!
//! \return The program finishing code
//---------------------------------------------
int answPrint (const double a, const double b, const double c);

//---------------------------------------------
//! Gets the a, b, c-coefficients of the square
//! equation ax^2 + bx + c = 0
//!
//! \param [in] a a-coefficient
//! \param [in] b b-coefficient
//! \param [in] c c-coefficient
//---------------------------------------------
void enterData (double *a, double *b, double *c);

//---------------------------------------------
//! Gets a coefficient with a message for users
//!
//! \param [in] coef Pointer to the coefficient
//! \param [in] name Coefficient`s name
//---------------------------------------------
void enterCoefficient (double *coef, const char name);

//---------------------------------------------
//! Solves a square equation ax^2 + bx + c = 0
//!
//! \param [in] a a-coefficient
//! \param [in] b b-coefficient
//! \param [in] c c-coefficient
//! \param [out] x1 Pointer to the 1st root
//! \param [out] x2 Pointer to the 2nd root
//!
//! \return Number of roots
//!
//! \note In case of infinite number of roots,
//!       returns infRoots.

//---------------------------------------------
int squareEquationRootsNum (const double a, const double b, const double c, double *x1, double *x2);

//---------------------------------------------
//! Solves a linear equation bx + c = 0
//!
//! \param [in] b b-coefficient
//! \param [in] c c-coefficient
//! \param [out] x1 Pointer to the root
//! \return Number of roots
//!
//! \note In case of infinite number of roots,
//!       returns infRoots.
//---------------------------------------------
int linearEquationRootsNum (const double b, const double c, double *x1);

//---------------------------------------------
//! Checks, if two real numbers are equal,
//! considering the accurancy (epsilon)
//!
//! \param [in] num1 1st number
//! \param [in] num2 2nd number
//! \param [in] accurancy Accurancy
//!
//! \return the result of comparison
//---------------------------------------------
int equality (const double num1, const double num2, const double accurancy);

//---------------------------------------------
//! Unit test function
//!
//! \return Program finishing code
//---------------------------------------------
int testing ();

//---------------------------------------------
//! Checks if test is completed correctly
//!
//! \param [in] i Counter of iterations
//! \param [in] a a-coefficient of square equation
//! \param [in] b b-coefficient of square equation
//! \param [in] c c-coefficient of square equation
//! \param [in] rootsNum The right number of roots
//! \param [in] dataX1 The right 1st root
//! \param [in] dataX2 The right 2nd root
//!
//! \return Program finishing code
//---------------------------------------------
int testIsCorrect (const int i, const double a, const double b, const double c,
                   const int rootsNum, const double dataX1, const double dataX2);

//---------------------------------------------
//! Gives a report of test failure
//!
//! \param i Number of test
//! \param x1 Received 1st root
//! \param x2 Received 2nd root
//! \param answers Received number of roots
//! \param rootsNum Right number of roots
//! \param dataX1 Right 1st root
//! \param dataX2 Right 2nd root
//!
//! \return Program finishing code
//---------------------------------------------
int testFailure (const int i, const double x1, const double x2, const int answers,
                 const int rootsNum, const double dataX1, const double dataX2);

//---------------------------------------------
//! Swaps 2 numbers
//!
//! \param [in] num1 1st number
//! \param [in] num2 2nd number
//---------------------------------------------
void swap (double *num1, double *num2);

#endif