#include <stdio.h>
#include <stdlib.h>

#include "convert.h"
#include "matrice.h"
void printMatrix(matrix* m) {
    for (int i = 0; i < m->row; i++) {
        for (int j = 0; j < m->col; j++) {
            printf("Valeur à [%d][%d] : %f\n", i, j, m->values[i][j]);
        }
        printf("\n");
    }
}
int main ()
{
    srand(time(NULL));

    matrix* X = createMatrix(100, 2);
    matrix* Y = createMatrix(100 ,1);
    creat_X_Y(X, Y);
    //printMatrix(X)
    //printMatrix(Y)
    matrix* hidden_weights = createMatrix(2,2);
    matrix_randomize(hidden_weights ,2);
    //printMatrix(hidden_weights);

    matrix* hidden_bias=createMatrix(2,1);
    matrix_randomize(hidden_bias ,2);
    //printMatrix(hidden_bias);

    matrix* output_weights=createMatrix(2,1);
    matrix_randomize(output_weights,1);
    //printMatrix(output_weights);

    matrix* output_bias=createMatrix(1,1);
    matrix_randomize(output_bias,1);
    //printMatrix(output_bias);


}