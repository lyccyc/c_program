#include <stdio.h>
#include <string.h>

int main() {
  char number[1001];
  int i;
  
  while (1) {
    int len = 0;
    scanf("%s", number);
    len = strlen(number);
    if (number[0]=='0'){
        return 0;
    }
    int count = 0;
    for (int i=0;i<len;i=i+2){
        count+=(number[i]-'0');
    }
    for (int i=1;i<len;i=i+2){
        count-=(number[i]-'0');
    }

    if (count==0 || count%11==0){
         printf("%s is a multiple of 11.\n", number);
    } 
    else {
      printf("%s is not a multiple of 11.\n", number);
    }
    }
    return 0;
}