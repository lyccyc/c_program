/*規則:
    餘數同:奇先偶後
    奇數:先大再小
    偶數:先小再大如果有平局*/

// 由小到大:若 a 要排在 b 右邊，就回傳正的值，排在 b 左邊就回傳負的值，不交換就回傳 0
#include <stdio.h>
int cmp(int a, int b){
  return a - b;
}

int main(){ 
    int n,m;
    int i, j, temp; 
    char a=0;
    scanf("%d %d",&n,&m);
    int arr[n];
    for(int i=0;i<=n;i++){
        scanf("%[^\n]",arr[i]);
        fflush(stdin);
    }

    // 氣泡排序
    for(i=0; i<n; i++){
        for(j=0; j<n-i-1; j++){
            // 用 cmp 函式判斷陣列 arr 中的 j 項是否應排在 j+1 項後面
            //餘數小到大
            if((arr[j] % m) > (arr[j+1] % m)){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
            if (arr[j]%m ==arr[j+1]%m){
                //偶數由小到大
                if(arr[j]%2==0 && arr[j+1]%2==0){
                    if(cmp(arr[j], arr[j+1]) > 0){
                    // 交換陣列 arr 中的 j 與 j+1 項
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    }
                }
                //奇數由大到小
                if(arr[j]%2!=0 && arr[j+1]%2!=0){
                    if(cmp(arr[j],arr[j+1]) < 0){
                        temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                    }
                }
                if(arr[j]%2==0 && arr[j+1]%2!=0){
                    if(cmp(arr[j], arr[j+1]) < 0){
                        temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                    }
                }
            }
        }
    }
    for(i=0;i<=n;i++){
        if(i!=n)
            printf("%d\n",arr[i]);
    }
      
  return 0;
}