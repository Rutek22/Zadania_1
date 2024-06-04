/*
 * Implementacja metod klasy Player.
 */

#include <iostream>
#include "player.h"
#include "board.h"
#include "game.h"

#define X_MIN 'a'
#define X_MAX 'h'
#define Y_MIN '1'
#define Y_MAX '8'

// Konstruktor Player
Player::Player(string name, bool isWhite, King& myKing, set<Piece*>& myPieces) :
        _name(name), _isWhite(isWhite), _myPieces(myPieces), _myKing(myKing)
{
    // Inicjalizacja właściwości gracza
}

// Destruktor Player
Player::~Player() {
}

// Metoda wykonująca ruch
bool Player::makeMove()
{
    string badInput; // Zmienna do przechowywania nieprawidłowego wejścia
    string fromSquare =  "  ";
    string toSquare = "  ";
    int fromX;
    int fromY;
    int toX;
    int toY;

    // Sprawdzenie i ogłoszenie, czy gracz jest w szachu
    if(inCheck())
    {
        cout << _name << " jest w szachu!" << endl;
    }

    // Pobranie ruchu od gracza
    cout << _name << " podaj ruch (np. a2 a4): ";
    cin >> fromSquare >> toSquare;

    // Walidacja poprawności notacji ruchu i zajętości pola startowego
    while(fromSquare.length() != 2 ||
          toSquare.length() != 2 ||
          tolower(fromSquare.at(0)) < X_MIN ||
          tolower(fromSquare.at(0)) > X_MAX ||
          tolower(toSquare.at(0)) < X_MIN ||
          tolower(toSquare.at(0)) > X_MAX ||
          tolower(fromSquare.at(1)) < Y_MIN ||
          tolower(fromSquare.at(1)) > Y_MAX ||
          tolower(toSquare.at(1)) < Y_MIN ||
          tolower(toSquare.at(1)) > Y_MAX ||
          !(Board::getBoard()->squareAt(tolower(fromSquare.at(0)) - X_MIN,
                                        tolower(fromSquare.at(1)) - Y_MIN)->occupied())
            )
    {
        cerr << "Niepoprawny ruch. Sprobuj ponownie." << endl;
        cin.clear();
        getline(cin, badInput); // Usunięcie nieprawidłowego wejścia z bufora
        cout << _name << " podaj ruch (np. a2 a4): ";
        cin >> fromSquare >> toSquare;
    }

    // Przetłumaczenie notacji algebrycznej na współrzędne planszy
    fromX = tolower(fromSquare.at(0)) - X_MIN;
    fromY = tolower(fromSquare.at(1)) - Y_MIN;
    toX = tolower(toSquare.at(0)) - X_MIN;
    toY = tolower(toSquare.at(1)) - Y_MIN;

    // Wykonanie ruchu figury z pola startowego na pole docelowe
    return Board::getBoard()->squareAt(fromX, fromY)->occupiedBy()->moveTo(*this,
                                                                           *(Board::getBoard()->squareAt(toX, toY)));
}

// Metoda sprawdzająca, czy gracz jest w szachu
bool Player::inCheck()
{
    bool check = false;

    // Iteracja po figurach przeciwnika
    for (set<Piece*>::iterator itr = Game::opponentOf(*this)->myPieces()->begin();
         itr != Game::opponentOf(*this)->myPieces()->end(); ++itr)
    {
        // Sprawdzenie, czy figura może się przemieścić na pole króla
        if (((Piece*)*itr)->location() &&
            ((Piece*)*itr)->canMoveTo(*(myKing()->location())))
        {
            // Gracz jest w szachu
            check = true;
        }
    }

    return check;
}

// Metoda do zbierania zbitych figur
void Player::capture(Piece* aPiece)
{
    // Usunięcie lokalizacji figury z planszy
    aPiece->setLocation(NULL);

    // Dodanie figury do zbioru zbitych przez gracza
    _capturedPieces.insert(aPiece);
}

// Metoda zwracająca nazwę gracza
string Player::getName() const
{
    return _name;
}

// Metoda zwracająca informację, czy gracz gra białymi figurami
bool Player::isWhite() const
{
    return _isWhite;
}

// Metoda zwracająca sumaryczny wynik punktowy zbitych figur
int Player::score() const
{
    int score = 0;

    // Iteracja po zbitych figurach i sumowanie ich wartości
    for (set<Piece*>::iterator itr = _capturedPieces.begin(); itr != _capturedPieces.end(); ++itr)
    {
        score += ((Piece*)*itr)->value();
    }

    return score;
}

// Metoda zwracająca wskaźnik do zbioru figur gracza
set<Piece*>* Player::myPieces() const
{
    return &_myPieces;
}

// Metoda zwracająca wskaźnik do króla gracza
King* Player::myKing() const
{
    return &_myKing;
}
