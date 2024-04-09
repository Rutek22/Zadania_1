#include <stdio.h>

int dodawanie(int x, int y) {
    return x + y;
}

int odejmowanie(int x, int y) {
    return x - y;
}

int mnozenie(int x, int y) {
    return x * y;
}

int main() {
    int koniec = 0;
    int (*pf)(int, int);

    while (koniec == 0) {
        printf("Funkcje:\n"
               "1. Dodawanie\n"
               "2. Odejmowanie\n"
               "3. Mnozenie\n"
               "4. Zamkniecie programu\n");
        printf("Wybierz funkcje:");

        int opcja;
        scanf("%d", &opcja);

        printf("\n");

        int num1;
        int num2;

        switch (opcja) {
            case 1:
                printf("Wprowadz pierwsza liczbe:");
                scanf("%d", &num1);
                printf("Wprowadz druga liczbe:");
                scanf("%d", &num2);
                pf = &dodawanie;
                int wynikDodawanie = pf(num1, num2);

                printf("Funkcja dodawanie - (%d + %d)\n", num1, num2);
                printf("Wynik: %d", wynikDodawanie);

                break;
            case 2:
                printf("Wprowadz pierwsza liczbe:");
                scanf("%d", &num1);
                printf("Wprowadz druga liczbe:");
                scanf("%d", &num2);
                pf = &odejmowanie;
                int wynikOdejmowanie = pf(num1, num2);

                printf("Funkcja dodawanie - (%d - %d)\n", num1, num2);
                printf("Wynik: %d", wynikOdejmowanie);

                break;
            case 3:
                printf("Wprowadz pierwsza liczbe:");
                scanf("%d", &num1);
                printf("Wprowadz druga liczbe:");
                scanf("%d", &num2);
                pf = &mnozenie;
                int wynikMnozenie = pf(num1, num2);

                printf("Funkcja dodawanie - (%d * %d)\n", num1, num2);
                printf("Wynik: %d", wynikMnozenie);

                break;
            case 4:
                printf("Zamykanie programu.");
                koniec = 1;
                break;
            default:
                printf("Nieprawidlowa opcja !!!");
                break;
        }

        printf("\n");
        printf("\n");
    }
    return 0;
}