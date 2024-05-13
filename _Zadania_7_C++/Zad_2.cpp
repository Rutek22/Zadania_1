#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>

int czyPoprawne(const std::string& line, int max_czerwone, int max_zielone, int max_niebieskie, int& sumaMocy) {
    int result = 1;
    int indexStart = 0;
    int currRed = 0;
    int currBlue = 0;
    int currGreen = 0;

    size_t length = line.length();

    for (size_t i = 0; i < length; i++) {
        if (line[i] == ':') {
            indexStart = i + 1;
            break;
        }
    }

    for (size_t i = indexStart; i < length; i++) {
        std::string number;

        if (std::isdigit(line[i])) {
            while (std::isdigit(line[i])) {
                number += line[i++];
            }

            int num = std::atoi(number.c_str());

            if (line[i + 1] == 'r') {
                if (currRed < num) {
                    currRed = num;
                }
            } else if (line[i + 1] == 'b') {
                if (currBlue < num) {
                    currBlue = num;
                }
            } else if (line[i + 1] == 'g') {
                if (currGreen < num) {
                    currGreen = num;
                }
            }
        }
    }

    if (max_czerwone < currRed || max_zielone < currGreen || max_niebieskie < currBlue) {
        result = -1;
    }

    sumaMocy += currRed * currBlue * currGreen;

    std::cout << std::setw(5) << currRed << " czerwonych, " << std::setw(5) << currBlue << " niebieskich, " << std::setw(5) << currGreen << " zielonych\n";

    return result;
}

int getIndex(const std::string& line) {
    int index = 0;

    size_t length = line.length();

    for (size_t i = 0; i < length; i++) {
        if (std::isdigit(line[i])) {
            size_t j = i;
            while (std::isdigit(line[j])) {
                index = index * 10 + (line[j] - '0');
                j++;
            }
            break;
        }
    }

    return index;
}

int main() {
    std::ifstream file("input2.txt");
    std::string line;
    int sumaIndeksow = 0;
    int sumaMocy = 0;

    if (!file.is_open()) {
        std::cout << "Nie można otworzyć pliku!!!";
        return 1;
    }

    while (std::getline(file, line)) {
        std::cout << "Gra: " << std::setw(3) << getIndex(line) << " - ";
        if ((czyPoprawne(line, 12, 13, 14, sumaMocy)) == 1) {
            sumaIndeksow += getIndex(line);
        }
    }

    std::cout << "Suma Indeksow: " << sumaIndeksow << std::endl;
    std::cout << "Suma Mocy: " << sumaMocy << std::endl;

    file.close();

    return 0;
}
