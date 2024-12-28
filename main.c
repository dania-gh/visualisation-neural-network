#include <stdio.h>
#include <stdlib.h>

#include "convert.h"
#include "matrice.h"
#include "initialisation.h"
#include "activation.h"
#include "back_propagation.h"
#include "save.h"

const double learning_rate = 0.1;
const int epochs = 10000;




int main() {
    srand(time(NULL));

    matrix* X = createMatrix(100, 2);
    matrix* Y = createMatrix(100, 1);
    creat_X_Y(X, Y);

    Parameters* params = initialisation(2, 1, 4, 2);

    

    

    for (int epoch = 0; epoch < epochs; epoch++) 
    {
        double total_log_loss = 0.0;
        

        

        for (int i = 0; i < 100; i++) {


            matrix* x_sample=createMatrix(2,1);
            x_sample->values[0][0]=X->values[i][0];
            x_sample->values[1][0]=X->values[i][1];

           

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

        if (epoch % 1000 == 0) {
            printf("Epoch %d, Log Loss moyen : %.4f\n", epoch, total_log_loss / 100);
        }
          
    }

    save_weight_bias(params, "weight_bias_model.csv");

    printf("\nRésultats après entraînement :\n");

    for (int i = 0; i < 100; i++) {
        
        matrix* x_sample = createMatrix(2, 1);
        x_sample->values[0][0] = X->values[i][0];
        x_sample->values[1][0] = X->values[i][1];

        activation* activations = sigmoid(x_sample, params);

        matrix* output = activations->activ[params->num_layers - 1];


        printf("Entrées : %.1f, %.1f | Sortie calculée : %.2f | Sortie attendue : %.1f\n",
            X->values[i][0], X->values[i][1], output->values[0][0], Y->values[i][0]);

    }


    return 0;
}
