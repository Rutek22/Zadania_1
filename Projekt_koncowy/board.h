/*
 * Klasa reprezentująca planszę do gry.
 */

#ifndef PROJEKT_KONCOWY_BOARD_H
#define PROJEKT_KONCOWY_BOARD_H

#include <ostream>
#include "square.h"

using namespace std;

class Board {
public:
    /*
     * Domyślny destruktor
     */
    ~Board();

    /*
    * Pobierz instancję planszy
    *
    * @return instancja planszy
    */
    static Board* getBoard();

    /*
    * Pobierz konkretny kwadrat na planszy
    *
    * @params x, y współrzędne kwadratu na planszy
    * @return obiekt kwadratu
    */
    Square* squareAt(int x, int y) const;

    /*
    * Określ, czy ścieżka między dwoma kwadratami jest czysto pionowa
    *
    * @param from początkowy kwadrat
    * @param to docelowy kwadrat
    * @return true, jeśli ścieżka jest czysto pionowa, w przeciwnym razie false
    */
    bool isClearVertical(Square& from, Square& to) const;

    /*
    * Określ, czy ścieżka między dwoma kwadratami jest czysto pozioma
    *
    * @param from początkowy kwadrat
    * @param to docelowy kwadrat
    * @return true, jeśli ścieżka jest czysto pozioma, w przeciwnym razie false
    */
    bool isClearHorizontal(Square& from, Square& to) const;

    /*
    * Określ, czy ścieżka między dwoma kwadratami jest czysto diagonalna
    *
    * @param from początkowy kwadrat
    * @param to docelowy kwadrat
    * @return true, jeśli ścieżka jest czysto diagonalna, w przeciwnym razie false
    */
    bool isClearDiagonal(Square& from, Square& to) const;

    /*
     * Określ, czy kwadrat znajduje się na końcowym rzędzie planszy
     *
     * @param location kwadrat do sprawdzenia
     * @return true, jeśli kwadrat znajduje się na końcowym rzędzie, w przeciwnym razie false
     */
    bool isEndRow(Square& location) const;

    /*
    * Wyświetl planszę do strumienia wyjściowego
    *
    * @param outStream strumień wyjściowy do wyświetlenia planszy
    */
    void display(ostream& outStream) const;


private:

    /*
     * Tworzy planszę 8x8 z zainicjalizowanymi kwadratami
     */
    Board();

    // Prywatne atrybuty
    static Board* _theBoard; // Statyczna instancja planszy
    static const int _DIMENSION = 8; // Wymiar planszy
    Square* _squares[_DIMENSION][_DIMENSION]; // Tablica 2D wskaźników na kwadraty reprezentująca planszę
};


#endif //PROJEKT_KONCOWY_BOARD_H
