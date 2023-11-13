#include <stdio.h>

int main(){
      int N,i,j,temp,mid1,mid2;
    while(scanf("%d",&N) != EOF){
        int x[N];
        int a = 0;
          
        for(i= 0; i < N; i++)
            scanf("%d",&(x[i]));
            
        for(i= N-2; i >= 0; i--){
            for(j= 0; j <= i; j++){
                if(x[j] > x[j+1]){
                    temp = x[j];
                    x[j] = x[j+1];
                    x[j+1] = temp;
                }
            }
        }
        if(N% 2 == 0){
            mid1 = x[(N-1)/2];
            mid2 = x[N/2];
        }else{
            mid1 = x[(N-1)/2];
            mid1 = mid2;
        }
        
        for(i= 0; i < N; i++)
            if(mid1-x[i] == 0 || mid2-x[i] == 0)
                a++;
        
        printf("%d %d %d\n",mid1,a,(mid2-mid1+1));
    }
    return 0;
}
    /*int n,temp;
    float ave;

    ave=32.9;
    n=(int)ave;
    printf("%d",n);
    /*while(scanf("%d" ,&n) != EOF){
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

}*/
