#include <stdio.h>
#include <stdlib.h>

#include "convert.h"
#include "matrice.h"
#include "initialisation.h"
#include "activation.h"
#include "back_propagation.h"
#include "load.h"

matrix* predict(matrix* x_sample, Parameters* params) {
    activation* activations = sigmoid(x_sample, params);
    return activations->activ[params->num_layers - 1]; 
}
int main ()
{
    
    Parameters* params = initialisation(8, 1, 10, 5);

    load_weight_bias(params, "../model_neural/weight.csv", "../model_neural/bias.csv");

    matrix* nouvelle_entree = createMatrix(8, 1);
    nouvelle_entree->values[0][0] = 1; 
    nouvelle_entree->values[1][0] = 103; 
    nouvelle_entree->values[2][0] = 30;
    nouvelle_entree->values[3][0] = 38;
    nouvelle_entree->values[4][0] = 83;
    nouvelle_entree->values[5][0] = 43.3;
    nouvelle_entree->values[6][0] = 0.183;
    nouvelle_entree->values[7][0] = 33;


    matrix* sortie = predict(nouvelle_entree, params);

    printf("Entrées : %.2f, %.2f | Sortie prédite : %.2f\n", 
        nouvelle_entree->values[0][0], nouvelle_entree->values[1][0], sortie->values[0][0]);

    if (sortie->values[0][0] > 0.5) {
        printf("Cette femme est  diabétique.\n");
    } else {
        printf("Cette femme n'est pas diabétique.\n");
    }

    return 0;

}