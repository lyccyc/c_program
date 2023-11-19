#include <stdio.h>
#include <math.h>
int main(){
    double x=2;
    double y=5;
    double z=pow(x,y);
    printf("%.0f 的 %0.f 次方是 %0.f\n",x,y,z);
    return 0; 
}
