#ifndef activation_h
#define activation_h


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "matrice.h"
#include "initialisation.h"
#include "operation.h"


typedef struct {
    int nb_layers;
    matrix** activ;
}activation ;

activation* sigmoid (matrix* x, Parameters* p);
matrix* sigmoid_deriv(matrix* a);
double log_loss(double expected, double predicted);

#endif