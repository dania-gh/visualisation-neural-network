#include "initialisation.h"


Parameters* initialisation(int nb_x,int nb_y, int nb_node, int nb_layers)
{
    Parameters* p= (Parameters*)malloc(sizeof(Parameters));


    p->num_layers = nb_layers;


    p->weight = (matrix**) malloc(nb_layers * sizeof(matrix*));
    p->bias = (matrix**) malloc(nb_layers * sizeof(matrix*));

    for (int i =0 ;i< nb_layers ; i++)
    {
        if(i==0)
        {
            p->weight[i] = createMatrix(nb_layers , nb_x);
        }
        else if(i==nb_layers-1)
        {
            p->weight[i] = createMatrix(nb_layers, nb_layers); 
        }
        else 
        {
            p->weight[i] = createMatrix(nb_y , nb_layers);
        }

        matrix_randomize(p->weight[i], nb_node);


        if (i== nb_layers-1)
        {
            p->bias = createMatrix(nb_y	, 1);
        }
        else 
        {
            p->bias = createMatrix(nb_node , 1);
        }

        matrix_fill(p->bias,0);
    }

    return p;
}