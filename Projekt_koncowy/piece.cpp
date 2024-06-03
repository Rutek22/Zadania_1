/*
 * Implementacja klasy Piece reprezentującej figurę
 */

#include <string>     // Dołączenie biblioteki string dla std::string
#include "piece.h"    // Dołączenie pliku nagłówkowego klasy Piece
#include "player.h"   // Dołączenie pliku nagłówkowego klasy Player

// Konstruktor klasy Piece
Piece::Piece(bool isWhite) : _isWhite(isWhite), _square(NULL) {
    // Ustalenie koloru figury na podstawie parametru isWhite
    if(isWhite)
        _color = "W";  // Biała figura
    else
        _color = "B";  // Czarna figura
}

// Destruktor klasy Piece
Piece::~Piece() {
    // Destruktor domyślny
}

// Metoda moveTo - przenosi figurę na określony kwadrat, sprawdzając legalność ruchu
bool Piece::moveTo(Player& byPlayer, Square& toSquare) {
    bool validMove = false;
    Piece* toCapture = NULL;  // Wskaźnik na figurę do schwytania
    Square* fromSquare = _square;  // Kwadrat, z którego figura się porusza

    // Sprawdzenie, czy ruch wykonywany jest przez właściciela figury
    if(_isWhite == byPlayer.isWhite()) {
        // Sprawdzenie, czy ruch jest zgodny z geometrią ruchu figury
        if(canMoveTo(toSquare)) {
            // Sprawdzenie, czy kwadrat toSquare jest zajęty przez inną figurę
            if(toSquare.occupied()) {
                toCapture = toSquare.occupiedBy();  // Pobranie figury do schwytania

                // Ruch jest możliwy tylko jeśli figura do schwytania ma inny kolor
                if(toCapture->isWhite() != byPlayer.isWhite()) {
                    validMove = true;
                }
            }
            // Jeśli nie ma figury do schwytania, ruch jest bezpośrednio uznawany za prawidłowy
            else {
                validMove = true;
            }

            if(validMove) {
                // Wykonanie ruchu:
                // Tymczasowe wykonanie ruchu, przemieszczenie figury
                // Tymczasowe usunięcie schwytanej figury przeciwnika z planszy, jeśli istnieje
                if(toCapture) {
                    toCapture->setLocation(NULL);
                }

                // Usunięcie figury z jej obecnego kwadratu
                _square->setOccupier(NULL);

                // Ustawienie nowego kwadratu figury
                _square = &toSquare;

                // Ustawienie figury na nowym kwadracie
                _square->setOccupier(this);

                // Sprawdzenie, czy ruch nie wystawia króla gracza byPlayer na szach
                if(byPlayer.inCheck()) {
                    // Jeśli wystawia na szach, ruch jest nieprawidłowy
                    validMove = false;

                    // Cofnięcie wykonanego ruchu:
                    // Przywrócenie pierwotnej lokalizacji figury
                    _square = fromSquare;

                    // Aktualizacja obecnego kwadratu figury
                    _square->setOccupier(this);

                    // Przywrócenie schwytanej figury przeciwnika na jej pierwotną lokalizację, jeśli była
                    toSquare.setOccupier(toCapture);

                    // Jeśli była schwytana figura, przywrócenie jej pierwotnej lokalizacji
                    if(toCapture) {
                        toCapture->setLocation(&toSquare);
                    }
                }
                else {
                    // Jeśli nie wystawia na szach, ruch jest prawidłowy, więc następuje faktyczne schwytanie figury przeciwnika
                    if(toCapture) {
                        byPlayer.capture(toCapture);
                    }
                }
            }
        }
    }

    return validMove;
}

// Metoda setLocation - ustawia obecną lokalizację figury na planszy
void Piece::setLocation(Square* location) {
    _square = location;
}

// Metoda isWhite - zwraca true, jeśli figura jest biała, w przeciwnym razie false
bool Piece::isWhite() const {
    return _isWhite;
}

// Metoda color - zwraca kolor figury jako string ("W" dla białej, "B" dla czarnej)
string Piece::color() const {
    return _color;
}

// Metoda isOnSquare - zwraca true, jeśli figura znajduje się na kwadracie, w przeciwnym razie false
bool Piece::isOnSquare() const {
    return _square;
}

// Metoda location - zwraca wskaźnik na kwadrat, na którym znajduje się figura
Square* Piece::location() const {
    return _square;
}
