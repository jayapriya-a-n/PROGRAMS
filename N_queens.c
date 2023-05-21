#include <stdio.h>
#include <stdbool.h>

#define NMAX 20

int count = 0;

bool isSafe(int board[NMAX][NMAX], int row, int col, int N) {
    int i, j;

    // Check the left side of the current row
    for (i = 0; i < col; i++) {
        if (board[row][i])
            return false;
    }

    // Check the upper diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }

    // Check the lower diagonal
    for (i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j])
            return false;
    }

    return true;
}

void solveNQueens(int board[NMAX][NMAX], int col, int N) {
    if (col == N) {
        // Found a solution
        count++;
        return;
    }

    int i;
    for (i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;
            solveNQueens(board, col + 1, N);
            board[i][col] = 0;  // Backtrack
        }
    }
}

int main() {
    int N;
    printf("Enter the size of the chessboard (N): ");
    scanf("%d", &N);

    if (N < 1 || N > NMAX) {
        printf("Invalid board size. Please enter a value between 1 and %d.\n", NMAX);
        return 1;
    }

    int board[NMAX][NMAX] = {0};
    solveNQueens(board, 0, N);

    printf("Total number of solutions for a %dx%d chessboard: %d\n", N, N, count);

    return 0;
}
