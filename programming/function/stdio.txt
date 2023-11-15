#include <stdio.h>

int main(){
    char c,str[10],buf[10];

    //輸入和輸出buf
    printf("輸入一個字串:\n");
    fgets(buf,sizeof(buf),stdin);

    puts("輸入的字串為:");
    puts(buf);
    //輸入和輸出c
    printf("請輸入一個字元：");
    c=getchar();//取得第一個字元
    putchar(c);//輸出第一個字元
    putchar('\n');
    
    return 0;
}
