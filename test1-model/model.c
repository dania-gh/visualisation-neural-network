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
            int actual = (int)output_test->values[i][0];
            int predicted ;
            if (output_test_predect->values[i][0] >= 0.5)
            {
                predicted =1;
            }
            else
            {
                predicted =0;
            }
            

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

void copyPredictions(matrix* output, matrix* output_test_predect) {
    if (output_test_predect->row != output->row || output_test_predect->col != 1) {
        printf("Erreur : Dimensions incompatibles entre les matrices.\n");
        return;
    }

    for (int i = 0; i < output_test_predect->row; i++) {
        output_test_predect->values[i][0] = output->values[i][0]; // Copie la première colonne
    }
}

void freeActivations(activation* activations) {
    for (int i = 0; i < activations->nb_layers; i++) {
        freeMatrix(activations->activ[i]);
    }
    free(activations->activ);  
    free(activations);         
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

    for (int i = 0; i < 267; i++) {
        matrix* input_normalise_test_sample = createMatrix(8, 1);
        for (int j = 0; j < 8; j++) {
            input_normalise_test_sample->values[j][0] = input_normalise_test->values[i][j];
        }

        activation* activations = sigmoid(input_normalise_test_sample, params);
        matrix* output = activations->activ[params->num_layers - 1];

        output_test_predect->values[i][0] = output->values[0][0];

        freeMatrix(input_normalise_test_sample);
        freeActivations(activations); 
    }
    

    int TP, TN, FP, FN;
    confusion_matrix(output_test, output_test_predect, &TP, &TN, &FP, &FN);
    printf("Matrice de confusion of input data test  :\n");
    printf("TP = %d, TN = %d, FP = %d, FN = %d\n", TP, TN, FP, FN);

    for (int i = 0; i < 500; i++) {
        matrix* input_normalise_training_sample = createMatrix(8, 1);
        for (int j = 0; j < 8; j++) {
            input_normalise_training_sample->values[j][0] = input_normalise_training->values[i][j];
        }

        activation* activations = sigmoid(input_normalise_training_sample, params);
        matrix* output = activations->activ[params->num_layers - 1];

        output_training_predect->values[i][0] = output->values[0][0];

        freeMatrix(input_normalise_training_sample);
        freeActivations(activations);
    }

    printf("\n");
    printf("\n");
    printf("\n");

    confusion_matrix(output_training, output_training_predect, &TP, &TN, &FP, &FN);
    printf("Matrice de confusion of input data training  :\n");
    printf("TP = %d, TN = %d, FP = %d, FN = %d\n", TP, TN, FP, FN);

    freeMatrix(input_normalise_test);
    freeMatrix(output_test);
    freeMatrix(output_test_predect);
    freeMatrix(input_normalise_training);
    freeMatrix(output_training);
    freeMatrix(output_training_predect);
    


    

    return 0;
}


/*printf("Entrées : %.1f, %.1f | Sortie calculée : %.2f | Sortie attendue : %.1f\n",
        input_normalise_test->values[i][0], input_normalise_test->values[i][1], output->values[0][0], output_test->values[i][0]);*/







