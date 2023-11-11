#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,i,j,A,min=0;
    scanf("%d",&n);
    int num[n];
    for (i=0;i<n;i++){
        scanf("%d",&num[i]);
    }

    for (i=0;i<n;i++){
        for (j=0;j<i;j++){
            A=abs(num[i]-num[j]);
            min+=A;
        }
    }
    printf("%d",min);
    return 0;
}