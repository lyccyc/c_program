#include <stdio.h>
#include <stdlib.h>

int median(int arr[],int n){
    int median=(n+1)/2-1;
    return arr[median];
}

void sort(int arr[],int n){
    for (int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int findMin(int arr[], int n) {
    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main(){
    int n;
    while(scanf("%d\n",&n) != EOF){
        int i,j,a=0,A=0,B=0;
        int med,min,ans2=0,ans3=0;
        int ans[n],num[n];
        /*
        1. 符合 A 條件的最小值(min)
        2. 陣列中有多少個值符合 A 條件(ans2)
        3. 所有整數中有多少個數字符合 A 條件(ans3)*/

        for (i=0;i<n;i++){
            scanf("%d",&num[i]);
        }

        sort(num,n);
        med=median(num,n);
        
        for (i=0;i<n;i++){
            if (med <= num[i]){
                ans[i]=num[i];
                a+=1;
            }
        }
        min=findMin(ans,a);//找到中位數最小值
        for (i=0;i<n;i++){
            for (j=0;j<a;j++){
                if (ans[j] <=num[i] )
                    A+=1;
                else if (ans[j] >= num[i])
                    B+=1;
                if (A <= n/2 && B<= n/2)
                    ans2+=1;
            }
           
        }
        printf("%d %d\n",min,ans2);
    }
    return 0;
}