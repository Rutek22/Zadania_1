#include <stdio.h>

int Suma(int koniec) {
    int wynik = 0;

    if (koniec > 0) {
        for (int i = 1; i < koniec; i++) {
            if (i % 3 == 0 || i % 5 == 0) {
                wynik += i;
            }
        }
    }

    return wynik;
}

int main()
{
    printf("Podaj liczbe: ");
    int liczba;
    scanf("%d", &liczba);

    int suma = 0;
    if (liczba > 0) {
        suma = Suma(liczba);
    }

    printf("Suma wszystkich wielokrotnosci 3, 5 ponizej %d: %d\n", liczba, suma);

    return 0;
}
