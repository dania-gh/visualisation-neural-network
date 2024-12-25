#include "operation.h"


matrix* multiplication (matrix* m1, matrix* m2)
{
    matrix* m = createMatrix(m1->row, m1->col);

    for (int i =0 ; i <m1->row ; i++)
    {
        for(int j= 0 ; j<= m1->col ;j++)
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
        for(int j= 0 ; j<= m1->col ;j++)
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
        for(int j = 0 ; j<= m1->col ;j++)
        {
            m->values[i][j] = m1->values[i][j] - m1->values[i][j];
        }
    }

    return m;
}