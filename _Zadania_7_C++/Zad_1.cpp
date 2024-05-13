#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>

std::string numbers[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int energiaZLinii(const std::string& line) {
    int energia = 0;
    int liczbaPierwsza = -1;
    int liczbaOstatnia = -1;

    for (size_t i = 0; i < line.length(); i++) {
        if (isdigit(line[i])) {
            if (liczbaPierwsza == -1) {
                liczbaPierwsza = line[i] - '0';
            }
            liczbaOstatnia = line[i] - '0';
        } else {
            for (size_t j = 0; j < sizeof(numbers) / sizeof(numbers[0]); j++) {
                if (strncmp(&line[i], numbers[j].c_str(), numbers[j].length()) == 0) {
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
    std::ifstream file("input.txt");
    std::string line;
    int sumaEnergii = 0;

    if (!file.is_open()) {
        std::cout << "Nie można otworzyć pliku!!!";
        return 1;
    }

    while (std::getline(file, line)) {
        sumaEnergii += energiaZLinii(line);
    }

    std::cout << "Suma Energii: " << sumaEnergii << std::endl;

    file.close();

    return 0;
}