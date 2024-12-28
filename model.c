#include <stdio.h>
#include <stdlib.h>

#include "convert.h"
#include "matrice.h"
#include "initialisation.h"
#include "activation.h"
#include "back_propagation.h"
#include "save.h"
#include "load.h"

matrix* predict(matrix* x_sample, Parameters* params) {
    activation* activations = sigmoid(x_sample, params);
    return activations->activ[params->num_layers - 1]; 
}
int main ()
{
    
    Parameters* params = initialisation(2, 1, 4, 2);

    load_weight_bias(params, "weight.csv", "bias.csv");

    matrix* nouvelle_entree = createMatrix(2, 1);
    nouvelle_entree->values[0][0] = 0.7; 
    nouvelle_entree->values[1][0] = 0.2; 

    matrix* sortie = predict(nouvelle_entree, params);

    printf("Entrées : %.2f, %.2f | Sortie prédite : %.2f\n", 
        nouvelle_entree->values[0][0], nouvelle_entree->values[1][0], sortie->values[0][0]);

    if (sortie->values[0][0] > 0.5) {
        printf("La plante est toxique.\n");
    } else {
        printf("La plante n'est pas toxique.\n");
    }

    return 0;

}