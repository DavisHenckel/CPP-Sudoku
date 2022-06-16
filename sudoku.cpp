#include "sudoku.h"

using namespace std;

Sudoku::Sudoku(int numClues){
    generatePuzzle(numClues);
};

Sudoku::Sudoku(int** initArray[9][9]) {
    for (int i = 0; i < this->rowSize; i++) {
        for (int j = 0; j < this->colSize; j++) {
            **initArray[i][j] = this->sudokuBoard[i][j];
        }
    }
}

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
        string errorStr = "Number must be between 1 and 9 (inclusive)\nNumber was: {0}", num;
        throw invalid_argument(errorStr);
        return false;
    }
    if (row > 8 || row < 0) {
        throw invalid_argument("Row must be between 0 and 8 (inclusive)");
        return false;
    }
    if (col > 8 || col < 0) {
        throw invalid_argument("Column must be between 0 and 8 (inclusive)");
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

bool Sudoku::subGridPlacementValid(int row, int col, int num) {
    if (!this->validateInput(row, col, num)) {
        return false;
    }
    int subgridRowStart = row / 3 * 3;
    int subgridColStart = col / 3 * 3;
    for (int i = subgridRowStart; i < subgridRowStart + 3; i++) {
        for (int j = subgridColStart; j < subgridColStart + 3; j++) {
            if (this->sudokuBoard[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

bool Sudoku::moveValid(int row, int col, int num) {
    if (!this->validateInput(row, col, num)) {
        return false;
    }
    if (this->colPlacementValid(row,col,num)
        && this->rowPlacementValid(row,col,num)
        && this->subGridPlacementValid(row,col,num)) {
        return true;
    }
    return false;
}

tuple<int, int> Sudoku::getEmptySpace() {
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            if (this->sudokuBoard[i][j] == 0) {
                return make_tuple(i,j);
            }
        }
    }
    return make_tuple(-1,-1);
}

bool Sudoku::solve() {
    tuple<int, int> nextEmptySpot = this->getEmptySpace();
    if (get<0>(nextEmptySpot) == -1) {
        return true;
    }
    else {
        for (int i = 1; i < 10; i++) {
            if (this->moveValid(get<0>(nextEmptySpot), get<1>(nextEmptySpot), i)) {
                this->sudokuBoard[get<0>(nextEmptySpot)][get<1>(nextEmptySpot)] = i;
                if (this->solve()) {
                    return true;
                }
                this->sudokuBoard[get<0>(nextEmptySpot)][get<1>(nextEmptySpot)] = 0;
            }
        }
        return false;
    }
}

void Sudoku::generatePuzzle(int numClues, int counter) {
    if (counter == numClues) {
        return;
    }
    int rowPlacement = rand() % 9;
    int colPlacement = rand() % 9;
    int randomNum = (rand() % 9) + 1;
    if (this->sudokuBoard[rowPlacement][colPlacement] == 0) {
        if (this->moveValid(rowPlacement, colPlacement, randomNum)) {
            this->sudokuBoard[rowPlacement][colPlacement] = randomNum;
            int copyArray [9][9];
            //quick for loop to copy elements to copy array.
            for (int i = 0; i < this->rowSize; i++) {
                for (int j = 0; j < this->colSize; j++) {
                    copyArray[i][j] = this->sudokuBoard[i][j];
                }
            }
            //Instantiate new puzzle with current state of array to see if solvable.
            Sudoku copyPuzzle = Sudoku(**copyArray);
            if (copyPuzzle.solve()) {
                return this->generatePuzzle(numClues, counter + 1);
            }
            this->sudokuBoard[rowPlacement][colPlacement] = 0;
            return this->generatePuzzle(numClues, counter);
        }
        else {
            return this->generatePuzzle(numClues, counter);
        }
    }
    else {
        return this->generatePuzzle(numClues, counter);
    }

}

