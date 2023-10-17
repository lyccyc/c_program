#include <stdio.h>

int main(){
    int n,temp;
    double ave;

    while(scanf("%d" ,&n) != EOF){
        int V[n];
        for(int i=0; i<n ; i++){
            V[n] = 0;
            scanf("%d" ,&V[i] );
            ave+=V[i];
        }
        ave/=n;

        int fail=V[0];
        for (int i=1; i<n; i++) {
            if (V[i] > V[i+1]){
                temp=V[i+1];
                V[i+1]=V[i];
                V[i]=temp;

            if (V[i]<ave){
                printf("%d",i+1);
            }
        }
    }
    return 0;
}
}
