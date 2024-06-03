/*
 * Klasa reprezentuje figurę szachową, która przechowuje informację, czy została już wcześniej przesunięta.
 */

#ifndef PROJEKT_KONCOWY_RESTRICTEDPIECE_H
#define PROJEKT_KONCOWY_RESTRICTEDPIECE_H

#include "piece.h"  // Dołączenie pliku nagłówkowego klasy Piece

class Player;  // Deklaracja forward dla klasy Player

using namespace std;

/*
 * Klasa RestrictedPiece dziedziczy publicznie po klasie Piece.
 */
class RestrictedPiece : public Piece {
public:
    /*
    * Konstruktor tworzy obiekt RestrictedPiece
    *
    * @param isWhite określa, czy figura jest biała
    */
    RestrictedPiece(bool isWhite);

    /*
     * Domyślny destruktor
     */
    virtual ~RestrictedPiece();

    /*
    * Przenieś figurę na inne pole.
    *
    * @return true, jeśli ruch jest możliwy
    */
    virtual bool moveTo(Player& byPlayer, Square& to);

    /*
    * Sprawdź, czy figura została wcześniej przesunięta.
    *
    * @return true, jeśli figura została wcześniej przesunięta
    */
    bool hasMoved() const;

private:
    // Prywatne atrybuty
    bool _moved;  // Flaga określająca, czy figura została już wcześniej przesunięta
};


#endif //PROJEKT_KONCOWY_RESTRICTEDPIECE_H
