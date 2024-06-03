/**
 * Klasa reprezentująca grę w szachy
 */

#ifndef PROJEKT_KONCOWY_GAME_H
#define PROJEKT_KONCOWY_GAME_H

#include <set>
#include <iostream>
#include "board.h"
#include "piece.h"
#include "player.h"

using namespace std;

class Game {
public:
    /*
     * Destruktor
     */
    ~Game();

    /*
     * Ustawienie nowej gry w szachy
     *
     */
    static void initialize();

    /*
    * Pobranie gracza, którego jest teraz kolej
    *
    * @return gracz
    */
    static Player* getNextPlayer();

    /*
    * Pobranie przeciwnika danego gracza
    *
    * @param player gracz
    * @return przeciwnik
    */
    static Player* opponentOf(Player& player);

private:

    /*
     * Utworzenie gry
     */
    Game();

    // Prywatne atrybuty
    static Player* player1;
    static Player* player2;
    static Player* nextPlayer;
    static set<Piece*> whitePieces;
    static set<Piece*> blackPieces;
};

#endif //PROJEKT_KONCOWY_GAME_H
