#include"convert.h"
#include"matrice.h"

void matrix_csv(const char *filename, int cols, int lin, matrix* mat) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erreur d'ouverture du fichier %s\n", filename);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < cols; j++) {
            if (fscanf(file, "%lf,", &mat->values[i][j]) != 1) {
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

    matrix_csv(fileinput, 8, 267, X);
    matrix_csv(fileoutput, 1, 267, Y);
}