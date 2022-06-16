#include <QCoreApplication>
#include "sudoku.h"

int main()
{
    srand(time(NULL));
    Sudoku sudoku = Sudoku(17);
    printf("Here is your random puzzle\n");
    sudoku.printBoard();
    printf("Solving...\n");
    sudoku.solve();
    printf("Here is the solution\n");
    sudoku.printBoard();
    return 0;
}
