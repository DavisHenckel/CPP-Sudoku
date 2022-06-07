#include "sudoku.h"
#include <stdio.h>
#include <stdexcept>

using namespace std;

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

bool Sudoku::validateInput(int row, int col, int num) {
    if (num > 9 || num < 1) {
        throw invalid_argument("Number must be between 1 and 9 (inclusive)");
        return false;
    }
    if (row > 8 || row < 0) {
        throw invalid_argument("Row must be between 0 and 8 (inclusive)");
        return false;
    }
    if (col > 8 || col < 0) {
        throw invalid_argument("Number must be between 0 and 8 (inclusive)");
        return false;
    }
    return true;
}

bool Sudoku::rowPlacementValid(int row, int col, int num) {
    if (!this->validateInput(row, col, num)) {
        return false;
    }
    for (int i = 0; i < this->colSize; i++) {
        if (this->sudokuBoard[i][col] == num) {
            return false;
        }
    }
    return true;
}

bool Sudoku::colPlacementValid(int row, int col, int num) {
    if (!this->validateInput(row, col, num)) {
        return false;
    }
    for (int i = 0; i < this->rowSize; i++) {
        if (this->sudokuBoard[row][i] == num) {
            return false;
        }
    }
    return true;
};

