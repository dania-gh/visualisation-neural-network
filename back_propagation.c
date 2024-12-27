#include "back_propagation.h"


gradient* back_propagation(matrix* x, matrix* y, Parameters* p, activation* A)
{
    int m = y->col;

    gradient* g = (gradient*)malloc(sizeof(gradient));

    g->nb_layers = p->num_layers;

    g->grad = (matrix**)malloc(g->nb_layers* sizeof(matrix));
    
}