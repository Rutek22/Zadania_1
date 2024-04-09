#include <stdio.h>

union Dane {
    int liczbaCalkowita;
    float liczbaZmiennoprzecinkowa;
    char znak;
};

int main() {
    union Dane dane;

    dane.liczbaCalkowita = 17;
    printf("Zmienna calkowita (INT): %d\n", dane.liczbaCalkowita);

    dane.liczbaZmiennoprzecinkowa = 17.7;
    printf("Zmienna zmiennoprzecinkowa (FLOAT): %f\n", dane.liczbaZmiennoprzecinkowa);

    dane.znak = 'x';
    printf("Zmienna znakowa (CHAR): %c\n", dane.znak);

    return 0;
}