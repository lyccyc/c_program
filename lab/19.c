#include <stdio.h>
int main()
{
    while(1){
        char c[1001];
        scanf("%s", c);
        int i,j,temp;
        int cnt[128] = {0};
        for(i = 0; c[i]; i++){
            cnt[c[i]]++;
        }
    }
    return 0;
}