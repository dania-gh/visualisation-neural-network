#ifndef EVALUATIO_H
#define EVALUATIO_H

#include"stdio.h"
#include"matrice.h"

void confusion_matrix(matrix* output_test, matrix* output_test_predect , int *TP, int *TN, int *FP, int *FN);
double accuracy(int TP, int TN, int FP, int FN);
double precision(int TP, int FP);
double recall(int TP, int FN);
#endif