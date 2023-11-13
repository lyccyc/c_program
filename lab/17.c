#include <stdio.h>
int cmp(int a,int b,int m){
    if(a%m==b%m){
        //奇數
        if (a%2==0 && b%2==0){
            if (a<b){
                int temp=a;
                a=b;
                b=temp;
            }
        }
        if (a%2==0 && b%2!=0){
                int temp=a;
                a=b;
                b=temp;
        }
        if (a%2!=0 && b%2!=0){
            if (a>b){
                int temp=a;
                a=b;
                b=temp;
            }
        }
    }
    return a,b;
}

int main(){
    int N,m;
    scanf("%d %d",&N,&m);
    int num[N];
    for(int i=0;i<N;i++){
        scanf("%d",&num[i]);
    }

    for(int i=0;i<N;i++){
        printf("%d\n", cmp(num[i],num[i+1],m));
    }
}