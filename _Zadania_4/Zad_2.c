#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wyswietlenieTablicy(int tab[], int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        printf("%4d", tab[i]);
    }
    printf("\n");
}

void sortowanieTablicy(int tab[], int rozmiar) {
    for (int i = 0; i < rozmiar - 1; ++i) {
        for (int j = 0; j < rozmiar - i - 1; ++j) {
            if (tab[j] > tab[j + 1]) {
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}

int wyszukiwanieBinarne(int tab[], int lewy, int prawy, int szukana) {
    if (prawy >= lewy) {
        int srodek = (lewy + prawy) / 2;

        if (tab[srodek] == szukana) {
            return srodek;
        }

        if (szukana < tab[srodek]) {
            return wyszukiwanieBinarne(tab, lewy, srodek - 1, szukana);
        } else {
            return wyszukiwanieBinarne(tab, srodek + 1, prawy, szukana);
        }

    } else {
        return -1;
    }
}

int main() {
    srand(time(NULL));
    int tab[20];
    int rozmiarTablicy = sizeof(tab) / sizeof(tab[0]);

    // Wpisanie randomowych wartosci do tablicy
    for (int i = 0; i < rozmiarTablicy; i++) {
        tab[i] = rand() % 100 + 1; // (1 - 100)
    }

    printf("Tablica: \n");
    wyswietlenieTablicy(tab, rozmiarTablicy);

    // Sortowanie tablicy
    sortowanieTablicy(tab, rozmiarTablicy);

    printf("Tablica po posortowaniu: \n");
    wyswietlenieTablicy(tab, rozmiarTablicy);

    printf("\n");
    printf("Podaj liczbe ktora chcesz znalesc: ");
    int szukana;
    scanf("%d", &szukana);
    int index = wyszukiwanieBinarne(tab, 0, rozmiarTablicy - 1, szukana);

    if (index == -1) {
        printf("Wartosc %d nie zostala znaleziona w tablicy\n", szukana);
    } else {
        printf("Znaleziono wartosc %d na indeksie %d\n", szukana, index);
    }

    return 0;
}
