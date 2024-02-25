#include <stdlib.h>
#include <stdio.h>

int main()
{
    char name[50];
    printf("Wprowadz swoje imie: ");
    scanf_s("%s", name, (unsigned)_countof(name));
    printf("Witaj %s", name);
    return 0;
}
