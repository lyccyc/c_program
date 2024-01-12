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

// 印出棋盤內容
void printChess(int chess[SIZE][SIZE]){
    for(int i = 0; i < SIZE; i ++){
        for(int j = 0; j < SIZE; j ++)
            printf("%d ", chess[i][j]);
        printf("\n");
    }
    return;
}

//和輸入同樣顏色的棋子八個方向可以下的座標
int checkNewStep(int chess[8][8], int next[8][8], int color, int x, int y){
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
        int n=0;//跑的圈數

        while(in_board(x_, y_)){
            if (chess[x_][y_] == 0){
                break;
            }
            else if (chess[x_][y_] == color) {
                if(n==0){
                    break;
                }
                else{
                    return 1;
                }
            }
            x_ += dx;
            y_ += dy;
            n+=1;
            next[x][y]=chess[x_][y_];        
        }
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

void newStep(int next[SIZE][SIZE]){
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
//翻轉棋子，將下的位置從0變成1
void reverse_input(int chess[SIZE][SIZE],int change[SIZE][SIZE],int pos_x,int pos_y,int x,int y,int color){
    change[x][y]=chess[pos_x][pos_y];
    color=change[x][y];
    int judge[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

    for (int d = 0; d < 8; d++) {
        int dx = judge[d][0];
        int dy = judge[d][1];
        int x_ = x + dx;
        int y_ = y + dy;
        int color2=chess[x_][y_];

        while(in_board(x_,y_)){
            int color2=chess[x_][y_];
            //遇到空白棋子
            if (color2==0){
                return;//跳出函式
            }
            //遇到我方棋子
            if (color2==color){
                break;//跳出迴圈
            }
            x_ += dx;
            y_ += dy;
        }

        while(1){
            int color2=chess[x_][y_];
            change[pos_x][pos_y]=1;
            break;
        }
    }
}

void check_change(int chess[SIZE][SIZE],int change[SIZE][SIZE],int pos_x,int pos_y,int color){
    for (int i=-1;i<=1;i++){
        for (int j=-1;j<=1;j++){
            if (!i && !j){
                continue;
            }
            reverse_input(chess,change,pos_x,pos_y,i,j,color);
        }
    }
}

int can_reverse(int change[SIZE][SIZE],int i,int j){
    int rev=0;
    for (i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            if (change[i][j]){
                rev++;
            }
        }
    }
    return rev;
}
int main(){
    //輸入座標、方向
    int i,j,dx,dy;
    scanf("%d %d %d %d",&i,&j,&dx,&dy);
    int color=chess[i][j];
    int change[SIZE][SIZE]={0};

    int ans1[SIZE][SIZE]={0};
    printf("白子所有可下的步\n");
    checkNewStepByColor(chess,ans1,2);
    newStep(ans1);
    printf("\n");
    
    int ans2[SIZE][SIZE]={0};
    printf("黑子所有可下的步\n");
    checkNewStepByColor(chess,ans2,1);
    newStep(ans2);
    printf("\n");

    //預設玩家下黑棋
    int pos_x,pos_y;
    printf("請下黑子適合的位置:\n");
    scanf("%d %d",&pos_x,&pos_y);
    int current_color=1;
    chess[pos_x][pos_y]=current_color;
    check_change(chess,change,pos_x,pos_y,current_color);
    printChess(chess);


}