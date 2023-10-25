#include <stdio.h>
#define SIZE 8
/*程式流程
in_board:確認在棋盤內
checkNewStepByColor:所有空白的地方(才能找出所有可下的位置）
checkNewStep:和輸入同樣顏色的棋子八個方向可以下的座標
printnext:印出答案*/

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
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
}
//判斷位置 (x, y) 能否下顏色為 color 的棋，可以下的位子將紀錄在next[][]中，
void checkNewStep(int chess[SIZE][SIZE], int next[SIZE][SIZE], int x, int y,int dx,int dy) {
    int color=chess[x][y];
    if (chess[x][y] != 0){
        return;
    }

    //二維陣列判斷八個方向
    int judge[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

    for (int d = 0; d < 8; d++) {
        dx = judge[d][0];
        dy = judge[d][1];
        int x_ = x + dx;
        int y_ = y + dy;

        while(in_board(x_, y_)){
            if (chess[x_][y_] == 0){
                break;
            }

            next[x][y]=chess[x_][y_];
            return;
        }
        x_ += dx;
        y_ += dy;
    }
    return;
}

//所有空白的地方(才能找出所有可下的位置）
void checkNewStepByColor(int chess[SIZE][SIZE], int next[SIZE][SIZE], int color,int dx,int dy){
    for(int i = 0; i < SIZE; i ++){
        for(int j = 0; j < SIZE; j ++){
        int check=chess[i][j];
        if (check==color){
            checkNewStep(chess,next,i,j,dx,dy);
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

int main(){
    //輸入座標
    int i,j,dx,dy;
    scanf("%d %d %d %d",&i,&j,&dx,&dy);
    int color=chess[i][j];

    int ans1[SIZE][SIZE]={0};
    printf("白子可下位置:\n");
    checkNewStepByColor(chess,ans1,color,dx,dy);
    printNext(ans1);

    int ans2[SIZE][SIZE]={0};
    printf("\n黑子可下位置:\n");
    checkNewStepByColor(chess,ans2,color,dx,dy);
    printNext(ans2);
}