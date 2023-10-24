#include <stdio.h>
#define SIZE 8

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

//印出棋盤
void printchess(){
    for(int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++)
            if(chess[i][j] == 3) 
                printf("x");
            else printf("%d", chess[i][j]);
        printf("\n");  
}
}

//印出可下的座標
void print_can_play(int next[SIZE][SIZE]){
    for(int i = 0; i < SIZE; i ++){
        for(int j = 0; j < SIZE; j ++){
            if(next[i][j]){
                if(!first) printf(", ");
                printf("(%d, %d)", i, j);
                first = 0;
            }
        }
    }
}

//newStep 函數會根據給定的座標 (x,y)及給定的方向 (dx,dy), 
//其中 (dx, dy) in {(-1,-1),(-1,0), (-1, 1), (0,-1),(0,1), (1,-1),(1,0),(1,1)} 八個方位之一 
//return 0: 表示無可下子位子
//return n: 表示 (x,y)+n*(dx,dy)可以下子
int newStep(int chess[SIZE][SIZE], int x, int y, int dx, int dy)
{
   int judge[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

   int color1=chess[x][y];
   if (color1==0){
        return 0;
   }

    int color2;
    int distance=0;

    while(1){
        int x_=x+dx;
        int y_=y+dy;
        distance++;
        color2=chess[x_][y_];
        //相同顏色的棋子
        if (color2==color1){
            break;
        }
        //超出邊界
        if (x_<0 || x>SIZE || y_<0 || y_>SIZE){
            break;
        }
        if (color2==0){
            if (distance <= 1){
                break;
            }
            else{
                return distance;
            }
        }
    }
    return 0;
}
//checkNewStep 用來計算 根據輸入的座標 (x,y)
//其8個方向可以下的所有位子
//可以下的位子將紀錄再next[][]中，當return後
//next[][]會被更改(如果有可下子的位子）
void checkNewStep(int chess[8][8], int next[8][8], int x, int y) {
    
}
//checkNewStepByColor 函數用來計算，根據你輸入的 color 棋子，所有可下的位子
//所以當結束函數 return 後，next[][]內容會被更改
//所以呼叫這函數時，傳進來的next[][]必須被初ㄓ
void checkNewStepByColor(int chess[SIZE][SIZE], int next[SIZE][SIZE], int color) 
{
    for(int i = 0; i < SIZE; i ++){
        for(int j = 0; j < SIZE; j ++){
        int check=chess[i][j]
        if (check==color){
            checkNewStep(chess,next,x,y)
        }
        }
    }
}