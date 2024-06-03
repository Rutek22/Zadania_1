/*
 * Klasa reprezentująca gracza
 */

#ifndef PROJEKT_KONCOWY_PLAYER_H
#define PROJEKT_KONCOWY_PLAYER_H

#include <set>
#include "piece.h"
#include "king.h"

using namespace std;

class Player {
public:
    /*
     * Tworzy gracza.
     *
     * @param name nazwa gracza
     * @param isWhite czy gracz gra białymi
     * @param myKing referencja do króla gracza
     * @param myPieces zbiór referencji do figur gracza
     */
    Player(string name, bool isWhite, King& myKing, set<Piece*>& myPieces);

    /*
     * Destruktor
     */
    ~Player();

    /*
     * Wykonuje ruch.
     *
     * @return czy ruch został wykonany pomyślnie
     */
    bool makeMove();

    /*
     * Sprawdza, czy gracz jest w szachu.
     *
     * @return czy w szachu
     */
    bool inCheck();

    /*
     * Zbiera (zbija) figurę przeciwnika.
     *
     * @param aPiece wskaźnik do zbitej figury
     */
    void capture(Piece* aPiece);

    /*
     * Zwraca nazwę gracza.
     *
     * @return nazwa gracza
     */
    string getName() const;

    /*
     * Sprawdza, czy gracz gra białymi.
     *
     * @return czy gra białymi
     */
    bool isWhite() const;

    /*
    * Zwraca całkowity wynik zdobytych figur.
    *
    * @return wynik
    */
    int score() const;

    /*
     * Zwraca zbiór figur gracza.
     *
     * @return zbiór figur
     */
    set<Piece*>* myPieces() const;

    /*
     * Zwraca króla gracza.
     *
     * @return król gracza
     */
    King* myKing() const;

private:
    // Prywatne atrybuty
    string _name;               // Nazwa gracza
    bool _isWhite;              // Czy gracz gra białymi
    set<Piece*>& _myPieces;     // Zbiór figur gracza (referencje)
    set<Piece*> _capturedPieces; // Zbiór zbitych figur
    King& _myKing;              // Referencja do króla gracza
};

#endif //PROJEKT_KONCOWY_PLAYER_H
