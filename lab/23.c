#include <stdio.h>
#include <ctype.h>

void capitalizeSentences(char text[]) {
    // 設定一個標誌，表示下一個字符是句子的開頭
    int capitalizeNext = 1;

    // 遍歷字元串
    for (int i = 0; text[i] != '\0'; i++) {
        // 如果 capitalizeNext 為真且字符是字母，則將其轉換為大寫
        if (capitalizeNext && isalpha(text[i])) {
            text[i] = toupper(text[i]);
            capitalizeNext = 0;
        }

        // 如果字符是句點、驚嘆號或問號，將 capitalizeNext 設置為真
        if (text[i] == '.' || text[i] == '!' || text[i] == '?' || text[i]=='\n') {
            capitalizeNext = 1;
        }
    }
}

int main() {
    // 假設最大輸入為1000個字符
    char text[1001];

    gets(text);

    // 調用函數轉換句子的開頭為大寫
    capitalizeSentences(text);

    // 印出結果
    printf("%s", text);

    return 0;
}
