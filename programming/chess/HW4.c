#include <stdio.h>
#define SIZE 8
/*程式流程
in_board:確認在棋盤內
checkNewStepByColor:所有顏色和輸入座標一樣的棋子(才能找出所有可下的位置）
checkNewStep:和輸入同樣顏色的棋子八個方向可以下的座標
newStep:計算輸入座標和可下座標間距離［return 0=無解/return n=(dx,dy)*n可以下］
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

//和輸入同樣顏色的棋子八個方向可以下的座標
int checkNewStep(int chess[8][8], int next[8][8], int color, int x, int y){
    if (chess[x][y] != 0){
        return 0;
    }

    //二維陣列判斷八個方向
    int judge[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

    for (int d = 0; d < 8; d++) {
        int dx_ = judge[d][0];
        int dy_ = judge[d][1];
        int x_ = x + dx_;
        int y_ = y + dy_;
        int n=0;//跑的圈數

        while(in_board(x_, y_)){
            if (chess[x_][y_] == 0){
                break;
            }
            else if (chess[x_][y_] == color) {
                if(n==0){
                    break;;
                }
                else{
                    return n;
                }
            }
            x_ += dx_;
            y_ += dy_;
            n+=1;
            next[x][y]=chess[x_][y_];        
        }
        return next[x][y];
    }
    return 0;  
}
//所有顏色和輸入座標一樣的棋子(才能找出所有可下的位置）
int checkNewStepByColor(int chess[8][8], int next[8][8], int color){
    for(int i = 0; i < SIZE; i ++){
        for(int j = 0; j < SIZE; j ++){
            int c = chess[i][j];
            if(c == 0)
                checkNewStep(chess, next,color,i,j);
        }
    }
    return 0;
}

int main(){
    //輸入座標、方向
    int i,j,dx,dy;
    scanf("%d %d %d %d",&i,&j,&dx,&dy);
    int color=chess[i][j];

    int ans1[SIZE][SIZE]={0};
    printf("白子所有可下的步\n");
    checkNewStepByColor(chess,ans1,2);

    
    int ans2[SIZE][SIZE]={0};
    printf("黑子所有可下的步\n");
    checkNewStepByColor(chess,ans2,1);

}