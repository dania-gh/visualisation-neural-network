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
    matrix* input_normalise_test = createMatrix(267, 8);
    matrix* output_test = createMatrix(267, 1);
    matrix* output_test_predect = createMatrix(267, 1);

    matrix* input_normalise_training = createMatrix(500 , 8);
    matrix* output_training = createMatrix(500, 1);
    matrix* output_training_predect = createMatrix(500,1);

    creat_input_normalise_test_Y_Z_W(input_normalise_test, output_test,input_normalise_training , output_training );

    Parameters* params = initialisation(8, 1, 10, 4);

    load_weight_bias(params, "weight.csv", "bias.csv");

    for (int i = 0; i < 267; i++)
    {
        

        matrix* input_normalise_test_sample  = createMatrix(8, 1);
        input_normalise_test_sample->values[0][0]=input_normalise_test->values[i][0];
        input_normalise_test_sample->values[1][0]=input_normalise_test->values[i][1];
        input_normalise_test_sample->values[2][0]=input_normalise_test->values[i][2];
        input_normalise_test_sample->values[3][0]=input_normalise_test->values[i][3];
        input_normalise_test_sample->values[4][0]=input_normalise_test->values[i][4];
        input_normalise_test_sample->values[5][0]=input_normalise_test->values[i][5];
        input_normalise_test_sample->values[6][0]=input_normalise_test->values[i][6];
        input_normalise_test_sample->values[7][0]=input_normalise_test->values[i][7];

        activation* activations = sigmoid(input_normalise_test_sample, params);

        matrix* output = activations->activ[params->num_layers - 1];

        output_test_predect->values=output->values;
    }


    for (int i = 0; i < 500; i++)
    {
        matrix* input_normalise_training_sample = createMatrix(8,1);
        input_normalise_training_sample->values[0][0]=input_normalise_training->values[i][0];
        input_normalise_training_sample->values[1][0]=input_normalise_training->values[i][1];
        input_normalise_training_sample->values[2][0]=input_normalise_training->values[i][2];
        input_normalise_training_sample->values[3][0]=input_normalise_training->values[i][3];
        input_normalise_training_sample->values[4][0]=input_normalise_training->values[i][4];
        input_normalise_training_sample->values[5][0]=input_normalise_training->values[i][5];
        input_normalise_training_sample->values[6][0]=input_normalise_training->values[i][6];
        input_normalise_training_sample->values[7][0]=input_normalise_training->values[i][7];

        activation* activations = sigmoid(input_normalise_training_sample, params);

        matrix* output = activations->activ[params->num_layers - 1];
        
        output_training_predect->values=output->values;
    }



    return 0;
}


/*printf("Entrées : %.1f, %.1f | Sortie calculée : %.2f | Sortie attendue : %.1f\n",
        input_normalise_test->values[i][0], input_normalise_test->values[i][1], output->values[0][0], output_test->values[i][0]);*/