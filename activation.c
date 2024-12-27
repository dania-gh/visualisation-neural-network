#include "activation.h"



activation* segmoid (matrix* x, Parameters* p)
{
    if (x == NULL || p == NULL) {
        fprintf(stderr, "Error: NULL input to segmoid function.\n");
        return NULL;
    }
    
    activation* A = (activation*) malloc(p->num_layers * sizeof(activation));

    if (A == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for activation struct.\n");
        return NULL;
    }


    A->nb_layers = p->num_layers;
    
    A->activ = (matrix**) malloc(A->nb_layers * sizeof(matrix));
    

     A->activ = (matrix**)malloc(A->nb_layers * sizeof(matrix*));
    if (A->activ == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for activation layers.\n");
        free(A); 
        return NULL;
    }

    
    for (int i = 0; i < p->num_layers ; i++)
    {
        matrix* z;
        if(i==0)
        {
            z = dot(p->weight[i],x);
        }
        else 
        {
            z = dot(p->weight[i],A->activ[i-1]);
            
        }
        z = addition(z,p->bias[i]);

        A->activ[i]=inverse(add_scaler(matrix_exp(multi_scaler(z ,-1)),1));
        
        freeMatrix(z);

    }
    return A;

}