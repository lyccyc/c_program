#include <stdio.h>

int main() {

  int n;
  int reminder;
  int reverse = 0;
  scanf("%d", &n);

  while (n > 0) {
    reminder=n%10;
    reverse = reverse * 10 + reminder;
    n /= 10;    
  }

  printf("%04d\n", reverse);

  return 0;
}