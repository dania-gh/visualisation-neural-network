#include "matrice.h"


matrix* createMatrix(int row, int col) {
    matrix* matrice = malloc(sizeof(matrix));
    if (matrice == NULL) {
        printf("Erreur d'allocation mémoire pour la structure matrix\n");
        exit(EXIT_FAILURE);
    }

    matrice->row = row;
    matrice->col = col;

    matrice->values = malloc(row * sizeof(double*));
    if (matrice->values == NULL) {
        printf("Erreur d'allocation mémoire pour les lignes\n");
        free(matrice);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < row; i++) {
        matrice->values[i] = malloc(col * sizeof(double));
        if (matrice->values[i] == NULL) {
            printf("Erreur d'allocation mémoire pour la ligne %d\n", i);

            for (int j = 0; j < i; j++) {
                free(matrice->values[j]);
            }
            free(matrice->values);
            free(matrice);
            exit(EXIT_FAILURE);
        }
    }
    return matrice;
}




void matrix_randomize(matrix* m, int nb_node) {
    double min = -1.0 / sqrt(nb_node); 
    double max = 1.0 / sqrt(nb_node);

    for (int i = 0; i < m->row; i++) {
        for (int j = 0; j < m->col; j++) {
            m->values[i][j] = min + (max - min) * ((double)rand() / RAND_MAX);
        }
    }
}



void matrix_fill(matrix* m,int n)
{
    for(int i = 0;i<m->row;i++)
    {
        for(int j= 0 ; j<m->col;j++)
        {
            m->values[i][j]=n;
        }
    }
}


matrix* matrix_copy(matrix* m)
{
    matrix* mat = createMatrix(m->row, m->col);



    for(int i = 0 ; i< m->row ; i++)
    {
        for ( int j =0 ; j< m->col ; j++)
        {
            mat->values[i][j] = m->values[i][j];
        }
    }

    return mat;
}