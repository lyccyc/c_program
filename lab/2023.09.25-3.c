#include <stdio.h>

int main()
{
    int a,b,c,d;
  	int temp1,temp2;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    if(a>b){ //變數交換
        temp1=a;
        a=b;
        b=temp1;
    }
    
    if(c>d){ //變數交換
        temp2=c;
        c=d;
        d=temp2;
    }
    
    if(a<c && c<b || a<d && d<b || c<a && a<d || c<b && b<d){
        printf("overlay");
    }
    else{
        printf("no overlay");
    }
   
    return 0;
}