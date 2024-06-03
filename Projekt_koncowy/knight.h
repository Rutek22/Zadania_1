/*
 * Ta klasa reprezentuje skoczka
 */

#ifndef PROJEKT_KONCOWY_KNIGHT_H
#define PROJEKT_KONCOWY_KNIGHT_H

#include <iostream>  // do użycia strumieni wejścia i wyjścia
#include "square.h"  // zawiera deklaracje klasy Square
#include "piece.h"   // zawiera deklaracje klasy Piece

using namespace std;

/*
 * Klasa reprezentująca figurę skoczka w szachach, dziedzicząca po klasie Piece.
 */
class Knight : public Piece {
public:
    /*
    * Konstruktor tworzący skoczka.
    *
    * @param isWhite określa kolor figury (true dla białego, false dla czarnego)
    */
    Knight(bool isWhite);

    /*
     * Domyślny destruktor.
     */
    ~Knight();

    /*
    * Metoda zwracająca wartość punktową figury.
    *
    * @return wartość skoczka (3 punkty)
    */
    int value() const;

    /*
    * Metoda sprawdzająca, czy figura może legalnie przesunąć się na podane pole.
    * Skoczek może poruszać się w "L" (skok o 2 pola w jednym kierunku i 1 pole prostopadle do niego).
    *
    * @param location pole, na które figura ma się przesunąć
    * @return true, jeśli ruch jest legalny; w przeciwnym razie false
    */
    bool canMoveTo(Square& location) const;

    /*
     * Metoda wyświetlająca figurę.
     *
     * @param outStream strumień wyjściowy, do którego ma być wyświetlona figura
     */
    void display() const;
};
#endif //PROJEKT_KONCOWY_KNIGHT_H
