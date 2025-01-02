#include <stdio.h>
#include <stdlib.h>

#include "convert.h"
#include "matrice.h"
#include "initialisation.h"
#include "activation.h"
#include "back_propagation.h"
#include "load.h"
#include "save.h"

int main ()
{
    matrix* X = createMatrix(267, 8);
    matrix* Y = createMatrix(267, 1);
    creat_X_Y(X, Y);

    Parameters* params = initialisation(8, 1, 10, 4);

    load_weight_bias(params, "weight.csv", "bias.csv");

    for (int i = 0; i < 267; i++) {
        

        matrix* x_sample = createMatrix(8, 1);
        x_sample->values[0][0]=X->values[i][0];
        x_sample->values[1][0]=X->values[i][1];
        x_sample->values[2][0]=X->values[i][2];
        x_sample->values[3][0]=X->values[i][3];
        x_sample->values[4][0]=X->values[i][4];
        x_sample->values[5][0]=X->values[i][5];
        x_sample->values[6][0]=X->values[i][6];
        x_sample->values[7][0]=X->values[i][7];

        activation* activations = sigmoid(x_sample, params);

        matrix* output = activations->activ[params->num_layers - 1];


    
        printf("Entrées : %.1f, %.1f | Sortie calculée : %.2f | Sortie attendue : %.1f\n",
        X->values[i][0], X->values[i][1], output->values[0][0], Y->values[i][0]);
        

    }

    return 0;
}