#ifndef initialisation_h
#define initialisation_h

#include<stdio.h>
#include<stdlib.h>
#include "matrice.h"

typedef struct {
    matrix** w;  
    matrix** b;  
    int num_layers;  
} Parameters;

#endif