#ifndef PLAYER_H
#define PLAYER_H


#include "Piece.h"
#include "Board.h"
#include "MyLibrary.h"
using namespace  std;



class Player {
public:public:
    int turn, isP; 
    Player(int turn, int isP);
    //int MyTurn(Board &board, int isP);
};
#endif // PLAYER_H
