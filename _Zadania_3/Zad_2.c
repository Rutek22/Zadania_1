#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int wiersze;
    int kolumny;

    printf("Podaj liczbe wierszy: ");
    scanf("%d", &wiersze);

    printf("Podaj liczbe kolumn: ");
    scanf("%d", &kolumny);

    // Alokacja pamieci dla wierszy i kolumn
    int** matrix = (int **)malloc(wiersze * sizeof(int *));

    for (int i = 0; i < wiersze; i++) {
        matrix[i] = (int *) malloc(kolumny * sizeof(int));
    }

    // Wypelnienie macierzy
    srand(time(NULL));
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            matrix[i][j] = rand() % 100 + 1; // losowa liczba z zakresu 1 - 100
        }
    }

    // Wyswietlenie macierzy
    printf("Macierz:\n");
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            printf("%5d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Zwolnienie zaalokowanej pamieci
    for (int i = 0; i < wiersze; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}