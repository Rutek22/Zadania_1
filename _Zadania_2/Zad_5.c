#include <stdio.h>
#include <string.h>

typedef struct {
    char imie[50];
    char nazwisko[50];
    char telefon[10];
} Contact;

void dodaj(Contact *lista_kontaktow, int *liczba_kontaktow) {
    if (*liczba_kontaktow < 10) {
        printf("Podaj imie: ");
        scanf("%s", lista_kontaktow[*liczba_kontaktow].imie);
        printf("Podaj nazwisko: ");
        scanf("%s", lista_kontaktow[*liczba_kontaktow].nazwisko);
        printf("Podaj numer telefonu: ");
        scanf("%s", lista_kontaktow[*liczba_kontaktow].telefon);
        (*liczba_kontaktow)++;
        printf("Kontakt zostal dodany pomyslnie.\n");
    } else {
        printf("Ksiazka adresowa jest pelna, nie można dodać nowego kontaktu.\n");
    }
}

void wyszukaj(Contact *lista_kontaktow, int liczba_kontaktow) {
    char nazwisko[50];
    int czy_istnieje = 0;

    printf("Podaj nazwisko do wyszukania: ");
    scanf("%s", nazwisko);

    printf("\n");

    for (int i = 0; i < liczba_kontaktow; i++) {
        if (strcmp(lista_kontaktow[i].nazwisko, nazwisko) == 0) {
            printf("Znaleziony kontakt:\n");
            printf("Imie: %s\n", lista_kontaktow[i].imie);
            printf("Nazwisko: %s\n", lista_kontaktow[i].nazwisko);
            printf("Telefon: %s\n", lista_kontaktow[i].telefon);
            printf("\n");
            czy_istnieje = 1;
        }
    }

    if (!czy_istnieje) {
        printf("Nie znaleziono kontaktu o nazwisku \"%s\".\n", nazwisko);
    }
}

void usun_kontakt(Contact *lista_kontaktow, int *liczba_kontaktow) {
    char nazwisko[50];
    int czy_istnieje = 0;
    printf("Wprowadz nazwisko do usuniecia: ");
    scanf("%s", nazwisko);

    printf("\n");

    for (int i = 0; i < *liczba_kontaktow; i++) {
        if (strcmp(lista_kontaktow[i].nazwisko, nazwisko) == 0) {
            czy_istnieje = 1;

            for (int j = i; j < *liczba_kontaktow - 1; j++) {
                lista_kontaktow[j] = lista_kontaktow[j + 1];
            }
            (*liczba_kontaktow)--;
            printf("Kontakt \"%s\" zostal usuniety.\n", nazwisko);
            break;
        }
    }

    if (!czy_istnieje) {
        printf("Nie znaleziono kontaktu o nazwisku \"%s\".\n", nazwisko);
    }

    printf("\n");
}

void pokaz_kontakty(Contact *lista_kontaktow, int liczba_kontaktow) {
    printf("Lista kontaktow:\n");
    for (int i = 0; i < liczba_kontaktow; ++i) {
        printf("Kontakt %d:\n", i + 1);
        printf("Imie: %s\n", lista_kontaktow[i].imie);
        printf("Nazwisko: %s\n", lista_kontaktow[i].nazwisko);
        printf("Telefon: %s\n", lista_kontaktow[i].telefon);
        printf("\n");
    }
}

int main()
{
    Contact lista_kontaktow[10] = {
            {"Jan", "Kowalski", "123456789"},
            {"Anna", "Nowak", "987654321"},
            {"Adam", "Mickiewicz", "555123456"}
    };

    int liczba_kontaktow = 3;
    int decyzja = 1;

    while (decyzja) {
        int opcja = 0;
        printf("Ksiazka adresowa - menu\n");
        printf("1. Dodaj nowy kontak\n");
        printf("2. Wyszukaj\n");
        printf("3. Usun kontakt\n");
        printf("4. Pokaz kontakty\n");
        printf("5. Koniec\n");
        printf("Wybierz opcje: ");
        scanf("%d", &opcja);

        printf("\n");

        switch (opcja) {
            case 1:
                dodaj(lista_kontaktow, &liczba_kontaktow);
                break;
            case 2:
                wyszukaj(lista_kontaktow, liczba_kontaktow);
                break;
            case 3:
                usun_kontakt(lista_kontaktow, &liczba_kontaktow);
                break;
            case 4:
                pokaz_kontakty(lista_kontaktow, liczba_kontaktow);
                break;
            case 5:
                printf("Zamykanie programu\n");
                decyzja = 0;
                break;
            default:
                printf("Nieprawidlowa opcja!\n");
                break;
        }
        printf("\n");
    }

    return 0;
}
