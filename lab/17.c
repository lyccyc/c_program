#include <stdio.h>

int main(){
    int n,m,num,temp,x;
    int mod,mod_1,mod_2;
    int i,j,k,l;
    //輸入
    scanf("%d %d",&n,&m);
    x=n/2;
    mod=n/m;
    int number[n],odd[x],even[x];

    for (i=0;i<n;i++){
        scanf("%d\n",&number[i]);
    }
    
    for (i=0;i<n;i+2){
        for(j=0;j<x;j++){
            odd[j]=number[i];
            mod_1=odd[i]%m;
            mod_2=odd[j]%m;
        }
        for (k=0;k<n;k++){
            for(l=0;l<k;l++){
                if (odd[k]>odd[l]){
                    temp=odd[k];
                    odd[k]=odd[l];
                    odd[l]=temp;
                }
            }
        }
        printf("%d",odd[i]);
        }
    
    for (i=1;i<n;i+2){
        for(j=0;j<x;j++){
            even[j]=number[i];
            mod_1=even[i]%m;
            mod_2=even[j]%m;
        }
        for (k=0;k<n;k++){
            for(l=0;l<k;l++){
                if (even[k]>even[l]){
                    temp=even[k];
                    even[k]=even[l];
                    even[l]=temp;
                }
            }
        }
        printf("%d",even[i]);
        }

    for(i=0;i<n;i++){
        printf("%d\n%d\n",odd[i],even[i]);
    }
}
  
    