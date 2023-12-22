#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *replace(char *source, char *target, char *replacement, int mode) {
    if (mode == 1) {
        //尋找
        //傳回指標，指向 source中第一次出現 target 的開頭
        char *occurrence = strstr(source, target);

        if (occurrence != NULL) {
            int targetLength = strlen(target);
            int replacementLength = strlen(replacement);
            int sourceLength = strlen(source);

            // 更新新長度
            int newLength = sourceLength - targetLength + replacementLength;

            // 
            char *result ;//= (char *)(newLength + 1);

            // 複製字串
            strncpy(result, source, occurrence - source);
            //result[occurrence - source] = '\0';

            // 串接字串
            strcat(result, replacement);

            // 串接剩下的字串
            strcat(result, occurrence + targetLength);

            return result;
        }
    }

    else if (mode == 2) {
        // Find and replace all occurrences of the target in the source
        char *occurrence = strstr(source, target);

        while (occurrence != NULL) {
            int targetLength = strlen(target);
            int replacementLength = strlen(replacement);
            int sourceLength = strlen(source);

            // 更新總長
            int newLength = sourceLength - targetLength + replacementLength;

            char *result = (char *)malloc(newLength + 1);

            // 複製找到目標字串前的字串
            strncpy(result, source, occurrence - source);
            //result[occurrence - source] = '\0';

            // 串接樣更換的字串
            strcat(result, replacement);

            // 串接剩下的字串
            strcat(result, occurrence + targetLength);

            // 找下一個terget
            source = result;
            occurrence = strstr(source, target);
        }

        return source;
    }

    return source;
}

int main() {
    char source[] = "Hello world! Hello universe! Hello world!";
    const char target[] = "world";
    const char replacement[] = "planet";

    printf("Original: %s\n", source);

    char *result = replace(source, target, replacement, 2);

    printf("After replacement: %s\n", result);

    return 0;
}