/*
 * Klasa reprezentująca figurę szachową
 */

#ifndef PROJEKT_KONCOWY_PIECE_H
#define PROJEKT_KONCOWY_PIECE_H

#include <ostream>   // Dołączenie biblioteki ostream dla std::ostream
#include "square.h"  // Dołączenie pliku nagłówkowego klasy Square
#include "board.h"   // Dołączenie pliku nagłówkowego klasy Board
class Player;        // Deklaracja forward dla klasy Player

using namespace std;

class Piece {
public:
    /*
    * Konstruktor klasy Piece
    *
    * @param isWhite określa, czy figura jest biała
    */
    Piece(bool isWhite);

    /*
     * Domyślny destruktor wirtualny
     */
    virtual ~Piece();

    /*
    * Przenieś figurę na kwadrat, upewniając się, że ruch
    * jest legalny
    *
    * @param byPlayer gracz wykonujący ruch
    * @param toSquare kwadrat, na który przenoszona jest figura
    * @return true, jeśli wykonano legalny ruch
    */
    virtual bool moveTo(Player& byPlayer, Square& toSquare);

    /*
    * Ustawia, na którym kwadracie znajduje się figura
    *
    * @param location kwadrat, na którym znajduje się figura
    */
    virtual void setLocation(Square* location);

    /*
    * Pobierz wartość punktową figury
    *
    * @return wartość punktowa figury
    */
    virtual int value() const = 0;

    /*
    * Sprawdza, czy figura jest biała
    *
    * @return true, jeśli figura jest biała
    */
    bool isWhite() const;

    /*
     * Pobierz kolor figury
     *
     * @return kolor figury
     */
    string color() const;

    /*
    * Wyświetla figurę
    * @param outStream strumień wyjściowy
    */
    virtual void display() const = 0;

    /*
    * Sprawdza, czy figura może legalnie przesunąć się na dany kwadrat
    * na podstawie geometrii ruchu
    *
    * @param location kwadrat, na który figura ma się przesunąć
    * @return true, jeśli ruch jest legalny
    */
    virtual bool canMoveTo(Square& location) const = 0;

    /*
    * Sprawdza, czy figura znajduje się na kwadracie
    *
    * @return true, jeśli figura znajduje się na kwadracie
    */
    bool isOnSquare() const;

    /*
    * Pobiera położenie figury
    *
    * @return kwadrat, na którym znajduje się figura
    */
    Square* location() const;

protected:
    bool _isWhite;  // Określa, czy figura jest biała
    string _color;  // Kolor figury

private:
    Square* _square;  // Kwadrat, na którym znajduje się figura
};


#endif //PROJEKT_KONCOWY_PIECE_H
