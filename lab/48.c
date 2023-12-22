#include <stdio.h>
#include <stdlib.h>

// Function to generate the next term in the look-and-say sequence
char* generateNextTerm(char* currentTerm) {
    int count = 1;
    char digit = currentTerm[0];
    int length = 1;

    // Count the consecutive occurrences of the same digit
    while (currentTerm[length] != '\0' && currentTerm[length] == digit) {
        count++;
        length++;
    }

    // Generate the next term
    char* nextTerm = (char*)malloc(2 * length * sizeof(char)); // Allocate enough space
    sprintf(nextTerm, "%d%c", count, digit);

    // Recursively generate the rest of the next term
    char* restNextTerm = generateNextTerm(currentTerm + length);
    strcat(nextTerm, restNextTerm);

    // Free the memory allocated for the rest of the next term
    free(restNextTerm);

    return nextTerm;
}

// Function to display the first N terms of the look-and-say sequence
void displayLookAndSay(int N, char* currentTerm) {
    if (N <= 0) {
        return;
    }

    printf("%s\n", currentTerm);

    // Recursively generate and display the next term
    char* nextTerm = generateNextTerm(currentTerm);
    displayLookAndSay(N - 1, nextTerm);

    // Free the memory allocated for the next term
    free(nextTerm);
}

int main() {
    int N = 10;
    char initialTerm[] = "1";

    printf("The first %d terms of the look-and-say sequence are:\n", N);
    displayLookAndSay(N, initialTerm);

    return 0;
}
