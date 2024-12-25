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