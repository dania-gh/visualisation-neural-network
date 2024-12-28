#include "back_propagation.h"


gradient* back_propagation(matrix* x, matrix* y, Parameters* p, activation* A)
{
    int m = y->col;

    gradient* g = (gradient*)malloc(sizeof(gradient));

    g->nb_layers = p->num_layers;

    g->dw= (matrix**)malloc(g->nb_layers* sizeof(matrix));
    g->db= (matrix**)malloc(g->nb_layers* sizeof(matrix));

    
    matrix* dz1;
    matrix* dz2;
    for(int i = p->num_layers-1 ; i>=0 ; i--)
    {
        
        if(i== p->num_layers-1)
        {
            dz2 = subtraction(A->activ[i],y);
        }
        else
        {
            matrix* deriv = sigmoid_deriv(A->activ[i]);
            matrix* trans = transpose(p->weight[i+1]);
            matrix* dott = dot(trans,dz2);
            dz1 = multiplication(dott,deriv);
            freeMatrix(dz2);
            dz2 = copy(dz1);
            freeMatrix(dott);
            freeMatrix(trans);
            freeMatrix(deriv);
            freeMatrix(dz1);
        }
        if(i==0)
        {
            matrix* trans = transpose(x);
            matrix* dott = dot(dz2,trans);
            g->dw[i]= multi_scaler(dott,(1/m));
            freeMatrix(dott);
            freeMatrix(trans);
        }
        else
        {
            matrix* trans = transpose(A->activ[i-1]);
            matrix* dott = dot(dz2,trans);
            g->dw[i]= multi_scaler(dott,(1/m));
            freeMatrix(dott);
            freeMatrix(trans);
        }

        matrix* sumrow = sum_row(dz2);
        g->db[i]=multi_scaler(sumrow,(1/m));
        freeMatrix(sumrow);
    }
    freeMatrix(dz2);
    return g;
}