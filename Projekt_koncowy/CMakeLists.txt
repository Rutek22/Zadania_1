cmake_minimum_required(VERSION 3.27)
project(Projekt_koncowy)

set(CMAKE_CXX_STANDARD 17)

add_executable(Projekt_koncowy
        bishop.cpp
        bishop.h
        board.cpp
        board.h
        game.cpp
        game.h
        king.cpp
        king.h
        knight.cpp
        knight.h
        main.cpp
        pawn.cpp
        pawn.h
        piece.cpp
        piece.h
        player.cpp
        player.h
        queen.cpp
        queen.h
        restrictedPiece.cpp
        restrictedPiece.h
        rook.cpp
        rook.h
        square.cpp
        square.h)
