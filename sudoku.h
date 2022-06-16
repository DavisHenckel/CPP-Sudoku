#ifndef SUDOKU_H
#define SUDOKU_H

#include <tuple>
#include <stdio.h>
#include <stdexcept>
#include <random>
#include <time.h>
#include <iterator>

using namespace std;

class Sudoku
{
private:
    //Private Methods
    bool validateInput(int row, int col, int num);
    bool rowPlacementValid(int row, int col, int num);
    bool colPlacementValid(int row, int col, int num);
    bool subGridPlacementValid(int row, int col, int num);
    bool moveValid(int row, int col, int num);
    void generatePuzzle(int numClues, int counter = 0);

public:
    Sudoku(int** sudokuPuzzle [9][9]);
    Sudoku(int numClues);
    const int rowSize = 9;
    const int colSize = 9;
    const int numElements = 81;
    int sudokuBoard [9][9] = {
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0}
    };

    //Public Methods
    void printBoard();
    tuple<int, int> getEmptySpace();
    bool solve();
};

#endif // SUDOKU_H
