#ifndef SUDOKU_H
#define SUDOKU_H

class Sudoku
{
private:
    //Private Methods
    bool validateInput(int row, int col, int num);
public:
    Sudoku();
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
    bool rowPlacementValid(int row, int col, int num);
    bool colPlacementValid(int row, int col, int num);
    bool subGridPlacementValid(int row, int col, int num);
    bool moveValid(int row, int col, int num);
};

#endif // SUDOKU_H
