#include <stdio.h>
#include <stdlib.h>
int main(){
    int row,column,data;
    int row_number,column_number,value;
    scanf("%d %d %d", &row, &column, &data);
    int num[row][column]= {0};

    for(int i=0;i<data;i++)
        scanf("%d %d %d",&row_number,&column_number,&value);

    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            printf("%d",num[i][j]);
        }
    }

    return 0;
}