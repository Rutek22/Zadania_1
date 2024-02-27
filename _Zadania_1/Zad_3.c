#include <stdio.h>

void Silnia(int tab[]) {
    for (int i = 0; i < 10; i++) {
        int wynik = 1;
        for (int  j = 0; j < tab[i]; j++)
        {
            wynik *= tab[j];
        }
        printf("!%d: %d\n", tab[i], wynik);
    }
}

int main()
{
    int tab[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    Silnia(tab);
    return 0;
}
