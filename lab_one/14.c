#include <stdio.h>

int main(){
    int n,temp;
  	float compute=0;
    float ave; 
    scanf("%d" ,&n);
   	int V[n];
        for(int i=0; i<n ; i++){
            V[n] = 0;
            scanf("%d" ,&V[i] );
            compute += V[i];
        }
    
  
    for (int i=0;i<=n;i++){
        for (int j=0;j<n-1;j++){
            if (V[j]>V[j+1]){
            temp=V[j];
            V[j]=V[j+1];
            V[j+1]=temp;
             }
         }
    }

    compute=compute-V[0]-V[1]-V[2]-V[n-1]-V[n-3]-V[n-2];
    ave=compute/(n-6);
    printf("%.2f",ave);
  return 0;
}