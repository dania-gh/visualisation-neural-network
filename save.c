#include "save.h"

void save_weight_bias(Parameters* params, const char* fichier)
{
    FILE* f = fopen(fichier, "wb");
    if (f == NULL) 
    {
        printf("Erreur lors de l'ouverture du fichier pour sauvegarder les poids.\n");
        return;
    }

    for (int i = 0; i < params->num_layers; i++) 
    {
        fwrite(params->weight[i]->values, sizeof(double), params->weight[i]->row * params->weight[i]->col, f);
        fwrite(params->bias[i]->values, sizeof(double), params->bias[i]->row * params->bias[i]->col, f);
    }

    fclose(f);
}