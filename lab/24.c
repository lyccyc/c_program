#include <stdio.h>
#include <string.h>

int main() {
    char s[1000],ans[1001];
    scanf("%s",s);
    int a,i,j,b;
    a=strlen(s);

    for(i=0;i<a;i++){
        for (j=0;j<a;j++){
            if (s[i]!=s[j]){
                ans[i]+=s[j];
                b+=1;
            }
        }
    }

    for (i=0;i<b;i++){
        printf("%s", ans[i]);
    }
    

    return 0;
}
