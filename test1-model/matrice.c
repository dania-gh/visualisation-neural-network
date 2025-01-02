#include "matrice.h"


matrix* createMatrix(int row,int col)
{
    matrix* matrice=malloc(sizeof(matrix));
    matrice->col=col;
    matrice->row=row;
    matrice->values=malloc(row*sizeof(double));
    for(int i=0;i<row;i++)
    {
        matrice->values[i]=malloc(col*sizeof(double));
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


void printMatrix(matrix* m) {
    for (int i = 0; i < m->row; i++) {
        for (int j = 0; j < m->col; j++) {
            printf("[%d][%d]  %f  \t", i, j, m->values[i][j]);
        }
        printf("\n");
    }
}


void freeMatrix(matrix* m)
{
    for(int i =0 ;i < m->row ; i++)
    {
        free(m->values[i]);
    }
    free(m->values);
    free(m);
}

void copyPredictions(matrix* output, matrix* output_test_predect) {
    if (output_test_predect->row != output->row || output_test_predect->col != 1) {
        printf("Erreur : Dimensions incompatibles entre les matrices.\n");
        return;
    }

    for (int i = 0; i < output_test_predect->row; i++) {
        output_test_predect->values[i][0] = output->values[i][0]; 
    }
}