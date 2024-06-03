/*
 * Implementacja klasy Bishop reprezentującej gońca
 */

#include "bishop.h"     // Dołączenie pliku nagłówkowego z deklaracją klasy Bishop

/*
 * Konstruktor klasy Bishop
 * Wywołuję konstruktor klasy bazowej Piece, przekazując informacje o kolorze figury.
 *
 * @param isWhite określa kolor figury (true dla białego, false dla czarnego)
 */
Bishop::Bishop(bool isWhite) : Piece(isWhite) {
}

/*
 * Destruktor klasy Bishop.
 */
Bishop::~Bishop() {
}

/*
 * Metoda zwracająca wartość punktową figury gońca.
 *
 * @return wartość gońca (3 punkty)
 */
int Bishop::value() const {
    return 3;
}

/*
 * Metoda sprawdzająca, czy figura może legalnie przesunąć się na podane pole.
 *
 * @param location pole, na które figura ma się przesunąć
 * @return true, jeśli ruch jest legalny (ruch po przekątnej bez przeszkód); w przeciwnym razie false
 */
bool Bishop::canMoveTo(Square& location) const {
    bool validMove = false;

    // Sprawdzenie, czy ruch jest legalny - ruch po przekątnej bez przeszkód
    if(Board::getBoard()->isClearDiagonal(*(this->location()), location)) {
        validMove = true;
    }

    return validMove;
}

/*
 * Metoda wyświetlająca figurę gońca na strumieniu wyjściowym.
 * Wyświetla kolor figury i literę "B" (od Bishop).
 */
void Bishop::display() const {
    cout << _color + "B";  // Wyświetla kolor figury (biały lub czarny) oraz literę "B"
}
