#include <stdio.h>
#include <math.h>

#define MAX_COORDINATES 100

struct Point {
    int x, y;
};

float calculate(struct Point a, struct Point b) {
    // 使用畢式定理計算兩點之間的距離（斜線長度）
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

int cmp(int a, int b){
  return a - b;
}

int main() {
    int C;  // 測試案例數量
    scanf("%d", &C);

    while (C--) {
        int N;  // 坐標對數量
        scanf("%d", &N);

        struct Point coordinates[MAX_COORDINATES],temp,high;

        // 讀取每個坐標點的值
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &coordinates[i].x, &coordinates[i].y);
        }

        //排序
        double totalLength = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N-i-1;j++){
                if(cmp(coordinates[j].x,coordinates[j+1].x) > 0){
                    temp=coordinates[j];
                    coordinates[j]=coordinates[j+1];
                    coordinates[j+1]=temp;
                }
            }
        }        

        for(int i=0;i<N;i++)
            printf("%d %d\n",coordinates[i].x,coordinates[i].y);

        // 計算陽光照到山坡的總長度
        totalLength+=calculate(coordinates[N-1],coordinates[N-2]);
        high=coordinates[N-2];
        if(N>2){ 
            for (int i = N-2; i >= 0 ; i--) {
                if(coordinates[i].y>high.y){
                    double delta1 = calculate(coordinates[i], coordinates[i+1]);
                    double delta2 = (coordinates[i].y-high.y);
                    totalLength += delta1*delta2/(coordinates[i].y-coordinates[i+1].y);
                    //lenghth:delta2=coor[i].y-high.y:coor[i].y
                    high=coordinates[i];
                }
            }
        }
        // 輸出結果
        printf("%.2f\n", totalLength);  // 輸出浮點數，保留兩位小數
    }
    return 0;
}

