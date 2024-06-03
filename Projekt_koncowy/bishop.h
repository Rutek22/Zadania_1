/*
 * Ta klasa reprezentuje gońca.
 */

#ifndef PROJEKT_KONCOWY_BISHOP_H
#define PROJEKT_KONCOWY_BISHOP_H

#include <iostream>     // do użycia strumieni wejścia i wyjścia
#include "piece.h"      // zawiera deklaracje klasy bazowej Piece
#include "square.h"     // zawiera deklaracje klasy Square

using namespace std;

/*
 * Klasa reprezentuje figurę gońca, dziedzicząca po klasie Piece
 */
class Bishop : public Piece {
public:
    /*
     * Konstruktor tworzący gońca
     *
     * @param isWhite określa kolor figury (true dla białego, false dla czarnego)
     */
    Bishop(bool isWhite);

    /*
     * Domyślny destruktor
     */
    ~Bishop();

    /*
     * Metoda zwracająca wartość punktową figury
     *
     * @return wartość gońca
     */
    int value() const;

    /*
     * Metoda sprawdzająca, czy figura może legalnie przesunąć się na podane pole
     *
     * @param location pole, na które figura ma się przesunąć
     * @return true, jeśli ruch jest legalny; w przeciwnym razie false
     */
    bool canMoveTo(Square& location) const;

    /*
     * Metoda wyświetlająca figurę
     *
     * @param outStream strumień wyjściowy, do którego ma być wyświetlona figura
     */
    void display() const;
};

#endif //PROJEKT_KONCOWY_BISHOP_H
