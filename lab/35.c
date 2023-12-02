#include <stdio.h>

#define BOARD 19
char chess[BOARD][BOARD];

int checkWinner(char player) {
    // 檢查水平和垂直
    for (int i = 0; i < BOARD; i++) {
        int rowWin = 1;
        int colWin = 1;
        for (int j = 0; j < BOARD; j++) {
            if (chess[i][j] != player) {
                rowWin = 0;
            }
            if (chess[j][i] != player) {
                colWin = 0;
            }
        }
        if (rowWin || colWin) {
            return 1;
        }
    }

    // 檢查兩個對角線
    int diag1Win = 1;
    int diag2Win = 1;
    for (int i = 0; i < BOARD; i++) {
        if (chess[i][i] != player) {
            diag1Win = 0;
        }
        if (chess[BOARD - 1 - i][i] != player) {
            diag2Win = 0;
        }
    }
    if (diag1Win || diag2Win) {
        return 1;
    }

    return 0; // 沒有獲勝
}

int main(){

    for(int i=0;i<BOARD;i++){
        for(int j=0;j<BOARD;j++){
            scanf("%c",&chess[i][j]);
        }
    }

    if (checkWinner('X')) {
        printf("Black\n");
    } 
    else if(checkWinner('O')){
        printf("white\n");
    }
    else{
        printf("No winner\n");
    }
    return 0;
}




