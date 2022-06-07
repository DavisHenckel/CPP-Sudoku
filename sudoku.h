#ifndef SUDOKU_H
#define SUDOKU_H

#include <tuple>

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

public:
    Sudoku();
    const int rowSize = 9;
    const int colSize = 9;
    const int numElements = 81;
    int sudokuBoard [9][9] = {
        {0,0,0,8,0,1,0,0,0},
        {0,0,0,0,0,0,0,4,3},
        {5,0,0,0,0,0,0,0,0},
        {0,0,0,0,7,0,8,0,0},
        {0,0,0,0,0,0,1,0,0},
        {0,2,0,0,3,0,0,0,0},
        {6,0,0,0,0,0,0,7,5},
        {0,0,3,4,0,0,0,0,0},
        {0,0,0,2,0,0,6,0,0}
    };

    //Public Methods
    void printBoard();
    tuple<int, int> getEmptySpace();
    bool solve();
};

#endif // SUDOKU_H
