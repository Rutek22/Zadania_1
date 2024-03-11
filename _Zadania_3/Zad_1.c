#include <stdio.h>
#include <stdlib.h>

void stworzPascal(int** matrix, int wysokosc) {
    for (int i = 0; i < wysokosc; i++) {

        matrix[i] = (int *) malloc((i+1) * sizeof(int));

        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                matrix[i][j] = 1;
            }
            else {
                matrix[i][j] = matrix[i - 1][j - 1] + matrix[i - 1][j];
            }
        }
    }
}

void wyswietlPascal(int** matrix, int wysokosc) {
    printf("Trojkat Pascala:\n");
    for (int i = 0; i < wysokosc; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%7d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int wysokosc;
    printf("Podaj wysokosc trojkota Pascala: ");
    scanf("%d", &wysokosc);

    int **matrix = (int **) malloc(wysokosc * sizeof(int *));

    stworzPascal(matrix, wysokosc);
    wyswietlPascal(matrix, wysokosc);

    free(matrix);

    return 0;
}