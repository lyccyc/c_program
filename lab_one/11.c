#include <stdio.h>
#include <math.h>

int main() {
    int distance;
    float toll;

    scanf("%d", &distance);

        if (distance > 200) {
            toll = 200.0 * 1.2 + (distance - 200.0)* 1.2 * 0.75;
        } 
        
        else {
            toll = distance * 1.2;
        }

        
        int roundedToll = (int)round(toll);
        
        printf("%d\n", roundedToll);

    return 0;
}
