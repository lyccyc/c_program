#include <stdio.h>

int F(int x) {
    return 3 * x + 1;
}

int G(int x, int y) {
    return x * y - 3;
}

int main() {
    char str[50];
    int num,result;
    gets(str);
    if(str[0]=="F" ){
        if (str[2]>='0' && str[2]<='9'){
            num=str[2]-'0';
            result=F(num);
        }

        else if(str[2]="G"){
            
        }
    printf("Output: %d\n", result);

    return 0;
}
