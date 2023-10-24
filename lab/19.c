#include <stdio.h>
int main()
{
    char c[1001];
    scanf("%s", &c);  
    for(int i = 0; c[i]; i++){
        printf("%d %d\n",c[i],c[i]);
    }
    
    return 0;
}