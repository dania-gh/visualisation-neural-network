#ifndef CONVERT_H
#define CONVERT_H
#include"stdio.h"
#include"stdlib.h"
#include"matrice.h"

void matrix_csv(const char *filename,int cols, int lin, matrix* mat);
void creat_X_Y(matrix* X, matrix* Y);

#endif