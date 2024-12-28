#include <stdio.h>
#include <stdlib.h>

#include "convert.h"
#include "matrice.h"
#include "initialisation.h"
#include "activation.h"

const double learning_rate = 0.1;
const int epochs = 10000;

void update_weights(matrix* weights, matrix* gradient, double learning_rate) {
    for (int i = 0; i < weights->row; i++) {
        for (int j = 0; j < weights->col; j++) {
            weights->values[i][j] -= learning_rate * gradient->values[i][j];
        }
    }
}


int main() {
    srand(time(NULL));

    matrix* X = createMatrix(100, 2);
    matrix* Y = createMatrix(100, 1);
    creat_X_Y(X, Y);

    Parameters* params = initialisation(2, 1, 2, 2);

    

    

    for (int epoch = 0; epoch < epochs; epoch++) 
    {
        double total_log_loss = 0.0;
        

        

        for (int i = 0; i < 100; i++) {


            matrix* x_sample=createMatrix(2,1);
            x_sample->values[0][0]=X->values[i][0];
            x_sample->values[1][0]=X->values[i][1];

           

            activation* activations=sigmoid(x_sample,params);
            matrix* output = activations->activ[activations->nb_layers-1];
           
            
            total_log_loss += log_loss(Y->values[i][0], output->values[0][0]);
            

            double output_gradient = (output->values[0][0] - Y->values[i][0]) * sigmoid_deriv(output)->values[0][0];


            matrix* gradient = createMatrix(1, 1);

            gradient->values[0][0] = output_gradient;
            update_weights(params->weight[1], gradient, learning_rate);

            

            params->bias[1]->values[0][0] -= learning_rate * output_gradient;

            matrix* hidden_gradient = createMatrix(2, 1);
            

             for (int h = 0; h < hidden_gradient->row; h++) {
                hidden_gradient->values[h][0] = output_gradient * 
                        params->weight[1]->values[0][h] * 
                        sigmoid_deriv(activations->activ[0])->values[h][0];
            }

            update_weights(params->weight[0], hidden_gradient, learning_rate);
                      
        }

        if (epoch % 1000 == 0) {
            printf("Epoch %d, Log Loss moyen : %.4f\n", epoch, total_log_loss / 100);
        }
          
    }

    printf("\nRésultats après entraînement :\n");

    for (int i = 0; i < 100; i++) {
        
        matrix* x_sample = createMatrix(2, 1);
        x_sample->values[0][0] = X->values[i][0];
        x_sample->values[1][0] = X->values[i][1];

        activation* activations = sigmoid(x_sample, params);

        matrix* output = activations->activ[activations->nb_layers - 1];


        printf("Entrées : %.1f, %.1f | Sortie calculée : %.2f | Sortie attendue : %.1f\n",
            X->values[i][0], X->values[i][1], output->values[0][0], Y->values[i][0]);

    }


    return 0;
}
