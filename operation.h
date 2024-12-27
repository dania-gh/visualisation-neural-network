#ifndef operation_h
#define operation_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrice.h"

matrix* multiplication (matrix* m1, matrix* m2);
matrix* addition (matrix* m1, matrix* m2);
matrix* subtraction (matrix* m1, matrix* m2);
matrix* dot (matrix* m1, matrix* m2);
matrix* multi_scaler (matrix* m , double n );
matrix* add_scaler (matrix* m , double n );
matrix* matrix_exp(matrix* m);
matrix* inverse(matrix* m);
matrix* transpose(matrix* mat);


#endif