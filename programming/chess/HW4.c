#include <stdio.h>
#define SIZE 8
/*程式流程
in_board:確認在棋盤內
checkNewStepByColor:所有顏色和輸入座標一樣的棋子(才能找出所有可下的位置）
checkNewStep:和輸入同樣顏色的棋子八個方向可以下的座標
newStep:計算輸入座標和可下座標間距離［return 0=無解/return n=(dx,dy)*n可以下］
printnext:印出答案*/

//2023.10.25 checkNewStep unfin

int chess[SIZE][SIZE]={
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,1,2,0,0,0},
    {0,0,0,2,1,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0}
};

//判斷是否在棋盤內
int in_board(int x, int y) {
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}
//判斷位置 (x, y) 能否下顏色為 color 的棋，可以下的位子將紀錄再next[][]中，
void checkNewStep(int chess[SIZE][SIZE], int next[SIZE][SIZE], int x, int y, int color) {
    color=chess[x][y];
    if (chess[x][y] != 0){
        return 0;
    }

    //二維陣列判斷八個方向
    int judge[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

    for (int d = 0; d < SIZE; d++) {
        int dx = judge[d][0];
        int dy = judge[d][1];
        int x_ = x + dx;
        int y_ = y + dy;

        while(in_board(x_, y_)){
            if (chess[x_][y_] != 0){
                break;
            }
            else  {
                next[x][y]=chess[x_][y_];
                return  next[x][y];
                }
        }
            x_ += dx;
            y_ += dy;
    }
    return 0;
    }


//所有顏色和輸入座標一樣的棋子(才能找出所有可下的位置）
void checkNewStepByColor(int chess[SIZE][SIZE], int next[SIZE][SIZE], int color){
    for(int i = 0; i < SIZE; i ++){
        for(int j = 0; j < SIZE; j ++){
        int check=chess[i][j];
        if (check==color){
            checkNewStep(chess,next,i,j);
        }
        }
    }
}

// 印出所有可下的座標
void printNext(int next[SIZE][SIZE]){
    int first = 1;
    for(int i = 0; i < SIZE; i ++){
        for(int j = 0; j < SIZE; j ++){
            if(next[i][j]){
                if(!first) printf(", ");
                printf("(%d, %d)", i, j);
                first = 0;
            }
        }
    }
    return;  
}