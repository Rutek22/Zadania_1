#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char imie[50];
    float ocena;
} Student;

void funkcja(Student* studenci[], int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        for (int j = 1; j < rozmiar; j++) {
            if (studenci[j]->ocena > studenci[j - 1]->ocena) {
                Student *temp = studenci[j];
                studenci[j] = studenci[j - 1];
                studenci[j - 1] = temp;
            }
        }
    }
}

int main()
{
    char *imiona[] = {"Adam", "Ewa", "Kamil", "Julia", "Mateusz", "Anna", "Piotr", "Natalia", "Bartosz", "Kinga",
                      "Kacper", "Zuzanna", "Maciej", "Wiktoria", "Jakub", "Magdalena", "Michal", "Oliwia", "Dominik", "Karolina"};

    Student studenci[100];

    // Inicjowanie tablicy studentów
    for (int i = 0; i < 100; i++) {
        int index_imienia = rand() % 20;
        strcpy(studenci[i].imie, imiona[index_imienia]);
        studenci[i].ocena = (rand() % 5) + 1;
    }

    printf("Tablica studentow: \n");
    printf("Numer studenta | Imie | Ocena\n");
    for (int i = 0; i < 100; i++) {
        printf("Student %4d %13s - %.2f\n", i + 1, studenci[i].imie, studenci[i].ocena);
    }

    printf("\n");

    // Stworzenie wskazników do kazdego elementu tablicy
    Student* wsk_studenci[100];
    for (int i = 0; i < 100; i++) {
        wsk_studenci[i] = &studenci[i];
    }

    funkcja(wsk_studenci, sizeof(wsk_studenci) / sizeof(wsk_studenci[0]));

    printf("Tablica studentow po posortowaniu: \n");
    printf("Numer studenta | Imie | Ocena\n");
    for (int i = 0; i < 100; i++) {
        printf("Student %4d %13s - %.2f\n", i + 1, wsk_studenci[i]->imie, wsk_studenci[i]->ocena);
    }

    return 0;
}
