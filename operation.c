#include "operation.h"


matrix* multiplication (matrix* m1, matrix* m2)
{
    if(m1->row != m2->row || m1->col != m2->col)
    {
        printf("matrix not the same dimension");
        return ;
    }
    matrix* m = createMatrix(m1->row, m1->col);

    for (int i =0 ; i <m1->row ; i++)
    {
        for(int j= 0 ; j< m1->col ;j++)
        {
            m->values[i][j] = m1->values[i][j] * m2->values[i][j];
        }
    }

    return m;
}


matrix* addition (matrix* m1, matrix* m2)
{
    if(m1->row != m2->row || m1->col != m2->col)
    {
        printf("matrix not the same dimension");
        return ;
    }
    matrix* m = createMatrix(m1->row, m1->col);

    for (int i =0 ; i <m1->row ; i++)
    {
        for(int j= 0 ; j< m1->col ;j++)
        {
            m->values[i][j] = m1->values[i][j] + m2->values[i][j];
        }
    }

    return m;
}


matrix* subtraction (matrix* m1, matrix* m2)
{
    if(m1->row != m2->row || m1->col != m2->col)
    {
        printf("matrix not the same dimension");
        return ;
    }
    matrix* m = createMatrix(m1->row, m1->col);

    for (int i = 0 ; i <m1->row ; i++)
    {
        for(int j = 0 ; j< m1->col ;j++)
        {
            m->values[i][j] = m1->values[i][j] - m2->values[i][j];
        }
    }

    return m;
}


matrix* dot (matrix* m1, matrix* m2)
{
    if(m1->col != m2->row )
    {
        printf("matrix not the right dimension");
        return ;
    }
    matrix* m = createMatrix(m1->row, m2->col);
    matrix_fill(m,0);

    for (int i = 0 ; i <m1->row ; i++)
    {
        for(int j = 0 ; j< m2->col ;j++)
        {
            for (int k = 0 ; k < m1->col ; k++)
                {
                    m->values[i][j] += m1->values[i][k] * m2->values[k][j];
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

matrix* add_scaler (matrix* m , double n )
{
    matrix* mat = matrix_copy(m);


    for(int i=0 ; i< m->row; i++)
    {
        for(int j=0 ; j< m->col; j++)
        {
            mat->values[i][j]+= n;
        }
    }
    return mat;
}

matrix* matrix_exp(matrix* m)
{
    matrix* mat = matrix_copy(m);
    for(int i=0 ; i< m->row; i++)
    {
        for(int j=0 ; j< m->col; j++)
        {
            mat->values[i][j]=exp(m->values[i][j]);
        }
    }
    return mat;
}

matrix* inverse(matrix* m)
{
    matrix* mat = matrix_copy(m);

    for(int i=0 ; i< m->row; i++)
    {
        for(int j=0 ; j< m->col; j++)
        {
            mat->values[i][j]=1/m->values[i][j];
        }
    }
    return mat;
}