#include <stdio.h>

char* getUserInput(char s[], int lim, int wrap) {
    int c, i;
    int charCount = 0;

    // Read input into the array s, within the specified limit
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        // Adds line break if len >= wrap
        if (charCount >= wrap) {
            s[i] = '\n';
            ++i;
            charCount = -1;
        }
        s[i] = c;
        ++charCount;
    }
    
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';  // Null-terminate the string

    return s;  // Return the pointer to the character array
}

int main(void) {
    char input[100];  // Allocate space for input
    int wrap = 15; // Sets the max length for line before it wraps

    // Get user input and print it
    printf("Enter a string: ");
    char *result = getUserInput(input, 100, wrap);
    printf("You entered:\n%s\n", result);

    return 0;
}