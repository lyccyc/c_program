#include <stdio.h>

int cycleLength(int n){
    int length=1;
    while (n != 1) {
        if (n % 2 == 1) {
            n = 3 * n + 1;
        } else {
            n = n / 2;
        }
        length++;
    }
    return length;
}

int maxCycleLength(int i, int j) {
    int max = 0;

    for (int num = i; num <= j; num++) {
        int ans = cycleLength(num);
        max = (ans > max) ? ans : max;
    }

    return max;
}

int main() {
    int i, j;

    // 輸入範圍
    while(scanf("%d %d", &i, &j)!=EOF){
        printf("%d %d",i,j);
        if(i>j){
            int temp=i;
            i=j;
            j=temp;
        }
        // 計算最大並輸出
        int result = maxCycleLength(i, j);
        printf(" %d\n", result);
        while(i==0 && j==0){
            break;
        }
    
    }
    return 0;
}