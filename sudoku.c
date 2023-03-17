#include <stdio.h>

#define SIZE 9

int grid[SIZE][SIZE];

// checks if number can be placed
int cell_check(int row, int col, int num) {
    
    // checks if number is already in row or column
    for(int i=0; i<SIZE; i++) {
        if(grid[i][col]==num||grid[row][i]==num){
            return 0;
        }
    }

    // checks if number is within 3x3 box
    // boxRow and boxCol gives which 3x3 num is in
    int boxRow=row-row%3;
    int boxCol=col-col%3;
    for(int i=boxRow; i<boxRow+3; i++) {
        for(int j=boxCol; j<boxCol+3; j++) {
            if(grid[i][j]==num) {
                return 0;
            }
        }
    }

    return 1;
}

// find empty cells
int empty(int *row, int *col) {

    // goes through the whole 9x9
    for(*row=0; *row<SIZE; *row++) {
        for(*col=0; *col<SIZE; *col++) {
            if(grid[*row][*col]==0) {
                return 1;
            }
        }
    }

    return 0;
}


// solve using empty and cell_check function, if cell is not empty, goes through 1-9 and cell_check to get soln
int solve() {

    int row, col;

    if(!empty(&row, &col)) {
        return 1;
    }

    for(int num=1; num<=9; num++) {
        if(cell_check(row, col, num)) {
            grid[row][col]=num;

            if(solve()) {
                return 1;
            }
            
            grid[row][col]=0;
        }
    }

    return 0;
}

void printSudoku() {

    for(int row=0; row<SIZE; row++) {
        for(int col=0; col<SIZE; col++) {
            printf("%d", grid[row][col]);
        }
        printf("\n");
    }

}

int main() {

    printf("Enter Sudoku, using space to seperate numbers, 0 to represent empty cells:\n");

    for(int row=0; row<SIZE; row++) {
        for(int col=0; col<SIZE; col++) {
            scanf("%d", &grid[row][col]);
        }
    }

    if(solve()) {
        printf("Solved Sudoku:\n");
        printSudoku();
    }
    else {
        printf("No solution");
    }

    return 0;
}