#ifndef initialisation_h
#define initialisation_h

#include<stdio.h>
#include<stdlib.h>
#include "matrice.h"

typedef struct {
    matrix** weight;  
    matrix** bias;  
    int num_layers;  
} Parameters;

Parameters* initialisation(int nb_x, int nb_y, int nb_node, int before_end,int nb_layers);

#endif