#include <iostream> // użycie strumieni wejścia i wyjścia
#include "game.h"   // zawiera deklaracje funkcji i klas związanych z grą
#include "board.h"  // zawiera deklaracje funkcji i klas związanych z planszą

/*
 * Główny program do gry w szachy:
 *
 * Etapy:
 *  1. Inicjalizacja gry i wyświetlenie początkowego stanu planszy.
 *  2. Pętla gry, w której gracze na przemian wykonują ruchy.
 *  3. Sprawdzenie poprawności ruchu i wyświetlenie odpowiedniego komunikatu w przypadku błędu.
 *  4. Wyświetlenie aktualnego stanu planszy po każdym ruchu.
 */

int main() {
    Player* currentPlayer = NULL; // wskażnik na obecnego gracza

    // Inicjalizacja gry w szachy i wyświetlenie początkowego stanu planszy
    Game::initialize();
    Board::getBoard()->display(cout);

    // Główna pętla programu, w której gracze na przemian wykonują ruchy
    while (true) {
        currentPlayer = Game::getNextPlayer();

        // Pętla, która ponawia próbę dopóki gracz nie wykona prawidłowego ruchu
        while (!currentPlayer->makeMove()) {
            // Komunikat o nieprawidłowym ruchu
            cerr << "Nieprawidłowy ruch... Spróbuj ponownie" << endl;
        }

        // Wyświetlenie stanu planszy po wykonanym ruchu
        Board::getBoard()->display(cout);
    }

    return 0;
}
