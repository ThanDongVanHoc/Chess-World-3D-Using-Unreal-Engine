#ifndef VALIDATOR_H
#define VALIDATOR_H
#include "MyLibrary.h"
using namespace std;
#include "Board.h"
inline bool inside(int x, int y){
    return (x >= 1 && x <= 8 && y >= 1 && y <= 8);
}
class Validator{
public:
    vector <pair<int, int>> getPawnMoves(Board& board, int x, int y){
        vector<pair<int, int>> moves;
        Piece* tmp = board.matrix[x][y];
        int myTurn = tmp->color;
        int ways = (myTurn == 1 ? -1 : 1);
        int fX = x + ways;
        int fY = y;
        if(inside(fX, fY) == true){
            Piece *ftmp = board.matrix[fX][fY];
            if(ftmp -> color == -1){
                moves.push_back({fX, fY});
                if(myTurn == 0 && x == 2){
                    fX++;
                    ftmp = board.matrix[fX][fY];
                    if(ftmp -> color == -1){
                        moves.push_back({fX, fY});  
                    }
                }
                if(myTurn == 1 && x == 7){
                    fX--;
                    ftmp = board.matrix[fX][fY];
                    if(ftmp -> color == -1){
                        moves.push_back({fX, fY});  
                    }
                }
            }
        }

        fX = x + ways;
        fY = y + 1;

        int eps = myTurn ? 4 : 5;

        if(inside(fX, fY) == true){
            Piece* ftmp = board.matrix[fX][fY];
            if(ftmp -> color != -1) {
                if (ftmp -> color != myTurn) moves.push_back({fX, fY});
            }
            else {
                if (x == eps && board.matrix[x][fY]->name == 'P' && board.matrix[x][fY]->cMove == 1) // En Passant
                    moves.push_back({fX, fY});
            }
        }

        fY = y - 1;
        if(inside(fX, fY) == true){
            Piece* ftmp = board.matrix[fX][fY];
            if(ftmp -> color != -1) {
                if (ftmp -> color != myTurn) moves.push_back({fX, fY});
            }
            else {
                if (x == eps && board.matrix[x][fY]->name == 'P' && board.matrix[x][fY]->cMove == 1) // En Passant
                    moves.push_back({fX, fY});
            }
        }

        return moves;
    }

    vector<pair<int, int>> getKnightMoves(Board& board, int x, int y){
        vector<pair<int, int>> moves;
        Piece* tmp = board.matrix[x][y];
        int myTurn = tmp -> color;
        
        vector<pair<int, int>> ways = { {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
        for (pair<int, int> step : ways){
            int fX = x + step.first;
            int fY = y + step.second;
            if(inside(fX, fY) == false) continue;
            Piece * ftmp = board.matrix[fX][fY];
            if(ftmp -> color == -1){
                moves.push_back({fX, fY});
                continue;
            } 
            if(ftmp -> color != myTurn){
                moves.push_back({fX, fY});
                continue;
            }
        }
        return moves;
    }

    vector<pair<int, int>> getBishopMoves(Board& board, int x, int y){
        vector<pair<int, int>> moves;
        Piece* tmp = board.matrix[x][y];
        int myTurn = tmp -> color;
        vector<pair<int, int>> ways = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        for (pair<int, int> step : ways){
            int fX = x;
            int fY = y;
            while(true){
                fX += step.first;
                fY += step.second;
                if(inside(fX, fY) == false) break;
                Piece * ftmp = board.matrix[fX][fY];
                if(ftmp -> color == -1){
                    moves.push_back({fX, fY});
                    continue;
                } 
                if(ftmp -> color != myTurn){
                    moves.push_back({fX, fY});
                    break;
                }
                if(ftmp -> color == myTurn) break;
            }
        }
        return moves;
    }

    vector<pair<int, int>> getRockMoves(Board& board, int x, int y){
        vector<pair<int, int>> moves;
        Piece* tmp = board.matrix[x][y];
        int myTurn = tmp -> color;
        vector<pair<int, int>> ways = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (pair<int, int> step : ways){
            int fX = x;
            int fY = y;
            while(true){
                fX += step.first;
                fY += step.second;
                if(inside(fX, fY) == false) break;
                Piece * ftmp = board.matrix[fX][fY];
                if(ftmp -> color == -1){
                    moves.push_back({fX, fY});
                    continue;
                } 
                if(ftmp -> color != myTurn){
                    moves.push_back({fX, fY});
                    break;
                }
                if(ftmp -> color == myTurn) break;
            }
        }
        return moves;
    }

    vector <pair<int, int>> getQueenMoves(Board& board, int x, int y){
        vector<pair<int, int>> moves;
        Piece* tmp = board.matrix[x][y];
        int myTurn = tmp -> color;
        vector<pair<int, int>> ways = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        for(pair<int, int> step: ways){
            int fX = x;
            int fY = y;
            while(true){
                fX += step.first;
                fY += step.second;
                if(inside(fX, fY) == false) break;
                Piece* ftmp = board.matrix[fX][fY];
                if(ftmp -> color == -1){
                    moves.push_back({fX, fY});
                    continue;
                }
                if(ftmp -> color == myTurn){
                    break;
                }
                if(ftmp -> color != myTurn){
                    moves.push_back({fX, fY});
                    break;
                }
            }
        }
        return moves;
    }

    vector <pair<int,int>> getKingMoves(Board& board, int x, int y){
        vector<pair<int, int>> moves;
        Piece* tmp = board.matrix[x][y];
        int myTurn = tmp->color;
        vector<pair<int, int>> ways = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
        for(pair<int, int> step: ways){
            int fX = x + step.first;
            int fY = y + step.second;
            if(inside(fX, fY) == false) continue;
            Piece* ftmp = board.matrix[fX][fY];
            if(ftmp -> color == -1 || ftmp->color != myTurn){
                moves.push_back({fX, fY});
            }
        }        
        return moves;
    }
};

#endif  