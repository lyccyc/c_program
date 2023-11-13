#include <stdio.h>
#include <stdlib.h>

int main(){
    int a,index=0,b[32];
    scanf("%d",&a);

    while(a>0){
        b[index]=a%2;
        a/=2;
        index+=1;
    }

    for (int i=index-1;i>=0;i--){
        printf("%d",b[i]);
    }

    return 0;
}