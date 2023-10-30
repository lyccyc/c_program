#include <stdio.h>

int main(){
    int n,m,num,temp,x;
    int mod_1,mod_2;
    int i,j;
    
    scanf("%d %d",&n,&m);
    x=n/2;
    int number[n],odd[x],even[x];

    for (i=0;i<n;i++){
        scanf("%d\n",&number[i]);
    }

    
    
    /*
    for (i=0;i<n;i+2){
        for (j=0;j<x;j++){
            odd[j]=number[i];
            if (odd[j]<odd[j+1]){
                temp = odd[j];
                odd[j] = odd[j+1];
                odd[j+1] = temp;
                }
            mod_1=odd[j]%m;
        }
    }
    for (i=0;i<n;i+2){
        for (j=0;j<x;j++){
            even[j]=number[i];
            if (even[j]>even[j+1]){
                temp = even[j];
                even[j] = even[j+1];
                even[j+1] = temp;
                }
            mod_2=even[j]%m;
        }
    }

    while ( mod_1=mod_2 ){
        for (i=0;i<n;i++){
            printf("%d %d",odd[i],even[i]);
        }      
    }      
    }*/
    
