#include"convert.h"

void matrix_csv(const char *filename,int cols, int lin, float mat[lin][cols])
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erreur d'ouverture du fichier\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < cols; j++) {
            if (fscanf(file, "%f,", &mat[i][j]) != 1) {
                printf("Erreur de lecture du fichier\n");
                fclose(file);
                exit(EXIT_FAILURE);
            }
        }
    }

    fclose(file);
}