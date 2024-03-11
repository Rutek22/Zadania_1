#include <stdio.h>
#include <stdlib.h>

void stworzPascal(int** pascal, int wysokosc) {
    for (int i = 0; i < wysokosc; i++) {

        pascal[i] = (int *) malloc((i + 1) * sizeof(int));

        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                pascal[i][j] = 1;
            }
            else {
                pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }
        }
    }
}

void wyswietlPascal(int** pascal, int wysokosc) {
    printf("Trojkat Pascala:\n");
    for (int i = 0; i < wysokosc; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%7d", pascal[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int wysokosc;
    printf("Podaj wysokosc trojkota Pascala: ");
    scanf("%d", &wysokosc);

    int **pascal = (int **) malloc(wysokosc * sizeof(int *));

    stworzPascal(pascal, wysokosc);
    wyswietlPascal(pascal, wysokosc);

    free(pascal);

    return 0;
}