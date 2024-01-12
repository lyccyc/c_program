#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *replace(char *source, char *target, char *replacement, int mode) {
    if (mode == 1) {
        // 尋找
        char *occurrence = strstr(source, target);

        if (occurrence != NULL) {
            int targetLength = strlen(target);
            int replacementLength = strlen(replacement);
            int sourceLength = strlen(source);

            // 更新總長
            int newLength = sourceLength - targetLength + replacementLength;

            // 分配記憶體
            char *result = (char *)malloc(newLength + 1);

            strncpy(result, source, occurrence - source);
            result[occurrence - source] = '\0';
          
            strcat(result, replacement);

            strcat(result, occurrence + targetLength);

            return result;
        }
    } else if (mode == 2) {
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
          result[occurrence - source] = '\0';

          // 串接要更換的字串
          strcat(result, replacement);

          // 串接剩下的字串
          strcat(result, occurrence + targetLength);

          //找下一個target
          source = result;
          occurrence = strstr(source, target);
      }

      return source;
  }

    return source;
}

num=0;
abc469jk42
num+=str[i];
sum=(num*10)+'0';