/**
 * Klasa reprezentująca pionka szachowego.
 */

#ifndef PROJEKT_KONCOWY_PAWN_H
#define PROJEKT_KONCOWY_PAWN_H

#include <iostream>  // do użycia strumieni wejścia i wyjścia
#include "square.h"  // zawiera deklarację klasy Square
#include "restrictedPiece.h"  // zawiera deklarację klasy RestrictedPiece

/*
 * Klasa reprezentująca figurę pionka w szachach, dziedzicząca po klasie RestrictedPiece.
 */
class Pawn : public RestrictedPiece {
public:
    /**
    * Tworzy pionka
    *
    * @param isWhite kolor pionka
    */
    Pawn(bool isWhite);

    /*
     * Domyślny destruktor
     */
    ~Pawn();

    /*
    * Ustawia kwadrat, na którym znajduje się pionek
    *
    * @param location kwadrat
    */
    void setLocation(Square* location);

    /*
    * Zwraca wartość punktową pionka
    *
    * @return wartość
    */
    int value() const;

    /*
     * Przenosi pionka na inny kwadrat.
     *
     * @return sukces przeniesienia
     */
    bool moveTo(Player& byPlayer, Square& to);

    /*
    * Określa, czy pionek może legalnie przesunąć się na dany kwadrat
    * na podstawie geometrii ruchu
    *
    * @param location kwadrat docelowy
    * @return czy ruch jest legalny
    */
    bool canMoveTo(Square& location) const;

    /*
    * Wyświetla pionka
    * @param outStream strumień wyjściowy
    */
    void display() const;


private:
    // Prywatne atrybuty
    Piece* _delegate;  // Delegat odpowiedzialny za szczegółowe zachowanie pionka
};

#endif //PROJEKT_KONCOWY_PAWN_H
