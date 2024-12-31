#include "initialisation.h"

Parameters* initialisation(int nb_x, int nb_y, int nb_node, int before_end,int nb_layers) {
    Parameters* p = (Parameters*)malloc(sizeof(Parameters));

    if (p == NULL) {
        printf("Erreur d'allocation mémoire pour Parameters\n");
        exit(EXIT_FAILURE);
    }

    p->num_layers = nb_layers;

    p->weight = (matrix**)malloc(nb_layers * sizeof(matrix*));
    p->bias = (matrix**)malloc(nb_layers * sizeof(matrix*));

    if (p->weight == NULL || p->bias == NULL) {
        printf("Erreur d'allocation mémoire pour les poids et les biais\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < nb_layers; i++) {
        if (i == 0) {
            p->weight[i] = createMatrix(nb_node, nb_x);
        } else if (i == nb_layers - 1) {
            p->weight[i] = createMatrix(nb_y, before_end);
        }else if(i == nb_layers - 2 ) {
            p->weight[i] = createMatrix(before_end, nb_node);
        }        else {
            p->weight[i] = createMatrix(nb_node, nb_node);
        }

        matrix_randomize(p->weight[i], p->weight[i]->row);

        if (i == nb_layers - 1) {
            p->bias[i] = createMatrix(nb_y, 1);
        } else if(i == nb_layers - 2){
            p->bias[i] = createMatrix(before_end, 1);
        }else {
            p->bias[i] = createMatrix(nb_node, 1);
        }

        matrix_fill(p->bias[i], 0);
    }

    return p;
}
