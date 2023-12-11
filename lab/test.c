#include <stdio.h>

int main(){
      int i,j,k= 0;
      int row,column,amount;
      scanf("%d %d %d",&row,&column,&amount);
      int number[amount][3];
      for(i= 0; i < amount; i++){
          scanf("%d %d %d\n",&number[i][0],&number[i][1],&number[i][2]);
      }
     
      
      for(i= 0; i < row; i++){
          for(j= 0; j < column; j++){
              if(i == number[k][0] && j == number[k][1]){
                printf("%d ",number[k][2]);
                //k++;
              }else{
                printf("%d ",0);
                //k++;
              }  
          }
          k++;
          printf("\n");
      }
    return 0;
}