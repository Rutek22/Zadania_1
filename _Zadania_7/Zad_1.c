#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *numbers[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int energiaZLinii(const char *line) {
    int energia = 0;
    int liczbaPierwsza = -1;
    int liczbaOstatnia = -1;

    for (int i = 0; line[i] != '\0'; i++) {
        if (isdigit(line[i])) {
            if (liczbaPierwsza == -1) {
                liczbaPierwsza = line[i] - '0';
            }
            liczbaOstatnia = line[i] - '0';
        } else {
            for (int j = 0; j < sizeof(numbers) / sizeof(numbers[0]); j++) {
                if (strncmp(&line[i], numbers[j], strlen(numbers[j])) == 0) {
                    if (liczbaPierwsza == -1) {
                        liczbaPierwsza = j + 1;
                    }
                    liczbaOstatnia = j + 1;
                    break;
                }
            }
        }
    }

    energia = liczbaPierwsza * 10 + liczbaOstatnia;

    return energia;
}

int main() {
    FILE *file;
    char line[1000];
    int sumaEnergii = 0;

    file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Nie można otworzyć pliku!!!");
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        sumaEnergii += energiaZLinii(line);
    }

    printf("Suma Energii: %d\n", sumaEnergii);

    fclose(file);

    return 0;
}
