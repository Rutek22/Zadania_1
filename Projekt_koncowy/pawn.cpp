/*
 *  pawn.cpp
 *  ChessProject
 *
 */

#include "pawn.h"
#include "queen.h"
#include "board.h"

Pawn::Pawn(bool isWhite) : RestrictedPiece(isWhite), _delegate(NULL)
{
    // Konstruktor pionka
    // Ustawienie koloru i początkowe ustawienie delegata na NULL
}

Pawn::~Pawn()
{
    // Destruktor pionka
    if(_delegate)
        delete _delegate; // Zwolnienie delegata, jeśli istnieje
}

void Pawn::setLocation(Square* location)
{
    Piece::setLocation(location); // Ustawienie nowego położenia pionka
}

int Pawn::value() const
{
    return 1; // Wartość punktowa pionka (w szachach pionek ma zazwyczaj wartość 1)
}

bool Pawn::moveTo(Player& byPlayer, Square& to)
{
    bool valid = false;

    // Jeśli pionek został promowany
    if(_delegate)
    {
        // Użyj reguł ruchu delegata, aby określić jego legalność
        valid = _delegate->moveTo(byPlayer, to);

        // Jeśli ruch jest legalny, przesuń pionka
        if(valid)
        {
            // Zwalnianie poprzedniego miejsca pionka
            location()->setOccupier(NULL);

            // Ustawienie nowego miejsca pionka
            setLocation(&to);

            // Ustawienie nowego zajmującego miejsca
            location()->setOccupier(this);
        }
    }
    else
    {
        // W przeciwnym razie próba normalnego ruchu jako pionek
        valid = RestrictedPiece::moveTo(byPlayer, to);

        // Jeśli ruch jest legalny i pionek dotarł do krawędzi przeciwnika
        if(valid)
        {
            if(Board::getBoard()->isEndRow(*location()))
            {
                // Promuj pionka do królowej
                _delegate = new Queen(isWhite());
                _delegate->setLocation(location());
            }
        }
    }

    return valid;
}

bool Pawn::canMoveTo(Square& location) const
{
    bool validMove = false;
    int translationX = location.getX() - this->location()->getX();
    int translationY = location.getY() - this->location()->getY();

    // Jeśli pionek został promowany, użyj reguł ruchu delegata
    if(_delegate)
    {
        validMove = _delegate->canMoveTo(location);
    }
    else
    {
        // W przeciwnym razie użyj normalnych reguł ruchu pionka
        // ("do przodu" jest "do tyłu" względem planszy dla czarnych pionków)
        if(!isWhite())
        {
            translationX *= -1;
            translationY *= -1;
        }

        // Ruch jest legalny, jeśli przesuwamy się o 1 pole do przodu na niezajęte pole
        if(!location.occupied() && translationY == 1 && translationX == 0)
        {
            validMove = true;
        }

            // Ruch jest legalny, jeśli pionek nie ruszał się wcześniej i przesuwamy się o 2 pola do przodu
            // na niezajęte pole wzdłuż czystej linii pionowej
        else if(!hasMoved() && translationY == 2 && translationX == 0 &&
                Board::getBoard()->isClearVertical(*(this->location()), location))
        {
            validMove = true;
        }

            // Ruch jest legalny, jeśli bierzemy pionek na sąsiedniej przekątnej
        else if(location.occupied() && translationY == 1 &&
                (translationX == 1 || translationX == -1))
        {
            validMove = true;
        }
    }

    return validMove;
}

void Pawn::display() const
{
    if(_delegate)
    {
        _delegate->display(); // Wyświetlenie delegata (zazwyczaj królowej, do której pionek został promowany)
    }
    else
    {
        cout << _color + "P"; // Wyświetlenie symbolu pionka (P dla białego, p dla czarnego)
    }
}
