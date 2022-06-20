#include "sudoku.h"
#include <iostream>

int getNumClues() {
    while(true) {
        printf("Enter a number of clues: ");
        int num;
        cin >> num;
        if (num == 0 || cin.fail()) {
            printf("Must enter an integer!\n");
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            continue;
        }
        if (num < 17 || num > 50) {
            printf("Number must be between 17 and 50 (inclusive)\n");
            cin.clear();
            continue;
        }
        return num;
    }
}

int main()
{
    srand(time(NULL));
    printf("Welcome to CPP Sudoku!\n    Press ctrl+c at any time to exit.\n\n");
    while(true) {
        int numClues = getNumClues();
        Sudoku sudoku = Sudoku(numClues);
        printf("Here is your random puzzle\nPress any key when ready to solve.\n");
        sudoku.printBoard();
        system("pause");
        printf("Solving...\n");
        sudoku.solve();
        printf("Here is the solution\n");
        sudoku.printBoard();
        system("pause");
    }
    system("pause");
    return 0;
}
