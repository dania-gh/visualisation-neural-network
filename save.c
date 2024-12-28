#include "save.h"

void save_weight_bias(Parameters* params, const char* fichier)
{
    FILE* f = fopen(fichier, "w");
    if (f == NULL) 
    {
        printf("Erreur lors de l'ouverture du fichier pour sauvegarder en CSV.\n");
        return;
    }

    for (int i = 0; i < params->num_layers; i++) 
    {
        
        for (int r = 0; r < params->weight[i]->row; r++) 
        {
            for (int c = 0; c < params->weight[i]->col; c++)
            {
                fprintf(f, "%lf", params->weight[i]->values[r][c]);
                if (c < params->weight[i]->col - 1) fprintf(f, ","); 
            }

            fprintf(f, "\n");
        }

        
        for (int r = 0; r < params->bias[i]->row; r++)
        {
            for (int c = 0; c < params->bias[i]->col; c++)
            {
                fprintf(f, "%lf", params->bias[i]->values[r][c]);
                if (c < params->bias[i]->col - 1) fprintf(f, ","); 

            }
            fprintf(f, "\n");
        }

        fprintf(f, "\n");
    }

    fclose(f);
}
