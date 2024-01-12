#include <stdio.h>

int main() {
    int num1, num2, num3, num4;

    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);

   
    int largest = num1;

    if (num2 > largest) {
        largest = num2;
    }


    if (num3 > largest) {
        largest = num3;
    }

  if (num4 > largest) {
        largest = num4;
    }

   
    printf("%d\n", largest);

    return 0;
}
