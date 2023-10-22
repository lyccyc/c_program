#include <stdio.h>
#define BOARD_SIZE 8

//判斷是否在棋盤內
int in_board(int x, int y) {
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

//判斷可下同顏色的旗子與否
int can_place(int chess[BOARD_SIZE][BOARD_SIZE],int player, int x, int y){
    if (chess[x][y] != 0){
        return 0;
    }

    //二維陣列判斷八個方向
    int judge[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

    for (int d = 0; d < 8; d++) {
        int dx = judge[d][0];
        int dy = judge[d][1];
        int x_ = x + dx;
        int y_ = y + dy;
        int n=0;

        while(in_board(x_, y_)){
            if (chess[x_][y_] == 0){
                break;
            }
            else if (chess[x_][y_] == player) {
                if(n==0){
                    break;;
                }
                else{
                    return 1;
                }
                }
            x_ += dx;
            y_ += dy;
            n+=1;
        }
    }
    
    return 0;  
}


int main() {

    // 示例棋盘，1 表示黑棋，2 表示白棋，0 表示空白
    int chess[BOARD_SIZE][BOARD_SIZE] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 2, 0},
        {0, 0, 0, 2, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
    };
    int i , j, color;

    printf("輸入棋子座標:");
    scanf("%d,%d",&i,&j);

    printf("輸入棋子顏色(黑色為1,白色為2):");
    scanf("%d",&color);

    int player = chess[i][j];
    
    //判斷旗子顏色
    if (player == 0) {
        printf("(%d, %d) 是空白\n", i, j);
    } 
    else if (player == 1) {
        printf("(%d, %d) 是黑棋\n", i, j);
    } 
    else if (player == 2) {
        printf("(%d, %d) 是白棋\n", i, j);
    }

    //判斷是否可下同顏色的棋
    if (can_place(chess, color, i, j)) {
        printf("(%d, %d)能下 color=%d 的子\n", i, j,color);
    } 
    
    else {
        printf("(%d, %d)不能下 color=%d 的子\n", i, j,color);
    }

    return 0;
}