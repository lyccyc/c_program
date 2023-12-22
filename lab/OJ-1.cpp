#include <assert.h>
#include <stdio.h>
 
int main()
{
   int a;
   char str[50];
     
   printf("輸入一個整數:： ");
   scanf("%d", &a);
   assert(a >= 10);
   printf("輸入的整數是： %d\n", a);
    
   printf("輸入字串： ");
   scanf("%s", str);
   assert(str != NULL);
   printf("輸入的字串是： %s\n", str);
    
   return(0);
}