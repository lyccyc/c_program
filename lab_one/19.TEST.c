#include <stdio.h>

void findCommonElements(int arr1[], int size1, int arr2[], int size2) {
    printf("相同的數字是: ");

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                printf("%d ", arr1[i]);
                break;  // 找到相同的數字後，跳出內層迴圈
            }
        }
    }

    printf("\n");
}

int main() {
    int size1, size2;

    // 讀取第一個陣列大小
    printf("輸入第一個陣列大小: ");
    scanf("%d", &size1);

    // 宣告第一個陣列
    int arr1[size1];

    // 讀取第一個陣列元素
    printf("輸入第一個陣列元素: ");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    // 讀取第二個陣列大小
    printf("輸入第二個陣列大小: ");
    scanf("%d", &size2);

    // 宣告第二個陣列
    int arr2[size2];

    // 讀取第二個陣列元素
    printf("輸入第二個陣列元素: ");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    // 找到相同的數字
    findCommonElements(arr1, size1, arr2, size2);

    return 0;
}
