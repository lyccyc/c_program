#include <stdio.h>
#include <string.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // 交换arr[j]和arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    char text[1000];
    int char_count[256] = {0};
    int unique_chars[256];
    int unique_count = 0;

    printf("请输入一串文字: ");
    fgets(text, sizeof(text), stdin);

    for (int i = 0; i < strlen(text); i++) {
        char_count[(int)text[i]]++;
    }

    // 获取非零出现次数的字符
    for (int i = 0; i < 256; i++) {
        if (char_count[i] > 0) {
            unique_chars[unique_count++] = i;
        }
    }

    // 对字符进行排序
    bubbleSort(unique_chars, unique_count);

    // 输出结果
    printf("字符\tASCII码\t出现次数\n");
    for (int i = 0; i < unique_count; i++) {
        printf("%c\t%d\t%d\n", (char)unique_chars[i], unique_chars[i], char_count[unique_chars[i]]);
    }

    return 0;
}
