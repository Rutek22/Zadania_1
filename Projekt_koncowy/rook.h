/*
 * Ta klasa reprezentuje wieże
 */

#ifndef PROJEKT_KONCOWY_ROOK_H
#define PROJEKT_KONCOWY_ROOK_H

#include <iostream>           // do użycia strumieni wejścia i wyjścia
#include "restrictedPiece.h"  // zawiera deklaracje klasy bazowej RestrictedPiece
#include "square.h"           // zawiera deklaracje klasy Square

using namespace std;

/*
 * Klasa reprezentująca figurę wieży w szachach, dziedzicząca po klasie RestrictedPiece.
 */
class Rook : public RestrictedPiece {
public:
    /*
    * Konstruktor tworzący wieżę.
    *
    * @param isWhite określa kolor figury (true dla białego, false dla czarnego)
    */
    Rook(bool isWhite);

    /*
     * Domyślny destruktor.
     */
    ~Rook();

    /*
    * Metoda zwracająca wartość punktową figury.
    *
    * @return wartość wieży
    */
    int value() const;

    /*
    * Metoda sprawdzająca, czy figura może legalnie przesunąć się na podane pole.
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


#endif //PROJEKT_KONCOWY_ROOK_H
