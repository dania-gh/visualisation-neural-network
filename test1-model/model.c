#include <stdio.h>
#include <stdlib.h>

#include "convert.h"
#include "matrice.h"
#include "initialisation.h"
#include "activation.h"
#include "back_propagation.h"
#include "load.h"
#include "save.h"
#include "evaluation.h"


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


    int TP, TN, FP, FN;
    double accur;
    double preci;
    double rec;
    double f1;



    confusion_matrix(output_test, output_test_predect, &TP, &TN, &FP, &FN);
    accur=accuracy(TP ,TN, FP, FN);
    preci=precision(TP,FP);
    rec=recall(TP,FN);
    f1=f1_score(preci,rec);
    printf("evaluation of data tests: \n "); 
    printf("Matrice de confusion :\n");
    printf("TP = %d, TN = %d, FP = %d, FN = %d\n", TP, TN, FP, FN);
    printf("Acurancy = %f\n", accur);
    printf("Precision = %f\n",preci);
    printf("Recall = %f\n",rec);
    printf("F1_score = %f\n",f1);


    printf("\n");
    printf("\n");
    printf("\n");

    confusion_matrix(output_training, output_training_predect, &TP, &TN, &FP, &FN);
    accur=accuracy(TP ,TN, FP, FN);
    preci=precision(TP,FP);
    rec=recall(TP,FN);
    f1=f1_score(preci,rec);
    printf("evaluation of data training: \n "); 
    printf("Matrice de confusion  :\n");
    printf("TP = %d, TN = %d, FP = %d, FN = %d\n", TP, TN, FP, FN);
    printf("Acurancy = %f\n", accur);
    printf("Precision = %f\n",preci);
    printf("Recall = %f\n",rec);
    printf("F1_score = %f\n",f1);





    freeMatrix(input_normalise_test);
    freeMatrix(output_test);
    freeMatrix(output_test_predect);
    freeMatrix(input_normalise_training);
    freeMatrix(output_training);
    freeMatrix(output_training_predect);
    
    return 0;
}







