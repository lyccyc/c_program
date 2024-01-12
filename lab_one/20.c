#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int findMedian(int arr[],int n){
    int mid_1,mid_2;
    
   
    return mid_1,mid_2;
}

int main() {
    int n;

    // 讀取陣列大小
    while(scanf("%d", &n)!=EOF){
         // 宣告陣列
        int arr[n];
        int mid_1,mid_2,ans2=0,ans3=1,i;

        // 讀取陣列元素
        for ( i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        qsort(arr,n,sizeof(int),cmpfunc);
        // 找到中位數
        if(n%2==0){
            mid_1=arr[(n-1)/2];
            mid_2=arr[n/2];
        }
    
        else{
            mid_1=arr[n/2];
            mid_2=mid_1;
        }
        
        for(i=0;i<n;i++){
            if(mid_1==arr[i] || mid_2==arr[i])
                ans2+=1;
        }

        ans3=mid_2-mid_1+1;
        
        printf("%d %d %d\n",mid_1,ans2,ans3);

    }
   
    return 0;
}
