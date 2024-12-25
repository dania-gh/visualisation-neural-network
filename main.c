#include <stdio.h>
#include <stdlib.h>

#include "convert.h"
#include "matrice.h"
void printMatrix(matrix* m) {
    for (int i = 0; i < m->row; i++) {
        for (int j = 0; j < m->col; j++) {
            printf("%f ", m->values[i][j]);
        }
        printf("\n");
    }
}
int main ()
{
    matrix* X = createMatrix(100, 2);
    matrix* Y = createMatrix(100 ,1);

    creat_X_Y(X, Y);

    printf("Matrice 1:\n");
    printMatrix(X);
    
}