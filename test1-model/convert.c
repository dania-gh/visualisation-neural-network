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



void creat_X_Y_Z(matrix* X, matrix* Y,matrix* Z)
{
    const char *fileinput_normalise_test="input_normalise_test";
    const char *fileoutput="output.csv";
    const char *fileinput_normalise_training="input_normalise_training";

    matrix_csv(fileinput_normalise_test, 8, 267, X);
    matrix_csv(fileoutput, 1, 267, Y);
    matrix_csv(fileinput_normalise_training ,8 , 500 ,Z);

}