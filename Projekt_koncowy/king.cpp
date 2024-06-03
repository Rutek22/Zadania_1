/*
 *  Implementacja klasy King reprezentującej figurę króla
 */
#include "king.h"       // Dołączenie pliku nagłówkowego z deklaracją klasy King

/*
 * Konstruktor klasy King.
 * Wywołuje konstruktor klasy bazowej RestrictedPiece, przekazując informację o kolorze figury.
 *
 * @param isWhite określa kolor figury (true dla białego, false dla czarnego)
 */
King::King(bool isWhite) : RestrictedPiece(isWhite) {
}

/*
 * Destruktor klasy King.
 */
King::~King() {
}

/*
 * Metoda zwracająca wartość punktową figury króla.
 * W szachach król jest bezcenny, więc zwracana jest wartość 0.
 *
 * @return wartość króla (0 punktów)
 */
int King::value() const {
    return 0;
}

/*
 * Metoda sprawdzająca, czy figura może legalnie przesunąć się na podane pole.
 * Król może poruszać się na każde sąsiednie pole (poziomo, pionowo, na ukos) o jedno pole.
 *
 * @param location pole, na które figura ma się przesunąć
 * @return true, jeśli ruch jest legalny; w przeciwnym razie false
 */
bool King::canMoveTo(Square& location) const {
    bool validMove = false;
    int translationX = location.getX() - this->location()->getX();  // różnica współrzędnych X
    int translationY = location.getY() - this->location()->getY();  // różnica współrzędnych Y

    // Sprawdzenie, czy figura porusza się o 1 pole do przodu/tyłu
    if(abs(translationY) == 1 && translationX == 0) {
        validMove = true;
    }

    // Sprawdzenie, czy figura porusza się o 1 pole na boki
    else if(abs(translationX) == 1 && translationY == 0) {
        validMove = true;
    }

    // Sprawdzenie, czy figura porusza się o 1 pole na przekątne
    else if(abs(translationX) == 1 && abs(translationY) == 1) {
        validMove = true;
    }

    return validMove;
}

/*
 * Metoda wyświetlająca figurę króla na strumieniu wyjściowym.
 * Wyświetla kolor figury i literę "K" (od King).
 */
void King::display() const {
    cout << _color + "K";  // Wyświetla kolor figury (biały lub czarny) oraz literę "K"
}
