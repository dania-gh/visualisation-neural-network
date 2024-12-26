#include <stdio.h>
#include <stdlib.h>

#include "convert.h"
#include "matrice.h"

const double learning_rate = 0.1;
const int epochs = 10000;
void printMatrix(matrix* m) {
    for (int i = 0; i < m->row; i++) {
        for (int j = 0; j < m->col; j++) {
            printf("Valeur à [%d][%d] : %f\n", i, j, m->values[i][j]);
        }
        printf("\n");
    }
}
int main ()
{
    srand(time(NULL));

    matrix* X = createMatrix(100, 2);
    matrix* Y = createMatrix(100 ,1);
    creat_X_Y(X, Y);
    
    matrix* hidden_weights = createMatrix(2,2);
    matrix_randomize(hidden_weights ,2);
    

    matrix* hidden_bias=createMatrix(2,1);
    matrix_fill(hidden_bias,0);
    

    matrix* output_weights=createMatrix(2,1);
    matrix_randomize(output_weights,1);
   

    matrix* output_bias=createMatrix(1,1);
    matrix_fill(output_bias,0);
    
    

    for (int epoch=0 ; epoch < epochs ; epoch++)
    {
        double total_log_loss = 0.0;

        for (int i=0 ; i <100 ; i++)
        {
            matrix* hiden_layen = createMatrix(2,1);
            
        }
    } 
    

}