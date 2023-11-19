/*質數要排在非質數的前面，如果兩個數都是質數，數字大的要排在前面，如果兩個數都不是質數，數字小的要排在前面。**/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

bool isPrime(int a){
    if(a<=1)
        return false;

    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            return false;  // 如果有其他因數，則不是質數
        }
    }

    return true;  // 是質數
}

int cmp(int a, int b){
  return a - b;
}

int main(){

    int n,i,j,temp;
    scanf("%d",&n);

    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    qsort(arr, n, sizeof(int), cmpfunc);

    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            //兩個都是質數
            if(isPrime(arr[j]) && isPrime(arr[j+1])){
                if(cmp(arr[j],arr[j+1]) < 0){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                }
            }
            //兩個都不是質數
            if(!isPrime(arr[j]) && !isPrime(arr[j+1])){
                if(cmp(arr[j],arr[j+1]) > 0){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                }
            }
            if(!isPrime(arr[j]) && isPrime(arr[j+1])){
                if(cmp(arr[j],arr[j+1]) < 0){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                }
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    } 
    return 0;
}