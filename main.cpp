#include "board.h"
#include "autoPlayer.h"
#include "randomPlayer.h"
#include "singleMovePlayer.h"
#include "bookPlayer.h"
#include <cstdlib>
#include <iostream>
using namespace std;



void playTurn(bool isX, board& gameBoard){
    cout << "enter your move player ";
    if(isX){
        cout << "X: ";
    }else{
        cout << "O: ";
    }

    cout << endl;

    int mv;
    cin >> mv;

    gameBoard.playMove(isX, mv);
}

void playGame(board& gameBoard){
    for(int turn = 0; turn < 9; turn++){
        playTurn(turn%2, gameBoard);
        gameBoard.printBoard();
        if(gameBoard.checkIsWon()){
            cout << "GAME OVER!" << endl;
            cout << "Winner: ";
            if(gameBoard.isWonByX){
                cout << "X" << endl;
            }else if(gameBoard.isWonByO){
                cout << "O" << endl;
            }else{
                cout << "uh oh, game is won but both lost apparently???" << endl;
            }
            turn += 9;
        }
    }
    if(!gameBoard.checkIsWon()){
        cout << "Draw :(" << endl;
    }
}

void playVsComputer(bool asX, board& gameBoard, autoPlayer& cpu){
    for(int turn = 0; turn < 9; turn++){
        bool isXTurn = turn % 2 == 0;
        if(isXTurn == asX){
            playTurn(asX, gameBoard);
            gameBoard.printBoard();
        }else{
            gameBoard.playMove(!asX, cpu.chooseMove(gameBoard));
            gameBoard.printBoard();
        }
        if(gameBoard.checkIsWon()){
            cout << "GAME OVER!" << endl;
            cout << "Winner: ";
            if(gameBoard.isWonByX){
                cout << "X" << endl;
            }else if(gameBoard.isWonByO){
                cout << "O" << endl;
            }else{
                cout << "uh oh, game is won but both lost apparently???" << endl;
            }
            turn += 9;
        }
        bookPlayer tempBookPlayer;
        tempBookPlayer.chooseMove(gameBoard);
    }
    if(!gameBoard.checkIsWon()){
        cout << "Draw :(" << endl;
    }
    bookPlayer tempBookPlayer;
    tempBookPlayer.chooseMove(gameBoard);
}

int cpuVsCpu(board& gameBoard, autoPlayer& cpuX, autoPlayer& cpuO, bool printGame){
    for(int turn = 0; turn < 9; turn++){
        bool isXTurn = turn % 2 == 0;
        if(isXTurn){
            gameBoard.playMove(isXTurn, cpuX.chooseMove(gameBoard));
        }else{
            gameBoard.playMove(isXTurn, cpuO.chooseMove(gameBoard));
        }
        if(printGame){
            gameBoard.printBoard();
            if(gameBoard.checkIsWon()){
                cout << "GAME OVER!" << endl;
                cout << "Winner: ";
                if(gameBoard.isWonByX){
                    cout << "X" << endl;
                }else if(gameBoard.isWonByO){
                    cout << "O" << endl;
                }else{
                    cout << "uh oh, game is won but both lost apparently???" << endl;
                }
            // turn += 9;
            }
        
        
        }
        if(gameBoard.checkIsWon()){
            if(gameBoard.isWonByX){
                return -1;
            }else{
                return 1;
            }
            turn+=9;
        }

    }


    return 0;
}

int main(){
    system("cls");

    srand(static_cast<unsigned int>(time(nullptr)));

    singleMovePlayer cpu;

    randomPlayer cpu2;
    bookPlayer cpu3;

    board gameBoard;

    gameBoard.printBoard();

    playVsComputer(true, gameBoard, cpu2);

    // gameBoard.printBoard();

    // playVsComputer(1, gameBoard, cpu);

    // cpuVsCpu(gameBoard, cpu, cpu2, true);

    // playGame(gameBoard);

    //run multiple cpuvcpu games and only output the tally of wins

    // int numGames = 100;
    // int cpu1Wins = 0;
    // int cpu2Wins = 0;
    // int draws = 0;
    // for(int i = 0; i < numGames; i++){
    //     board tempGameBoard;
    //     switch (cpuVsCpu(tempGameBoard, cpu, cpu2, false)){
    //         case -1: 
    //             cpu1Wins++;
    //             break;
    //         case 0:
    //             draws++;
    //             break;
    //         case 1:
    //             cpu2Wins++;
    //             break;
    //     }

    // }

    // cout << "After " << numGames << " games:" << endl;
    // cout << "Cpu1 got " << cpu1Wins << " wins" << endl;
    // cout << "Cpu2 got " << cpu2Wins << " wins" << endl;
    // cout << "and there were " << draws << " draws." << endl;


    return 0;
}