#ifndef PIECE_H
#define PIECE_H

class Board; // Forward declaration
#include "MyLibrary.h"
using namespace  std;
class Piece{
public:
    int color, cMove; 
    char name;
    Piece();
};

#endif // PIECE_H
