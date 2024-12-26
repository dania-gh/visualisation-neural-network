#include <stdio.h>
#include <stdlib.h>

#include "convert.h"
#include "matrice.h"
#include "fonction.h"

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

        for (int i = 0; i < 4; i++)
        {
            matrix* hidden_layer = createMatrix(2, 1);

            for (int h = 0; h < hidden_layer->row; h++) 
           {
                hidden_layer->values[h][0] = sigmoid(X->values[i][0] * hidden_weights->values[h][0] +X->values[i][1] * hidden_weights->values[h][1] + hidden_bias->values[h][0]);
            }

            matrix *output = createMatrix(1,1);

            output->values[0][0] = sigmoid( hidden_layer->values[0][0] * output_weights->values[0][0] +  hidden_layer->values[1][0] * output_weights->values[1][0] +  output_bias->values[0][0]);

            total_log_loss=+-log_loss(Y->values[i][0] ,output->values[0][0]);


            double output_gradient ;
            output_gradient=(output->values[0][0]-Y->values[i][0])*sigmoid_deriv(output->values[0][0]);

            for (int h = 0; h < hidden_layer->row; h++)
            {
                output_weights->values[h][0]-=learning_rate*output_gradient *hidden_layer->values[h][0];
            }

            output_bias->values[0][0] -= learning_rate *output_gradient;

            matrix* hidden_gradient= createMatrix(2,1);

            for (int h = 0; h < hidden_gradient->row; h++)
            {
                hidden_gradient->values[h][0] =output_gradient * output_weights->values[h][0] * sigmoid_deriv(hidden_layer->values[h][0]) ;

                
            }


            

        }
    } 
    

}