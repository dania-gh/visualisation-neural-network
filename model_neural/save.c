#include "save.h"

void save_data(Parameters* params, const char* fichier_poids, const char* fichier_bias)
{
   
    FILE* f_poids = fopen(fichier_poids, "w");
    if (f_poids == NULL) 
    {
        printf("Erreur : impossible d'ouvrir le fichier pour les poids.\n");
        return;
    }

    
    for (int i = 0; i < params->num_layers; i++) 
    {
        for (int r = 0; r < params->weight[i]->row; r++)
        {
            for (int c = 0; c < params->weight[i]->col; c++)
            {
                fprintf(f_poids, "%lf", params->weight[i]->values[r][c]);
                if (c < params->weight[i]->col - 1) fprintf(f_poids, ","); 
            }

            fprintf(f_poids, "\n");
        }
    }
    fclose(f_poids);

    
    FILE* f_bias = fopen(fichier_bias, "w");
    if (f_bias == NULL) 
    {
        printf("Erreur : impossible d'ouvrir le fichier pour les biais.\n");
        return;
    }

    
    for (int i = 0; i < params->num_layers; i++) 
    {
        for (int r = 0; r < params->bias[i]->row; r++) 
        {
            for (int c = 0; c < params->bias[i]->col; c++) 
            {
                fprintf(f_bias, "%lf", params->bias[i]->values[r][c]);
                if (c < params->bias[i]->col - 1) fprintf(f_bias, ","); 
            }
            fprintf(f_bias, "\n");
        }
    }

    fclose(f_bias);
}
