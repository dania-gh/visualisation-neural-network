#include"convert.h"
#include"matrice.h"

void matrix_csv(const char *filename,int cols, int lin, matrix* mat)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erreur d'ouverture du fichier\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < cols; j++) {
            if (fscanf(file, "%lf,", mat->values[i][j]) != 1) {
                printf("Erreur de lecture du fichier\n");
                fclose(file);
                exit(EXIT_FAILURE);
            }
        }
    }

    fclose(file);
}


void creat_X_Y(matrix* X, matrix* Y)
{
    const char *fileinput="input.csv";
    const char *fileoutput="output.csv";

    matrix_csv(fileinput, 2, 100, X);
    matrix_csv(fileoutput, 1, 100, Y);
}