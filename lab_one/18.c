#include <stdio.h>

int main(){
    int run;
    scanf("%d",&run);
    while (run--){
        int L,i,time=0;
        scanf("%d",&L);
        int car[L];
        for (i = 0;i < L; i++){
            scanf("%d",&car[i]);
        }
        for (i = 0; i < L; ++i) {
            for (int j = 0; j < i; ++j) {
            if (car[j] > car[i]) {
                int temp = car[j];
                car[j] = car[i];
                car[i] = temp;
                time+=1;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n",time);
    }
   
    return 0;
}