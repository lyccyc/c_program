#include <stdio.h>

int main(){
    int n,j=0;
    float ave=0;

    scanf("%d" ,&n);
    int V[n];
    for(int i=0; i<n ; i++){
        V[n] = 0;
        scanf("%d" ,&V[i] );
        ave+=V[i];
    }
    ave/=n;

    for (int i = 0; i < n; i++) {
            int fail=V[i];
            if (fail<ave){
                j+=1;
        }
        }
    printf("%d",j);
    return 0;
    }
        
   
   