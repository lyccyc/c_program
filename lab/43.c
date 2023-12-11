#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char integer[1000];
  char decimal[1000];
} DeciVar;

// Function to add two DeciVar values
DeciVar addDeciVars(DeciVar num1, DeciVar num2) {
  DeciVar result;
  int carry = 0;

  // Initialize result integer and decimal parts to zero
  strcpy(result.integer, "0");
  strcpy(result.decimal, "0");

  // Add decimal parts
  int len1 = strlen(num1.decimal);
  int len2 = strlen(num2.decimal);
  int maxLen = len1 > len2 ? len1 : len2;

  for (int i = 0; i < maxLen; i++) {
    int digit1 = (i < len1) ? (num1.decimal[i] - '0') : 0;
    int digit2 = (i < len2) ? (num2.decimal[i] - '0') : 0;
    int sum = digit1 + digit2 + carry;

    result.decimal[i] = (sum % 10) + '0';
    carry = sum / 10;
  }

  if (carry > 0) {
    result.decimal[maxLen] = carry + '0';
    result.decimal[maxLen + 1] = '\0';
  } else {
    result.decimal[maxLen] = '\0';
  }

  // Add integer parts
  len1 = strlen(num1.integer);
  len2 = strlen(num2.integer);
  maxLen = len1 > len2 ? len1 : len2;

  for (int i = 0; i < maxLen; i++) {
    int digit1 = (i < len1) ? (num1.integer[i] - '0') : 0;
    int digit2 = (i < len2) ? (num2.integer[i] - '0') : 0;
    int sum = digit1 + digit2 + carry;

    result.integer[i] = (sum % 10) + '0';
    carry = sum / 10;
  }

  if (carry > 0) {
    result.integer[maxLen] = carry + '0';
    result.integer[maxLen + 1] = '\0';
  } else {
    result.integer[maxLen] = '\0';
  }

  return result;
}

int main() {
  DeciVar num1, num2, result;

  // Read the first decimal value
 
  scanf("%s.%s", num1.integer,num1.decimal);

  scanf("%s.%s", num2.integer,num2.decimal);

  // Add the two decimal values
  result = addDeciVars(num1, num2);

  // Print the result
  printf("%s.%s\n", result.integer, result.decimal);

  return 0;
}

