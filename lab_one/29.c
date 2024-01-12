#include <stdio.h>
#define max 100

int main() {
    int n, k;

    // 輸入人數和步長
    scanf("%d %d", &n, &k);
    int num[max]={0};
    // 檢查是否結束
    if (n == 0 && k == 0) {
        return 0;
    }
    for(int i=0;i<n;i++)
      num[i]=i+1;
    //index: 0 1 2 3 4
    //numbe: 1 2 3 4 5
    /*[1, 2, 3, 4, 5]
      [1, 4, 3, 0, 5]
      [1, 0, 3, 0, 4]
      [0, 0, 1, 0, 4]
      [0, 0, 4, 0, 0]*/

    int dead =-1 ;

    for(int i=0;i<n-1;i++){
      for(int j=0;j<k;){
        if (dead + 1 == n) dead = -1;
        if(num[dead+1]!=0){
          dead++;
          j++;
        }
        dead++;
      }

      printf("dead people:%d  ",dead);
      int buryer=dead;
      for(int j=0;j<k;){
        if (buryer + 1 == n)  buryer=-1;
        if(num[buryer+1]!=0){
          buryer++;
          j++;
        }
        buryer++;
      }
       //4
      if(buryer==0)
        buryer+=1;
      num[dead-1]=num[buryer-1];
      num[buryer-1]=0;
      printf("buryer:%d\n",buryer);

      printf("now number:\n");
      for(int i=0;i<n;i++)
        printf("%d",num[i]);
      printf("\n");

      start=num[dead-1];
      if(start==0){
        start+=1;
      }

      
    }


    return 0;
}

