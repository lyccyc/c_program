#include <stdio.h>
int main()
{
    while(1){
        char c[1001];
        scanf("%s", c);
        int i,j,k,temp,ans;
        int cnt[128] = {0};
        for(i = 0; c[i]; i++){
            cnt[c[i]]++;
            /*if (c[i]!=c[i+1]){
                for (k = 0; k < cnt[c[i]]; ++k) {
                    for ( j = 0; j < k; ++j) {
                        if (cnt[c[j]] > cnt[c[k]]) {
                            temp =cnt[c[j]] ;
                            cnt[c[k]]  = cnt[c[i]] ;
                            cnt[c[k]] = temp;
                        }
                    }
                }
            }*/
            printf("%d %d\n",c[i],cnt[c[i]]);
        }
    }
    return 0;
}