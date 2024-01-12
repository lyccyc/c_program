#include <stdio.h>
#include <math.h>

int main(){
    int n,i;
    double standard = 0,value = 0,compute = 0,sigma = 0;

    while(scanf("%d" ,&n) != EOF){
        int V[n];
        for(i=0; i<n ; i++){
            V[n] = 0;
            scanf("%d" ,&V[i] );
            compute += V[i];
        }
        compute /= n;

        for(i=0; i<n ; i++){
            standard = V[i] - compute;
            standard *= standard;
            sigma += standard;
        }
        sigma /= n;
        value = sqrt(sigma);

        printf("%.2f",value);
    }
    return 0;
}
