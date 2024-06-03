/*
 * Implementacja klasy RestrictedPiece reprezentującej figurę, z informacje o tym czy była już przesunięta
 */

#include "player.h"             // Dołączenie pliku nagłówkowego player.h
#include "restrictedPiece.h"    // Dołączenie pliku nagłówkowego restrictedPiece.h

/*
 * Konstruktor klasy RestrictedPiece
 * Ustawienie początkowego stanu, że figura nie została jeszcze przesunięta
 */
RestrictedPiece::RestrictedPiece(bool isWhite) : Piece(isWhite) {
    _moved = false;
}

// Destruktor klasy RestrictedPiece
RestrictedPiece::~RestrictedPiece() {
}

// Metoda moveTo - próba przesunięcia figury na nową pozycję
bool RestrictedPiece::moveTo(Player& byPlayer, Square& to) {
    // Wywołanie metody moveTo z klasy bazowej Piece
    bool validMove = Piece::moveTo(byPlayer, to);

    // Zmiana flagi _moved tylko jeśli ruch jest legalny
    // i ta figura nie została jeszcze przesunięta
    if(validMove && !_moved) {
        _moved = true; // Ustawienie flagi na true, oznaczającej, że figura została już przesunięta
    }

    return validMove; // Zwrócenie wartości, czy ruch był legalny
}

// Metoda hasMoved - sprawdzenie, czy figura została już wcześniej przesunięta
bool RestrictedPiece::hasMoved() const {
    return _moved; // Zwrócenie wartości flagi _moved, która określa, czy figura została już przesunięta
}
