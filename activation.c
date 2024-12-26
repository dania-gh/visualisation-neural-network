#include "activation.h"



activation* segmoid (matrix* x, Parameters* p)
{
    activation* A = (activation*) malloc(p->num_layers * sizeof(activation));

    A->nb_layers = p->num_layers;
    
    A->activ = (matrix*) malloc(A->nb_layers * sizeof(matrix));
    
    for (int i = 0; i < p->num_layers ; i++)
    {
        if(i==0)
        {
            matrix* z = dot(p->weight[i],x);
            z = addition(z,p->bias[i]);
        }
        else 
        {
            matrix* z = dot(p->weight[i],A->activ[i-1]);
            z = addition(z,p->bias[i]);
        }

        

    }

}