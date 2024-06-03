/*
 * Klasa reprezentująca figurę królowej
 */

#ifndef PROJEKT_KONCOWY_QUEEN_H
#define PROJEKT_KONCOWY_QUEEN_H

#include <iostream>  // do użycia strumieni wejścia i wyjścia
#include "square.h"  // zawiera deklaracje klasy Square
#include "piece.h"   // zawiera deklaracje klasy Piece

using namespace std;

/*
 * Klasa reprezentująca figurę królowej w szachach, dziedzicząca po klasie Piece.
 */
class Queen: public Piece {
public:
    /*
    * Konstruktor tworzący królową.
    *
    * @param isWhite określa kolor figury (true dla białego, false dla czarnego)
    */
    Queen(bool isWhite);

    /*
     * Domyślny destruktor.
     */
    ~Queen();

    /*
    * Metoda zwracająca wartość punktową figury.
    *
    * @return wartość królowej
    */
    int value() const;

    /*
    * Metoda sprawdzająca, czy figura może legalnie przesunąć się na podane pole.
    * Królowa może poruszać się jak wieża (po pionie i poziomie) oraz jak goniec (po przekątnych).
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

#endif //PROJEKT_KONCOWY_QUEEN_H
