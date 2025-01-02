#include "load.h"

void load_weight_bias(Parameters* params, const char* fichier_poids, const char* fichier_bias)
 {
    FILE* poids_file = fopen(fichier_poids, "r");
    FILE* bias_file = fopen(fichier_bias, "r");

    if (!poids_file || !bias_file) 
    {
        printf("Erreur : Impossible d'ouvrir les fichiers poids ou biais.\n");
        exit(1);
    }

    
    for (int i = 0; i < params->num_layers; i++) 
    {
        for (int row = 0; row < params->weight[i]->row; row++) {
            for (int col = 0; col < params->weight[i]->col; col++) {
                fscanf(poids_file, "%lf,", &params->weight[i]->values[row][col]);
            }
        }
    }

    
    for (int i = 0; i < params->num_layers; i++) 
    {
        for (int row = 0; row < params->bias[i]->row; row++)
        {
            fscanf(bias_file, "%lf,", &params->bias[i]->values[row][0]);
        }
    }

    fclose(poids_file);
    fclose(bias_file);
}
