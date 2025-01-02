#include <stdio.h>
#include <stdlib.h>

#include "convert.h"
#include "matrice.h"
#include "initialisation.h"
#include "activation.h"
#include "back_propagation.h"
#include "load.h"
#include "save.h"


void confusion_matrix(matrix* output_test, matrix* output_test_predect , int *TP, int *TN, int *FP, int *FN) {
    *TP = *TN = *FP = *FN = 0; 

    if (output_test->row != output_test_predect->row || output_test->col != output_test_predect->col) {
        printf("Erreur : Les matrices doivent avoir les mêmes dimensions.\n");
        return;
    }

    for (int i = 0; i < output_test->row; i++) {
        for (int j = 0; j < 1; j++) {
            double actual = (double)output_test->values[i][0];
            double predicted = (double)output_test_predect->values[i][0];

            if (actual == 1 && predicted == 1) {
                (*TP)++;
            } else if (actual == 0 && predicted == 0) {
                (*TN)++;
            } else if (actual == 0 && predicted == 1) {
                (*FP)++;
            } else if (actual == 1 && predicted == 0) {
                (*FN)++;
            }
        }
    }
}



int main ()
{
    matrix* input_normalise_test = createMatrix(267, 8);
    matrix* output_test = createMatrix(267, 1);
    matrix* output_test_predect = createMatrix(267, 1);

    matrix* input_normalise_training = createMatrix(500 , 8);
    matrix* output_training = createMatrix(500, 1);
    matrix* output_training_predect = createMatrix(500,1);

    creat_X_Y_Z_W(input_normalise_test, output_test,input_normalise_training , output_training );

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

        matrix* output =activations->activ[params->num_layers - 1];


    }

    int TP, TN, FP, FN;
    confusion_matrix(output_test , output_test_predect ,&TP, &TN, &FP, &FN);
    printf("Matrice de confusion :\n");
    printf("TP = %d, TN = %d, FP = %d, FN = %d\n", TP, TN, FP, FN);



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