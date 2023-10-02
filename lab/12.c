#include <stdio.h>

int main() {
    int num;
	int digit;
    int found = 0; 
    
  	scanf("%d", &num);

        while (num > 0) {
            digit = num % 10; // 最後一位
            if (digit == 4) {
                found = 1;
                break; 
            }
            num /= 10; 
        }

       
        if (found==1) {
            printf("Yes");
        } 
        else {
            printf("No");
        }

    return 0;
}
