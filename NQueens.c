#include <stdio.h>

#define N 4 // change N here
int i,j;

void display(int board[N][N]) {
    for ( i = 0; i < N; i++) {
        for ( j = 0; j < N; j++) {
            if (board[i][j]) {
                printf("Q ");
            } else {
                printf("_ ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int isSafe(int board[N][N], int row, int col) {
    int maxLeft,maxRight;
    // Check vertical row
    for (i = 0; i < row; i++) {
        if (board[i][col]) {
            return 0;
        }
    }

    // Diagonal left
    maxLeft = row < col ? row : col; //min of row and col
    for ( i = 1; i <= maxLeft; i++) {
        if (board[row - i][col - i]) {
            return 0;
        }
    }

    // Diagonal right
    maxRight = row < N - col - 1 ? row : N - col - 1; //min of row and col
    for ( i = 1; i <= maxRight; i++) {
        if (board[row - i][col + i]) {
            return 0;
        }
    }

    return 1;
}

int queens(int board[N][N], int row) {
    int count = 0;
    int col;
    if (row == N) {
        display(board);
        return 1;
    }


    for ( col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;
            count += queens(board, row + 1);
            board[row][col] = 0;
        }
    }

    return count;
}

int main() {
    int board[N][N] = {0};
    printf("No of solutions is %d\n", queens(board, 0));
    return 0;
}
