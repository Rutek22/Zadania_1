/*
 * Klasa reprezentująca figurę króla
 */

#ifndef PROJEKT_KONCOWY_KING_H
#define PROJEKT_KONCOWY_KING_H

#include <iostream>  // do użycia strumieni wejścia i wyjścia
#include "restrictedPiece.h"  // zawiera deklaracje klasy RestrictedPiece

using namespace std;

/*
 * Klasa reprezentująca figurę króla w szachach, dziedzicząca po klasie RestrictedPiece.
 */
class King : public RestrictedPiece {
public:
    /*
    * Konstruktor tworzący króla.
    *
    * @param isWhite określa kolor figury (true dla białego, false dla czarnego)
    */
    King(bool isWhite);

    /*
     * Domyślny destruktor.
     */
    ~King();

    /*
    * Metoda zwracająca wartość punktową figury.
    *
    * @return wartość króla (wartość krytyczna, nie liczona w sposób formalny)
    */
    int value() const;

    /*
    * Metoda sprawdzająca, czy figura może legalnie przesunąć się na podane pole.
    * Król może poruszać się na każde sąsiednie pole (poziomo, pionowo, na ukos).
    *
    * @param location pole, na które figura ma się przesunąć
    * @return true, jeśli ruch jest legalny; w przeciwnym razie false
    */
    bool canMoveTo(Square& location) const;

    /*
     * Metoda wyświetlająca figurę króla.
     *
     * @param outStream strumień wyjściowy, do którego ma być wyświetlona figura
     */
    void display() const;
};

#endif //PROJEKT_KONCOWY_KING_H
