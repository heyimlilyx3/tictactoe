#pragma once
#include "autoPlayer.h"

class bookPlayer : public autoPlayer{
public:
    int chooseMove(board& gameBoard) override;
private:
    int readMove(board& gameBoard);
    void writeMoves();
    int boardToInt(board& gameBoard);
    vector<vector<bool>> intToBoard(int input);
};