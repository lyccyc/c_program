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

int findMax(int arr[], int n) {
    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main(){
    int n;
    while(scanf("%d\n",&n) != EOF){
        int i,j,a=0,b,A=0,B=0;
        int med,min,ans2=0,ans3=0,max;
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
        ans[0]=med;
        max=findMax(num,n);
        b=max-med;

        for (i=1;i<n;i++){
            if (b >= 0 && b<=max){
                ans[i]=b;
                a+=1;
            }
            b+=1;
        }

        min=findMin(ans,a);//找到中位數最小值

        for (i=0;i<n;i++){
            for (j=0;j<a;j++){
                if (num[i]==ans[j]){
                    ans2+=1;
                    break;
                }
            }
        }

        for (i=0;i<a;i++){
            for (j=0;j<i;j++){
                if(ans[i]!=ans[j])
                    ans3+=1;
            }
            
        }
        printf("%d %d\n",min,ans2);
    }
    return 0;
}