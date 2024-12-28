#include "back_propagation.h"


gradient* back_propagation(matrix* x, matrix* y, Parameters* p, activation* A)
{
    int m = y->col;

    gradient* g = (gradient*)malloc(sizeof(gradient));

    g->nb_layers = p->num_layers;

    g->dw= (matrix**)malloc(g->nb_layers* sizeof(matrix));
    g->db= (matrix**)malloc(g->nb_layers* sizeof(matrix));

    if (g->dw == NULL || g->db == NULL) {
        printf("Erreur : allocation de mémoire échouée pour g->dw ou g->db\n");
        return NULL;
    }

    
    matrix* dz1;
    matrix* dz2;
    for(int i = p->num_layers-1 ; i>=0 ; i--)

    {
        
        if(i== p->num_layers-1)
        {
            if (A->activ[i] == NULL || y == NULL) {
                printf("Erreur : matrice A->activ[%d] ou y est NULL\n", i);
                return NULL;
            }

            if (A->activ[i]->row != y->row || A->activ[i]->col != y->col) {
                printf("Erreur : Dimensions incompatibles pour la soustraction : A->activ[%d] (%d x %d) et y (%d x %d)\n", 
                    i, A->activ[i]->row, A->activ[i]->col, y->row, y->col);
                return NULL;
            }


            dz2 = subtraction(A->activ[i],y);
        }
        else
        {


            if (A->activ[i] == NULL) {
                printf("Erreur : matrice A->activ[%d] est NULL\n", i);
                return NULL;
            }



            matrix* deriv = sigmoid_deriv(A->activ[i]);
            matrix* trans = transpose(p->weight[i+1]);

            if (trans == NULL || dz2 == NULL || trans->col != dz2->row) {
                printf("Erreur : Dimensions incompatibles pour le produit matriciel trans * dz2\n");
                printf("Dimensions de trans : %d x %d\n", trans->row, trans->col);
                printf("Dimensions de dz2 : %d x %d\n", dz2->row, dz2->col);
                return NULL;
            }

            
            if (dz2->col == 1 && dz2->row != trans->col) {
                printf("Ajustement des dimensions de dz2...\n");
                dz2->row = trans->col; 
            }




            matrix* dott = dot(trans,dz2);

            if (dott->row != deriv->row || dott->col != deriv->col) {
                printf("Erreur : Dimensions incompatibles pour le produit matriciel dott * deriv\n");
                return NULL;
            }


            dz1 = multiplication(dott,deriv);
            freeMatrix(dz2);
            dz2 = matrix_copy(dz1);
            freeMatrix(dott);
            freeMatrix(trans);
            freeMatrix(deriv);
            freeMatrix(dz1);
        }
        if(i==0)
        {

            if (x == NULL) {
                printf("Erreur : matrice x est NULL\n");
                return NULL;
            }



            matrix* trans = transpose(x);

             if (trans == NULL || dz2 == NULL || trans->row != dz2->col) {
                printf("Erreur : Dimensions incompatibles pour le produit matriciel trans * dz2\n");
                return NULL;
            }


            matrix* dott = dot(dz2,trans);
            g->dw[i]= multi_scaler(dott,(1/m));
            freeMatrix(dott);
            freeMatrix(trans);
        }
        else
        {

            if (A->activ[i - 1] == NULL) {
                printf("Erreur : matrice A->activ[%d] est NULL\n", i - 1);
                return NULL;
            }


            matrix* trans = transpose(A->activ[i-1]);

            if (trans == NULL || dz2 == NULL || trans->row != dz2->col) {
                printf("Erreur : dimensions incompatibles pour le produit matriciel\n");
                return NULL;
            }

            matrix* dott = dot(dz2,trans);
            g->dw[i]= multi_scaler(dott,(1/m));
            freeMatrix(dott);
            freeMatrix(trans);
        }

        if (dz2 == NULL) {
            printf("Erreur : dz2 est NULL\n");
            return NULL;
        }

        matrix* sumrow = sum_row(dz2);
        g->db[i]=multi_scaler(sumrow,(1/m));
        freeMatrix(sumrow);
    }
    freeMatrix(dz2);
    return g;

}

