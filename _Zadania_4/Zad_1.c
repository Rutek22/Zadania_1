#include <stdio.h>

int factorial(int liczba) {
    if (liczba < 0) {
        return -1;
    }
    else if (liczba == 0 || liczba == 1) {
        return 1;
    }
    else {
        return liczba * factorial(liczba - 1);
    }
}

int main() {
    int liczba;

    printf("Program oblicza silnie z podanej liczby\n");
    printf("Wprowadz liczbe: ");
    scanf("%d", &liczba);

    int silnia = factorial(liczba);

    if (silnia != -1) {
        printf("Silnia z %d wynosi %d \n", liczba, silnia);
    } else {
        printf("Blad! Liczba musi byc wieksza od 0\n");
    }

    return 0;
}
