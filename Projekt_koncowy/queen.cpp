/*
 *  Implementacja klasy Queen reprezentującej figurę królowej w szachach.
 */
#include "queen.h"      // Dołączenie pliku nagłówkowego z deklaracją klasy Queen

/*
 * Konstruktor klasy Queen.
 * Wywołuje konstruktor klasy bazowej Piece, przekazując informację o kolorze figury.
 *
 * @param isWhite określa kolor figury (true dla białego, false dla czarnego)
 */
Queen::Queen(bool isWhite) : Piece(isWhite) {
}

/*
 * Destruktor klasy Queen.
 */
Queen::~Queen() {
}

/*
 * Metoda zwracająca wartość punktową figury królowej.
 *
 * @return wartość królowej (9 punktów)
 */
int Queen::value() const {
    return 9;
}

/*
 * Metoda sprawdzająca, czy figura może legalnie przesunąć się na podane pole.
 * Królowa może poruszać się jak wieża (po pionie i poziomie) oraz jak goniec (po przekątnych).
 *
 * @param location pole, na które figura ma się przesunąć
 * @return true, jeśli ruch jest legalny; w przeciwnym razie false
 */
bool Queen::canMoveTo(Square& location) const {
    bool validMove = false;

    // Sprawdzenie, czy figura porusza się po pionie bez przeszkód
    if(Board::getBoard()->isClearVertical(*(this->location()), location)) {
        validMove = true;
    }

    // Sprawdzenie, czy figura porusza się poziomie bez przeszkód
    else if(Board::getBoard()->isClearHorizontal(*(this->location()), location)) {
        validMove = true;
    }

    // Sprawdzenie, czy figura porusza się po przekątnych bez przeszkód
    else if(Board::getBoard()->isClearDiagonal(*(this->location()), location)) {
        validMove = true;
    }

    return validMove;
}

/*
 * Metoda wyświetlająca figurę królowej na strumieniu wyjściowym.
 * Wyświetla kolor figury i literę "Q" (od Queen).
 */
void Queen::display() const {
    cout << _color + "Q";  // Wyświetla kolor figury (biały lub czarny) oraz literę "Q"
}
