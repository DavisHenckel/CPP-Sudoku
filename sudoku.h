#ifndef SUDOKU_H
#define SUDOKU_H


class Sudoku
{
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

    void printBoard();
};

#endif // SUDOKU_H
