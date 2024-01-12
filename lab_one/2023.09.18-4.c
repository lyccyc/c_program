#include <stdio.h>

int main(){
    int a,b,c;
    float ave;

    scanf("%d %d %d", &a,&b,&c);
    ave=((float)(a+b+c))/3;
    
    printf("%.6f\n", ave);

    return 0;
}