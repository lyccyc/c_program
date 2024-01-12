#include <stdio.h>
#include <stdlib.h>

// Function to compare two numbers based on the described rules
int compare(const void *a, const void *b) {
    int mod_a = abs(*(int *)a % 2);
    int mod_b = abs(*(int *)b % 2);

    // If modulo values are different, sort based on modulo
    if (mod_a != mod_b) {
        return mod_a - mod_b;
    }

    // If both numbers have the same parity, sort based on their values
    if (*(int *)a % 2 == 0) {
        // Both are even, so sort in ascending order
        return (*(int *)a - *(int *)b);
    } else {
        // Both are odd, so sort in descending order
        return (*(int *)b - *(int *)a);
    }
}

int main() {
    int N, M;

    // Get the number of elements (N) and the positive integer (M)
    printf("Enter the number of elements (N): ");
    scanf("%d", &N);

    printf("Enter the positive integer (M): ");
    scanf("%d", &M);

    int numbers[N];

    // Get the N numbers
    printf("Enter %d numbers:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &numbers[i]);
    }

    // Use the qsort function to sort the array based on the compare function
    qsort(numbers, N, sizeof(int), compare);

    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}
