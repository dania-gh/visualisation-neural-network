#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
    double** values;
    int row;
    int col;
} matrix;

matrix* createMatrix(int row, int col);



#endif