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
void matrix_randomize(matrix* m, int nb_node);
void matrix_fill(matrix* m,int n);
matrix* matrix_copy(matrix* m);
void printMatrix(matrix* m);
void freeMatrix(matrix* m);
void copyPredictions(matrix* output, matrix* output_test_predect);


#endif