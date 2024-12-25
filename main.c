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

    

    matrix* hidden_weights = createMatrix(2,2);
    matrix_randomize(hidden_weights ,2);

    printMatrix(hidden_weights);

}