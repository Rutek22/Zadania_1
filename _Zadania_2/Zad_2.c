#include <stdio.h>

void funkcja(float * zmienna) {
    (*zmienna)*=2;
}

int main()
{
    float zmienna = 15.4;

    printf("Wartosc zmiennej: %f\n", zmienna);

    funkcja(&zmienna);

    printf("Wartosc zmiennej po wykonaniu funkcji: %f\n", zmienna);

    return 0;
}
