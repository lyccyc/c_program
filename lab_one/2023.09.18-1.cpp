#include <stdio.h>

int main(){
    int a,b,c;
    float ave;

    scanf("%d %d %d", &a,&b,&c);
    ave=(a+b+c)/3;
    
    printf("%.6f", ave);

    return 0;
}
