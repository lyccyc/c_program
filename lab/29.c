#include <stdio.h>
#define max 100

int main() {
    int n, k;

    // 輸入人數和步長
    scanf("%d %d", &n, &k);
    int num[max];
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
    int start=num[0];

    for(int i=0;i<n;i++){
      int dead=start+k-1; //2(number)
      
      if(start==0){
        start=num[dead-1+1];
      }

      

      printf("dead people:%d  ",num[dead-1]);
      num[dead-1]=0;

      int buryer=dead+k; //4
      if(num[buryer-1]==0)
        buryer+=1;
      num[dead-1]=num[buryer-1];
      num[buryer-1]=0;
      printf("buryer:%d\n",num[dead-1]);

      start=num[dead-1];

      printf("now number:\n");
      for(int i=0;i<n;i++)
        printf("%d",num[i]);
      printf("\n");

      start=num[daad-1];
      
    }


    return 0;
}

