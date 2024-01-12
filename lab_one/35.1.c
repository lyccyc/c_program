#include <stdio.h>
#include <stdbool.h>

#define SIZE 19

char board[SIZE][SIZE];

bool checkWinningCondition(char symbol) {
    // Check horizontal
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == symbol && board[i][j + 1] == symbol &&
                board[i][j + 2] == symbol && board[i][j + 3] == symbol &&
                board[i][j + 4] == symbol) {
                return true;
            }
        }
    }

    // Check vertical
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == symbol && board[i + 1][j] == symbol &&
                board[i + 2][j] == symbol && board[i + 3][j] == symbol &&
                board[i + 4][j] == symbol) {
                return true;
            }
        }
    }

    // Check diagonal (top-left to bottom-right)
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == symbol && board[i + 1][j + 1] == symbol &&
                board[i + 2][j + 2] == symbol && board[i + 3][j + 3] == symbol &&
                board[i + 4][j + 4] == symbol) {
                return true;
            }
        }
    }

    // Check diagonal (bottom-left to top-right)
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == symbol && board[i - 1][j + 1] == symbol &&
                board[i - 2][j + 2] == symbol && board[i - 3][j + 3] == symbol &&
                board[i - 4][j + 4] == symbol) {
                return true;
            }
        }
    }

    return false;
}

int main() {
   for(int i = 0;i < SIZE; i++){
    for(int j = 0;j < SIZE; j++){
        scanf("%c",&board[i][j]);
    }
   }

    if (checkWinningCondition('X')){
        printf("Black");
    } 
    else if(checkWinningCondition('O')){
        printf("White");
    }
    else{
        printf("No winner");
    }
    return 0;
}

