#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int wybierzRuch() {
    int ruchUzytkownika = 0;
    int ruch;
    printf("Lista ruchow:\n");
    printf("1. Kamien\n");
    printf("2. Papier\n");
    printf("3. Nozyce\n");
    printf("Wybierz swoj ruch [1, 2, 3]:");
    scanf("%d", &ruch);          // Znak & aby zapisać wartość do zmiennej
    if (ruch >= 1 && ruch <= 3) {
        ruchUzytkownika = ruch;
    } else {
        printf("Nieprawidlowy ruch!\n\n");
    }
    return ruchUzytkownika;
}

void ruchy(int ruchUzytkownika, int ruchKomputera) {
    printf("Uzytkownik: ");
    switch (ruchUzytkownika) {
        case 1:
            printf("Kamien\n");
            break;
        case 2:
            printf("Papier\n");
            break;
        case 3:
            printf("Nozyce\n");
            break;
    }
    printf("Komputer: ");
    switch (ruchKomputera) {
        case 1:
            printf("Kamien\n");
            break;
        case 2:
            printf("Papier\n");
            break;
        case 3:
            printf("Nozyce\n");
            break;
    }
}

int main() {
    printf("Gra Kamien, Papier, Nozyce\n");
    printf("Komendy:\n");
    printf("Graj\n");
    printf("Wyniki\n");
    printf("Koniec\n\n");

    char komenda[20];
    int decyzja = 1;
    int runda = 0;
    int wyniki[20][4];

    while (decyzja) {
        printf("Wprowadz komende: ");
        scanf("%s", komenda);

        printf("\n");

        if (strcmp(komenda, "Graj") == 0) {
            // Wybor uzytkownika
            int ruchUzytkownika = wybierzRuch();
            if (ruchUzytkownika == 0) {
                continue;
            }

            // Wybor komputera
            // Losowa liczba z zakresu od 1 do 3
            int ruchKomputera = rand() % 3 + 1;

            // Informacja o ruchach
            ruchy(ruchUzytkownika, ruchKomputera);

            // Sprawdzenie kto wygrał
            int wynik = 0;
            if (ruchUzytkownika == ruchKomputera) {
                printf("Remis!\n");
            } else if ((ruchUzytkownika == 1 && ruchKomputera == 3) ||
                       (ruchUzytkownika == 2 && ruchKomputera == 1) ||
                       (ruchUzytkownika == 3 && ruchKomputera == 2))  {
                printf("Wygrales!\n");
                wynik = 1;
            } else {
                printf("Komputer wygral!\n");
                wynik = -1;
            }

            // Zapis wynikow do tabeli
            wyniki[runda][0] = runda + 1;
            wyniki[runda][1] = ruchUzytkownika;
            wyniki[runda][2] = ruchKomputera;
            wyniki[runda][3] = wynik;

            runda++;
        } else if (strcmp(komenda, "Wyniki") == 0) {
            printf("Wyniki: \n");
            printf("Runda | Ruch Uzytkownika | Ruch Komputera | Wynik\n");

            for (int i = 0; i < runda; i++) {
                printf("%5d | %16d | %14d | %5d\n", wyniki[i][0], wyniki[i][1], wyniki[i][2], wyniki[i][3]);
            }

        } else if (strcmp(komenda, "Koniec") == 0) {
            printf("Zamykanie programu");
            decyzja = 0;
        } else {
            printf("Nieprawidlowa komenda!\n");
        }
        printf("\n");
    }

    return 0;
}