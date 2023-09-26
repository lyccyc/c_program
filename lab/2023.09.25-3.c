#include <stdio.h>

int main() {
    int start1, end1, start2, end2;

    scanf("%d %d %d %d", &start1,&end1,&start2, &end2);
    
    if (end1 < start2 || end2 < start1) {
        printf("no overlay\n");
    } 
  	else {
        printf("overlay\n");
    }

    return 0;
}
