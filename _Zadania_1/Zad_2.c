#include <stdio.h>

int main()
{
    int oceny[2][5] = { {2, 3, 4, 5, 6,}, {4, 3, 2, 3, 2} };
    int sumaMatematyka = 0, sumaFizyka = 0;

    for (int i = 0; i < 5; i++) {
        sumaMatematyka += oceny[0][i];
        sumaFizyka+= oceny[1][i];
    }

    float sredniaMatematyka = (float)sumaMatematyka / 5;
    float sredniaFizyka = (float)sumaFizyka / 5;

    printf("Srednia ocen z matematyki: %f\n", sredniaMatematyka);
    printf("Srednia ocen z fizyki: %f\n", sredniaFizyka);

    return 0;
}
