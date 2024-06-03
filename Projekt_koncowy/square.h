/**
 * Klasa reprezentująca kwadrat na planszy gry.
 */

#ifndef PROJEKT_KONCOWY_SQUARE_H
#define PROJEKT_KONCOWY_SQUARE_H

class Piece; // Deklaracja klasy Piece, aby uniknąć problemów z cyklicznymi zależnościami

using namespace std;

class Square {
public:
    /*
    * Tworzy kwadrat na planszy.
    *
    * @params x, y lokalizacja kwadratu na planszy
    */
    Square(int x, int y);

    /*
     * Domyślny destruktor
     */
    ~Square();

    /*
    * Ustawia figurę, która zajmuje kwadrat.
    *
    * @param piece figura na kwadracie
    */
    void setOccupier(Piece* piece);

    /*
    * Zwraca pozycję X kwadratu.
    *
    * @return pozycja X
    */
    int getX() const;

    /*
    * Zwraca pozycję Y kwadratu.
    *
    * @return pozycja Y
    */
    int getY() const;

    /*
    * Sprawdza, czy kwadrat jest zajęty przez figurę.
    *
    * @return true, jeśli jest zajęty; false w przeciwnym razie
    */
    bool occupied() const;

    /*
    * Zwraca figurę, która znajduje się na kwadracie.
    *
    * @return figura na kwadracie
    */
    Piece* occupiedBy() const;

private:
    // Prywatne atrybuty
    int _x;       // Pozycja X kwadratu na planszy
    int _y;       // Pozycja Y kwadratu na planszy
    Piece* _piece; // Wskaźnik do figury na kwadracie
};


#endif //PROJEKT_KONCOWY_SQUARE_H
