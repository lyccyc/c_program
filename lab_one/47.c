/*************************************************************
function name: convertToDifferentBase
description: Convert a decimal number @dec to the number with different @base and store the result as a string in result
return vaule: Result after convert.
notice: The letter you see in the number should be upper case.
*************************************************************/
char *convertToDifferentBase(int dec, int base, char *result) {
  	int index = 0;
    while (dec> 0) {
        int remainder = dec % base;

        if (remainder < 10) {
            result[index++] = (char)(remainder + '0');
        } else {
            result[index++] = (char)(remainder - 10 + 'A');
        }

        dec /= base;
    }

    int start = 0;
    int end = index - 1;
    while (start < end) {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        start++;
        end--;
    }

    return result;
}
