#include <stdio.h>

int main() {
    int start1, end1, start2, end2;
    int temp;
    scanf("%d %d %d %d", &start1,&end1,&start2, &end2);

    if (start1>end1){
            temp=start1;
            start1=end1;
            end1=temp;
        }

    if (start1 <= start2 <=end1 || start1 <= end2 <= end1) {
            printf("overlay\n");
            }
    else if (start1 >= start2 >= end1 || start1 >= end2 >= end1) {
            printf("overlay\n");
            } 
    else {
            printf("no overlay\n");
            } 
}