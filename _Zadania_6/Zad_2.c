#include <stdio.h>

int main() {
    int intArray[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *ptr = intArray;

    printf("Zawartosc tablicy: \n");
    for (int i = 0; i < 10; i++) {
        printf("Element [%d] - %d\n", i, *ptr);
        ptr++;
    }

    return 0;
}
