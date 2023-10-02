#include <stdio.h>
#include <math.h>

int main() {
    float inputNumber;
    scanf("%f", &inputNumber);

    float roundOff = ((inputNumber+0.005) * 100) / 100.0;
    float roundDown = floor(inputNumber * 100) / 100.0;

    printf("%.2f\n", roundOff);
    printf("%.2f\n", roundDown);

    return 0;
}