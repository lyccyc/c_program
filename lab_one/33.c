#include <stdio.h>

void printClockwise(int matrix[100][100], int n, int m) {
    int top = 0, bottom = n - 1, left = 0, right = m - 1;

    while (top <= bottom && left <= right) {
        // 從左到右
        for (int i = left; i <= right; i++) {
            printf("%d ", matrix[top][i]);
        }
        top++;

        // 從上到下
        for (int i = top; i <= bottom; i++) {
            printf("%d ", matrix[i][right]);
        }
        right--;

        // 從右到左
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;
        }

        // 從下到上
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
    }
}

int main() {
    int n, m;
    int matrix[100][100];

    // 讀取矩陣的行數和列數
    scanf("%d %d", &n, &m);

    // 讀取矩陣的內容
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // 輸出順時針序的矩陣內容
    printClockwise(matrix, n, m);

    return 0;
}
