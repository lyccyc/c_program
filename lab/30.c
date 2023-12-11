#include <stdio.h>
#define max 10000



int main(){
    int num[10000]={0};
    int start,high,end;
    while(scanf("%d %d %d", &start, &high, &end) != EOF){
        for(int i = start; i < end;i++){
            if(high>num[i])
                num[i] = high;
        }
    }
    
    for(int i = 0; i < max -1; i++){
        if(num[i]!=num[i+1]){
            printf("%d %d ", i+1, num[i+1]);
        }
    }
    return 0;
}