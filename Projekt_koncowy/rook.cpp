/*
 * Implementacja klasy Rook reprezentującej figurę wieży
 */

#include "rook.h"       // Dołączenie pliku nagłówkowego z deklaracją klasy Rook

/*
 * Konstruktor klasy Rook.
 * Wywołuje konstruktor klasy bazowej RestrictedPiece, przekazując informację o kolorze figury.
 *
 * @param isWhite określa kolor figury (true dla białego, false dla czarnego)
 */
Rook::Rook(bool isWhite) : RestrictedPiece(isWhite) {
}

/*
 * Destruktor klasy Rook.
 */
Rook::~Rook() {
}

/*
 * Metoda zwracająca wartość punktową figury wieży.
 *
 * @return wartość wieży (5 punktów)
 */
int Rook::value() const {
    return 5;
}

/*
 * Metoda sprawdzająca, czy figura może legalnie przesunąć się na podane pole.
 * Figura może przesuwać się po pionie lub poziomie bez przeszkód.
 *
 * @param location pole, na które figura ma się przesunąć
 * @return true, jeśli ruch jest legalny (ruch po pionie lub poziomie bez przeszkód); w przeciwnym razie false
 */
bool Rook::canMoveTo(Square& location) const {
    bool validMove = false;

    // Sprawdzenie, czy ruch jest legalny - ruch po pionie bez przeszkód
    if(Board::getBoard()->isClearVertical(*(this->location()), location)) {
        validMove = true;
    }

    // Sprawdzenie, czy ruch jest legalny - ruch poziomy bez przeszkód
    else if(Board::getBoard()->isClearHorizontal(*(this->location()), location)) {
        validMove = true;
    }

    return validMove;
}

/*
 * Metoda wyświetlająca figurę wieży na strumieniu wyjściowym.
 * Wyświetla kolor figury i literę "R" (od Rook).
 */
void Rook::display() const {
    cout << _color + "R";  // Wyświetla kolor figury (biały lub czarny) oraz literę "R"
}
