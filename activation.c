#include "activation.h"



activation* sigmoid (matrix* x, Parameters* p)
{
    if (x == NULL || p == NULL) {
        fprintf(stderr, "Error: NULL input to segmoid function.\n");
        return NULL;
    }
    
    activation* A = (activation*) malloc(sizeof(activation));

    if (A == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for activation struct.\n");
        return NULL;
    }


    A->nb_layers = p->num_layers;

    
     A->activ = (matrix**)malloc(A->nb_layers * sizeof(matrix*));


    if (A->activ == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for activation layers.\n");
        free(A); 
        return NULL;
    }

    for (int i = 0; i < p->num_layers; i++) 
    {
    matrix* z = NULL;

    if (i == 0) 
    {
        z = dot(p->weight[i], x);  
    }

     else 
    {
        z = dot(p->weight[i], A->activ[i - 1]);  
    }

    z = addition(z, p->bias[i]); 
    matrix* multi = multi_scaler(z, -1);  
    matrix* expo = matrix_exp(multi);  
    matrix* add = add_scaler(expo, 1);   
    A->activ[i] = inverse(add);  
    freeMatrix(add);
    freeMatrix(expo);
    freeMatrix(multi);
    freeMatrix(z);

    }
    return A;
}

matrix* sigmoid_deriv(matrix* a)
{
    matrix* z = createMatrix(a->row,a->col);
    for(int i=0 ; i< a->row; i++)
    {
        for(int j= 0 ; j < a->col ; j++)
        {
            z->values[i][j]=a->values[i][j]*(1-a->values[i][j]);
        }
    }
    return z;
}

double log_loss(double expected, double predicted) 
{
    const double epsilon = 1e-15;
    predicted = fmax(fmin(predicted ,1-epsilon), epsilon);
    return -(expected * log(predicted)+(1-expected)*log(1- predicted));
}