#pragma once

#include <vector>

using namespace std;


class board{
public:
    board();
    void printBoard();
    void playMove(bool isX, int where);
    bool isWonByX = false;
    bool isWonByO = false;
    bool checkIsWon();
    vector<int> getOpenSquares();
    vector<vector<bool>> boolBoard;
    
private:
    void printSquare(int i);

};