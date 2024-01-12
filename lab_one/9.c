#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);

    int m1=n%3;
    int m2=n%7;
    int m3=n%11;

    if (m1==2 && m2==5 && m3==7){
        printf("YES");
    }

    else{
        printf("NO");
    }
  
  return 0;}