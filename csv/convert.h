#ifndef CONVERT_H
#define CONVERT_H
#include"stdio.h"
#include"stdlib.h"

void matrix_csv(const char *filename,int cols, int lin, float mat[lin][cols]);
void creat_X_Y(float X[100][2], float y[100][1]);

#endif