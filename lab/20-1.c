#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    while (scanf("%d", &n) != EOF) {
        // 读取 n 个数字
        int numbers[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &numbers[i]);
        }

        // 计算 A 的最小可能值
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += numbers[i];
        }
        int A = (sum + n / 2) / n;  // 四舍五入取整

        // 统计满足 A 性质的数字数量
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (abs(numbers[i] - A) == abs(numbers[0] - A)) {
                count++;
            } else {
                break;  // 数组已排序，一旦不满足条件，后面的数字也不会满足
            }
        }

        // 统计可能的不同整数值
        int possible_values = n - count + 1;

        // 输出结果
        printf("%d %d %d\n", A, count, possible_values);
    }

    return 0;
}
