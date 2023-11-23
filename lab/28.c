#include <stdio.h>
#include <math.h>

#define MAX_COORDINATES 100

struct Point {
    int x, y;
};

float calculate(struct Point a, struct Point b) {
    // 使用勾股定理計算兩點之間的距離（斜線長度）
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

int main() {
    int C;  // 測試案例數量
    scanf("%d", &C);

    while (C--) {
        int N;  // 坐標對數量
        scanf("%d", &N);

        struct Point coordinates[MAX_COORDINATES];

        // 讀取每個坐標點的值
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &coordinates[i].x, &coordinates[i].y);
        }

        // 計算陽光照到山坡的總長度
        float totalLength = 0;
        for (int i = 0; i < N - 1; i++) {
            // 如果下一個點的 y 大於當前點的 y，則計算陽光照到山坡的長度
            if (coordinates[i - 1].y > coordinates[i].y) {
                totalLength += calculate(coordinates[i - 1], coordinates[i]);
            }
        }

        // 輸出結果
        printf("%.2f\n", totalLength);  // 輸出浮點數，保留兩位小數
    }

    return 0;
}
