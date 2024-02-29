#include <stdio.h>

typedef struct {
    char imie[50];
    float ocena;
} Student;

void funkcja(Student* studenci[], int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        for (int j = 1; j < rozmiar; j++) {
            if (studenci[j]->ocena > studenci[j - 1]->ocena) {
                Student temp = *(studenci[j]);
                *(studenci[j]) = *(studenci[j - 1]);
                *(studenci[j - 1]) = temp;
            }
        }
    }
}

int main()
{
    Student studenci[5] = { {"Krystian", 3},
                            {"Hubert", 4},
                            {"Wiktor", 5},
                            {"Kamil", 4},
                            {"Jakub", 2} };

    printf("Tablica studentow: \n");
    printf("Numer studenta | Imie | Ocena\n");
    for (int i = 0; i < sizeof(studenci) / sizeof(studenci[0]); i++) {
        printf("Student %d %s - %.2f\n", i + 1, studenci[i].imie, studenci[i].ocena);
    }

    printf("\n");

    // Stworzenie wskazników do kazdego elementu tablicy
    Student* wsk_studenci[5];
    for (int i = 0; i < 5; i++) {
        wsk_studenci[i] = &studenci[i];
    }

    funkcja(wsk_studenci, sizeof(wsk_studenci) / sizeof(wsk_studenci[0]));

    printf("Tablica studentow po posortowaniu: \n");
    printf("Numer studenta | Imie | Ocena\n");
    for (int i = 0; i < sizeof(studenci) / sizeof(studenci[0]); i++) {
        printf("Student %d %s - %.2f\n", i + 1, studenci[i].imie, studenci[i].ocena);
    }


    return 0;
}
