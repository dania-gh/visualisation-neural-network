#include <stdio.h>
#include <stdlib.h>

#include "convert.h"
#include "matrice.h"
#include "initialisation.h"
#include "activation.h"
#include "back_propagation.h"
#include "save.h"

const double learning_rate = 0.1;
const int epochs = 500;
Parameters* params;



int main() {
    srand(time(NULL));

    matrix* X = createMatrix(767, 8);
    matrix* Y = createMatrix(767, 1);
    creat_X_Y(X, Y);

    params = initialisation(8, 1, 10, 4);


    for (int epoch = 0; epoch < epochs; epoch++) 
    {
        double total_log_loss = 0.0;
        

        

        for (int i = 0; i < 767; i++) {


            matrix* x_sample=createMatrix(8,1);
            x_sample->values[0][0]=X->values[i][0];
            x_sample->values[1][0]=X->values[i][1];
            x_sample->values[2][0]=X->values[i][2];
            x_sample->values[3][0]=X->values[i][3];
            x_sample->values[4][0]=X->values[i][4];
            x_sample->values[5][0]=X->values[i][5];
            x_sample->values[6][0]=X->values[i][6];
            x_sample->values[7][0]=X->values[i][7];

           

            activation* activations=sigmoid(x_sample,params);
            matrix* output = activations->activ[params->num_layers-1];
           
            
            total_log_loss += log_loss(Y->values[i][0], output->values[0][0]);

            matrix* y_sample=createMatrix(1,1);
            y_sample->values[0][0]=Y->values[i][0];

            gradient* g = back_propagation(x_sample, y_sample, params, activations);

            for (int j = 0; j < params->num_layers; j++) 
            {
                
                update_weights(params->weight[j], g->dw[j], learning_rate);
                
                params->bias[j]->values[0][0] -= learning_rate * g->db[j]->values[0][0];
            }
                      
        }

        
        if (epoch % 10 == 0) 
        {
            printf("Epoch %d, Log Loss moyen : %.4f\n", epoch, total_log_loss / 100);
        }
        
          
    }

    save_weight_bias(params, "weight.csv","bias.csv");

    printf("\nRésultats après entraînement :\n");

    for (int i = 0; i < 767; i++) {
        
        matrix* x_sample = createMatrix(8, 1);
        x_sample->values[0][0]=X->values[i][0];
        x_sample->values[1][0]=X->values[i][1];
        x_sample->values[2][0]=X->values[i][2];
        x_sample->values[3][0]=X->values[i][3];
        x_sample->values[4][0]=X->values[i][4];
        x_sample->values[5][0]=X->values[i][5];
        x_sample->values[6][0]=X->values[i][6];
        x_sample->values[7][0]=X->values[i][7];

        activation* activations = sigmoid(x_sample, params);

        matrix* output = activations->activ[params->num_layers - 1];


        if (i % 10 == 0) {
           printf("Entrées : %.1f, %.1f | Sortie calculée : %.2f | Sortie attendue : %.1f\n",
            X->values[i][0], X->values[i][1], output->values[0][0], Y->values[i][0]);
        }

    }


    return 0;
}
