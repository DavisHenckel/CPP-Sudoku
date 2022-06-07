#include <QCoreApplication>
#include "sudoku.h"

int main()
{
    Sudoku sudoku;
    sudoku.printBoard();
    sudoku.solve();
    sudoku.printBoard();
    return 0;
}
