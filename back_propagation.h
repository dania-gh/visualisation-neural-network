#ifndef back_propagation_h
#define back_propagation_h

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "matrice.h"
#include "initialisation.h"
#include "operation.h"
#include "activation.h"

typedef struct{
    int nb_layers;
    matrix** grad;
}gradient;




#endif