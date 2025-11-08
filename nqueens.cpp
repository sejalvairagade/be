#include <iostream>
using namespace std;

#define N 4 // You can change N for different board sizes

// Function to print the N-Queens board
void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << (board[i][j] ? "Q " : ". ");
        cout << endl;
    }
}

// Check if a queen can be placed at board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check column
    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Check upper left diagonal
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check upper right diagonal
    for (i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

// Recursive function to solve N-Queens
bool solveNQueens(int board[N][N], int row) {
    // Base case: All queens placed
    if (row == N)
        return true;

    // Try placing queen in each column of current row
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1; // Place queen

            // Recur for next row
            if (solveNQueens(board, row + 1))
                return true;

            board[row][col] = 0; // Backtrack
        }
    }
    return false; // If queen cannot be placed
}

int main() {
    int board[N][N] = {0};

    // Place first queen manually at (0, 0)
    board[0][0] = 1;

    // Solve from next row
    if (solveNQueens(board, 1))
        printSolution(board);
    else
        cout << "No solution exists";

    return 0;
}
