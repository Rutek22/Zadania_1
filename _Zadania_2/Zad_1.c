#include <stdio.h>

int main()
{
    int zmienna = 15;
    int * pZmienna = &zmienna;
    *pZmienna = 17;

    printf("Wartosc zmiennej wyciagnieta ze zmiennej %d\n", zmienna);
    printf("Wartosc zmiennej wyciagnieta ze wskaznika %d\n", *pZmienna);

    return 0;
}
