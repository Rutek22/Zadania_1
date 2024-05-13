#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int czyPoprawne(const char *line, int max_czerwone, int max_zielone, int max_niebieskie, int *sumaMocy) {
    int result = 1;
    int indexStart = 0;
    int currRed = 0;
    int currBlue = 0;
    int currGreen = 0;

    for (int i = 0; i < strlen(line); i++) {
        if (line[i] == ':') {
            indexStart = i + 1;
            break;
        }
    }

    for (int i = indexStart; i < strlen(line); i++) {
        char number[5];
        int counter = 0;

        if (isdigit(line[i])) {
            while (isdigit(line[i])) {
                number[counter++] = line[i++];
            }
            number[counter] = '\0';

            int num = atoi(number);

            if (line[i+1] == 'r') {
                if (currRed < num) {
                    currRed = num;
                }
            } else if (line[i+1] == 'b') {
                if (currBlue < num) {
                    currBlue = num;
                }
            } else if (line[i+1] == 'g') {
                if (currGreen < num) {
                    currGreen = num;
                }
            }
        }
    }

    if (max_czerwone < currRed || max_zielone < currGreen || max_niebieskie < currBlue) {
        result = -1;
    }

    *sumaMocy += currRed * currBlue * currGreen;

    printf("%5d czerwonych, %5d niebieskich, %5d zielonych\n",currRed, currBlue, currGreen);

    return result;
}

int getIndex(const char *line) {
    int index = 0;
    int i = 0;

    while (line[i]) {
        if (isdigit(line[i])) {
            int j = i;
            while (isdigit(line[j])) {
                index = index * 10 + (line[j] - '0');
                j++;
            }
            break;
        }
        i++;
    }

    return index;
}

int main() {
    FILE *file;
    char line[1000];
    int sumaIndeksow = 0;
    int sumaMocy = 0;

    file = fopen("input2.txt", "r");

    if (file == NULL) {
        printf("Nie można otworzyć pliku!!!");
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("Gra: %-3d - ", getIndex(line));
        if ((czyPoprawne(line, 12, 13, 14, &sumaMocy)) == 1) {
            sumaIndeksow += getIndex(line);
        }
    }

    printf("Suma Indeksow: %d\n", sumaIndeksow);
    printf("Suma Mocy: %d\n", sumaMocy);

    fclose(file);

    return 0;
}
