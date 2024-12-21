#ifndef BOARD_H
#define BOARD_H


#include "Piece.h"
#include "Blank.h"
#include "MyLibrary.h"

typedef pair <int, int> ii;

using namespace  std;


class Board{
public: 
    Piece* matrix[10][10];
    vector <pair <char, pair<ii, ii>>> all_piece_moves;
    int kingx[2], kingy[2];
    int rep;
    map <string, int> cntBoard;

    Board();
    void placePiece(Piece* piece, int x, int y);
    Piece* getPiece(int x, int y);
    void printBoard();
};
#endif // BOARD_H
