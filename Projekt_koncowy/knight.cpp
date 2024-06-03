/*
 * Implementacja klasy Knight reprezentującej figurę skoczka
 */

#include "knight.h"     // Dołączenie pliku nagłówkowego z deklaracją klasy Knight

/*
 * Konstruktor klasy Knight.
 * Wywołuje konstruktor klasy bazowej Piece, przekazując informację o kolorze figury.
 *
 * @param isWhite określa kolor figury (true dla białego, false dla czarnego)
 */
Knight::Knight(bool isWhite) : Piece(isWhite) {
}

/*
 * Destruktor klasy Knight.
 */
Knight::~Knight() {
}

/*
 * Metoda zwracająca wartość punktową figury skoczka.
 *
 * @return wartość skoczka (3 punkty)
 */
int Knight::value() const {
    return 3;
}

/*
 * Metoda sprawdzająca, czy figura może legalnie przesunąć się na podane pole.
 * Skoczek może poruszać się w "L" (skok o 2 pola w jednym kierunku i 1 pole prostopadle do niego).
 *
 * @param location pole, na które figura ma się przesunąć
 * @return true, jeśli ruch jest legalny; w przeciwnym razie false
 */
bool Knight::canMoveTo(Square& location) const {
    bool validMove = false;
    int translationX = location.getX() - this->location()->getX();  // różnica współrzędnych X
    int translationY = location.getY() - this->location()->getY();  // różnica współrzędnych Y

    // Sprawdzenie, czy figura porusza się o 1 pole do przodu/tyłu
    // i o 2 pola na boki
    if(abs(translationY) == 1 && abs(translationX) == 2) {
        validMove = true;
    }

    // Sprawdzenie, czy figura porusza się o 1 pole na boki
    // i o 2 pola do przodu/tyłu
    else if(abs(translationX) == 1 && abs(translationY) == 2) {
        validMove = true;
    }

    return validMove;
}

/*
 * Metoda wyświetlająca figurę skoczka na strumieniu wyjściowym.
 * Wyświetla kolor figury i literę "N".
 */
void Knight::display() const {
    cout << _color + "N";  // Wyświetla kolor figury (biały lub czarny) oraz literę "N"
}
