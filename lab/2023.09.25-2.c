#include <stdio.h>

int main() {

  int n;
  int reminder;
  int reverse = 0;
  scanf("%d", &n);

  while (n > 0) {
    reminder=n%10;
    reverse = reverse * 10 + reminder; //40+2=43   430+2=432 4320+1=4321
    n /= 10;    //1
  }

  printf("%04d\n", reverse);

  return 0;
}