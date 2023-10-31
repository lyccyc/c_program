#include <stdio.h>
int main()
{
    int N,i,temp,prime=1;
    scanf("%d",N);
    int number[N];
    for (i=0;i<N;i++){
        scanf("%d",number[i]);
    }
    for (i=2;i<N;i++){
        if (number[i]%i==0){
            prime=0;
            break;
        }
    }
    /*是質數*/
    if (prime){

    }          
    /*for (i = 0; i < L; ++i) {
        for (int j = 0; j < i; ++j) {
        if (number[j] > number[i] && number[i]%2) {
            temp =number[j];
            number[j] = number[i];
            number[i] = temp;
            }
        }
    }*/

    return 0;
}