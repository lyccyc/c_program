#include <stdio.h>
#include <string.h>

void printLongestSubstring(char *s, int start, int end) {
    for (int i = start; i <= end; i++) {
        printf("%c", s[i]);
    }
    printf("\n");
}

int lengthOfLongestSubstring(char *s) {
    int n = strlen(s);

    // Using an array to store the last index of each character in the string
    int lastIndex[256];
    memset(lastIndex, -1, sizeof(lastIndex));

    int maxLength = 0;
    int start = 0;
    int longestStart = 0;
    int longestEnd = 0;

    for (int end = 0; end < n; end++) {
        if (lastIndex[s[end]] != -1) {
            start = (start > lastIndex[s[end]] + 1) ? start : lastIndex[s[end]] + 1;
        }
      
        lastIndex[s[end]] = end;

        if (maxLength < end - start + 1) {
            maxLength = end - start + 1;
            longestStart = start;
            longestEnd = end;
        }
    }

    printLongestSubstring(s, longestStart, longestEnd);

    return 0;
}

int main() {
    char s[1000];

    scanf("%s",s);

    int result = lengthOfLongestSubstring(s);

    return 0;
}


/*先寫一個函數等一下印出不重複的字串
再設一個函數(lengthOfLongestSubstring)，變數是(char s)
設一個整數型態陣列(lastindex)，把他初始化成-1(讓等一下要處理字串前，每一個字元出現的位置都是-1)
設四個變數都=0，等一下會用到
我用maxLength = 0
    start = 0
    longestStart = 0
    longestEnd = 0
1.檢查字元s[end]是否出現過
    (for int end=0;end<lenstr(s);end++)
    lastindex紀錄每個字元在目前的字串最後一次出現的位置
    如果lastindex[s[end]]!=-1表示已經出現過
    就更新start為重複的字元最後一次出現的位置的下一個位置(end+1)
    目的:要讓start始終指向當前字串的開始位置
2.更新lastindex[s[end]]為目前字元s[end]在字串中的位置end
3.檢查新字串的長度(emd-start+1)
    如果比maxlength還大，更新maxlength還有最長不重複字串的起始(longeststart=start)和結束位置(longes=end)
4.呼叫印出字串的函數，變數是(s,longestStart, longestEnd)
    印出字串，起始位置是i=longeststart,結束是i<=longestend,i++
5.主程式:
    宣告字元陣列[1001]
    輸入字元
    呼叫lengthOfLongestSubstring
6.結束*/
    


