/*
 *  Implementacja metod klasy Square
 */

#include "piece.h"
#include "square.h"

// Konstruktor klasy Square
Square::Square(int x, int y) : _x(x), _y(y), _piece(NULL) {
}

// Destruktor klasy Square
Square::~Square() {
}

// Ustawia figurę, która zajmuje kwadrat
void Square::setOccupier(Piece* piece) {
    _piece = piece;
}

// Zwraca pozycję X kwadratu na planszy
int Square::getX() const {
    return _x;
}

// Zwraca pozycję Y kwadratu na planszy
int Square::getY() const {
    return _y;
}

// Sprawdza, czy kwadrat jest zajęty przez figurę
bool Square::occupied() const {
    return _piece != NULL; // Zwraca true, jeśli na kwadracie znajduje się figura, w przeciwnym razie false
}

// Zwraca wskaźnik do figury, która zajmuje ten kwadrat (lub NULL, jeśli kwadrat jest pusty)
Piece* Square::occupiedBy() const {
    return _piece;
}
