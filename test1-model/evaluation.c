#include "evaluation.h"

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

double accuracy(int TP, int TN, int FP, int FN) {
    double total = TP + TN + FP + FN;
    return (TP + TN) / total;
}
