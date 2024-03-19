#include <stdio.h>

void wyswietlenieTablicy(int tab[], int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        printf("%4d", tab[i]);
    }
    printf("\n");
}

void permute(int tab[], int start, int koniec) {
    if (start == koniec) {
        wyswietlenieTablicy(tab, koniec + 1);
        return;
    }
    for (int i = start; i <= koniec; i++) {
        int temp = tab[start];
        tab[start] = tab[i];
        tab[i] = temp;

        permute(tab, start + 1, koniec);

        temp = tab[start];
        tab[start] = tab[i];
        tab[i] = temp;
    }
}

int main() {
    int tab[] = {1, 2, 3};
    int rozmiarTablicy = sizeof(tab) / sizeof(tab[0]);

    printf("Ciag: ");
    wyswietlenieTablicy(tab, rozmiarTablicy);

    printf("\n");
    printf("Permutacje ciagu: \n");
    permute(tab, 0, rozmiarTablicy - 1);

    return 0;
}
