#include <stdio.h>
#include <stdlib.h>

 
  
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



int main() {
    #define M 2 
    #define k 1 
    #define N 100
    float X[N][M];
    float y[N][k];

    const char *fileinput="input.csv";
    const char *fileoutput="output.csv";

    matrix_csv(fileinput, M, N, X);
    matrix_csv(fileoutput, k, N, y);


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%f ", X[i][j]);
        }
        printf("\n");
    }


    printf("\n");


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 1; j++) {
            printf("%f ", y[i][j]);
        }
        printf("\n");
    }

    

    return 0;
}