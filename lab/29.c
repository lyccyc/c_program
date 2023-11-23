#include <stdio.h>
int change_position(int arr[],int Index,int dead,int n){
  size_t len=sizeof(arr) / sizeof(arr[0]);
  int new_num[len]; 
  int buryer=arr[Index]; //插入的值
  int i; //迴圈變數
  
  for (i=0; i<n; ++i)
  {
    if (i < dead)
    {
      new_num[i] = arr[i]; /*迴圈變數i小於插入值位置Index時,每一個元素所放的位置不變*/
    }
    else if (i == dead)
    {  
      new_num[i] = buryer; //i等於Index時,將插入值賦給陣列b
    }
    else{
        arr[i]=arr[i+1];
        new_num[i] = arr[i-1]; /*因為插入了一個新的元素,所以插入位置後的每一個元素所存放的位置都要向後移一位*/
    }
  }
  for(i=0;i<len;i++){
    printf("%d ",new_num[i]);
  }
  printf("\n");
}

int delete_be_kill(int arr[],int Index,int n,int k)
{
  int surviver[n-1]; 
  int i; //迴圈變數
  
  for (i=0; i<n; ++i)
  {
    if (i < Index)
    {
      surviver[i] =arr[i]; /*迴圈變數i小於插入值位置Index時,每一個元素所存放的位置不變*/
    }
    else
    {
      surviver[i] = arr[i+1]; /*刪除值後面的元素都往前移一位,要刪除的值直接被覆蓋*/
    }
  }
  int buryer=Index+k;
  if(buryer<n)
        change_position(surviver,buryer,Index,n);
  else{
    buryer=Index+k-(Index+1); 
    change_position(surviver,buryer,Index,n);
    }

}

int kill(int n,int k){
    int num[n];

    for(int i=1;i<=n;i++){
        num[i]=i;
        //printf("%d ", num[i]);
    }
    for(int i=0;i<n;i++){
        int be_kill=(num[i]+k-1);
        delete_be_kill(num,be_kill-1,n,k);
    }
    
}
int main() {
    int n, k;

    while (1) {
        // 輸入人數和步長
        scanf("%d %d", &n, &k);

        // 檢查是否結束
        if (n == 0 && k == 0) {
            break;
        }

        // 計算安全起始位置並輸出
        int safeStart = kill(n, k);
    }

    return 0;
}
