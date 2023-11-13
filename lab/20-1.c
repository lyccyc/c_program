#include <stdio.h>
#include <stdlib.h>

// 比較函數，用於排序
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// 找到陣列的中位數
int findMedian(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);
    return arr[n / 2];
}

// 檢查中位數是否滿足條件
int checkConditions(int arr[], int n, int median) {
    int countLessThan = 0;
    int countGreaterThan = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] < median) {
            countLessThan++;
        } else if (arr[i] > median) {
            countGreaterThan++;
        }
    }

    // 檢查條件
    return (countLessThan <= n / 2) && (countGreaterThan <= n / 2);
}

int main() {
    int n;

    // 讀取陣列大小
    printf("輸入陣列大小: ");
    scanf("%d", &n);

    // 宣告陣列
    int arr[n];

    // 讀取陣列元素
    printf("輸入陣列元素:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 找到中位數
    int median = findMedian(arr, n);

    // 檢查中位數是否滿足條件
    if (checkConditions(arr, n, median)) {
        printf("中位數 %d 滿足條件\n", median);
    } else {
        printf("中位數 %d 不滿足條件\n", median);
    }

    return 0;
}
