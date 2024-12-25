#include "operation.h"


matrix* multiplication (matrix* m1, matrix* m2)
{
    matrix* m = createMatrix(m1->row, m1->col);

    for (int i =0 ; i <m1->row ; i++)
    {
        for(int j= 0 ; j< m1->col ;j++)
        {
            m->values[i][j] = m1->values[i][j] * m1->values[i][j];
        }
    }

    return m;
}


matrix* addition (matrix* m1, matrix* m2)
{
    matrix* m = createMatrix(m1->row, m1->col);

    for (int i =0 ; i <m1->row ; i++)
    {
        for(int j= 0 ; j< m1->col ;j++)
        {
            m->values[i][j] = m1->values[i][j] + m1->values[i][j];
        }
    }

    return m;
}


matrix* subtraction (matrix* m1, matrix* m2)
{
    matrix* m = createMatrix(m1->row, m1->col);

    for (int i = 0 ; i <m1->row ; i++)
    {
        for(int j = 0 ; j< m1->col ;j++)
        {
            m->values[i][j] = m1->values[i][j] - m1->values[i][j];
        }
    }

    return m;
}


matrix* dot (matrix* m1, matrix* m2)
{
    matrix* m = createMatrix(m1->row, m2->col);
    matrix_fill(m,0);

    for (int i = 0 ; i <m1->row ; i++)
    {
        for(int j = 0 ; j< m2->col ;j++)
        {
            for (int k = 0 ; k < m1->col ; k++)
                {
                    m->values[i][j] += m1->values[i][k] * m1->values[k][j];
                }
            
        }
    }

    return m;
}


matrix* multi_scaler (matrix* m , double n )
{
    matrix* mat = matrix_copy(m);


    for(int i=0 ; i< m->row; i++)
    {
        for(int j=0 ; j< m->col; j++)
        {
            mat->values[i][j]*= n;
        }
    }
    return mat;
}