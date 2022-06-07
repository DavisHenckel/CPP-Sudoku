#include "sudoku.h"
#include <stdio.h>

Sudoku::Sudoku(){};

void Sudoku::printBoard() {
    printf("+++++++++++++++++++++++++\n");
    for (int i = 0; i < this->rowSize; i++) {
        if (i == 9) {
            printf("|\n");
        }
        for (int j = 0; j < this->colSize; j++) {
            if (j == 0) {
                printf("| ");
            }
            if (j == 3 || j == 6) {
                printf("| ");
            }
            printf("%i ", this->sudokuBoard[i][j]);
            if (j == 8) {
                printf("|\n");
            }
        }
        if (i == 2 || i == 5) {
            printf("|+++++++++++++++++++++++|\n");
        }
    }
    printf("+++++++++++++++++++++++++\n");
}
