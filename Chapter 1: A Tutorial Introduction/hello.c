#include <stdio.h>

// Function prototypes
void helloWorld(void);
void printLine(void);
void fToC(void);
void cToF(void);
void parrot(void);
int power(int base, int exponent);
void powerTable(int base);
void printLongest();
void copy(char to[], char fromp[]);
int getLineLen(char s[], int lim);

// Prints hello world
void helloWorld() {
    printf("hello, world\n");
}

// Prints line to separate multiple outputs
void printLine() {
    printf("\n-----------------------\n");
}

// Prints table converting from Fahrenheit to Celsius
void fToC() {
    float farh, c;
    const int low = 0;
    const int high = 300;
    const int step = 20;
    
    farh = low;
    
    printf("Fahrenheit to Celsius\n\n");
    printf("  F     C\n");
    
    while (farh <= high) {
        c = (5.0 / 9.0) * (farh - 32.0);
        printf("%3.0f %6.1f \n", farh, c);
        farh = farh + step;
    }
}

// Prints table converting from Celsius to Fahrenheit
void cToF() {
    /* I'm using #define below because it's in the book, but my understanding
    is that it is outdated and the const int above is safer (type and scope) */
    #define LOWER -20 /* Lower limit of the table */    
    #define UPPER 300 /* Upper limit of the table */
    #define STEP 20 /* Step size */

    float farh, c;
    
    printf("Celsius to Fahrenheit\n\n");
    printf("  C     F\n");
    
    for (c = UPPER; c >= LOWER; c = c - STEP) {
        farh = 32 + (9.0 / 5.0) * c;
        printf("%3.0f %6.0f \n", c, farh);
    }
}

// Gets keyboard input and outputs the same
void parrot() {
    int c;

    while ((c = getchar()) != EOF) {
        putchar(c);
    }
}

// Tests if an input is EOF or not. Also prints EOF (-1)
void testEOF() {
    int c;
    int test;
    c = getchar();

    test = c == EOF; // If input is text, output is 0. If input is ctrl+d, output is 1
    printf("%d\n", test);

    printf("The value of EOF is: %d", EOF);
}

// Uses empty loop to count number of characters in keyboard input
void charCount() {
    double nc;

    for (nc = 0; getchar() != EOF; ++nc) {
        ; // Empty body since what matters is the counter in the for loop
    }

    printf("Characters: %.0f\n", nc);
}

// Counts number of lines, tabs, and blank spaces
void lineCount() {
    int c, lines, tabs, blanks;

    lines = 0;
    tabs = 0;
    blanks = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            ++lines;
        }
        if (c == '\t') {
            ++tabs;
        }
        if (c == ' ') {
            ++blanks;
        }
    }

    printf("Lines: %d\nTabs: %d\nBlanks: %d\n", lines, tabs, blanks);
}

// Replaces tabs and line breaks with \t and \n
void replace() {
    int c;

    while ((c = getchar()) != EOF) {
       if (c == '\n') {
            putchar('\\');
            putchar('n');
        }
        else if (c == '\t') {
            putchar('\\');
            putchar('t');
        }
        else {
            putchar(c);
        } 
    }
    printf("\n");
}

// Counts number of words
void wordCount() {
    int c, state, wordCount;
    const int IN = 1;
    const int OUT = 0;

    wordCount = 0;
    state = OUT;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
        }
        else if (state == OUT) {
            state = IN;
            ++wordCount;
        }
    }

    printf("Words: %d\n", wordCount);
}

// Counts number of each digit and prints histogram
void digitCount() {
    int digits[10];
    int i, j, c;

    for (i = 0; i < 10; ++i) {
        digits[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            ++digits[c - '0'];
        }
    }

    // print histogram
    for (i = 0; i < 10; ++i) {
        printf("\n%d: |", i);
        for (j = 0; j < digits[i]; ++j) {
            printf("-");
        }
        printf("\n");
    }
}

// Raises base (integer) to power of exponent (integer >= 0)
int power(int base, int exponent) {
    int result, i;

    result = 1;
    
    if (exponent < 0) {
        printf("Please enter a non-negative number");
        return -1;
    }
    else {
        for (i = 0; i < exponent; ++i) {
            result = result * base;
        }
        return result;
    }
}

// Creates a table with using power()
void powerTable(int base) {
    int i;
    int highestExponent = 6;

    printf(" Powers of %d\n", base);
    printf(" Base  Exp Result\n"); 
    printf("-----------------\n");
    for (i = 0; i <= highestExponent; ++i) {
        printf("| %2d | %2d | %3d |\n", base, i, power(base, i));
    }
    printf("-----------------\n");
}

// Collection of functions to print the longest line

void printLongest() {
    int maxLine = 1000; // Maximum input line size
    int len; // Current line length
    int max; // Maximum length seen so far
    char line[maxLine]; // Current input line 
    char longest[maxLine]; // Longest line is saved here

    max = 0;
    while ((len = getLineLen(line, maxLine)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) { // Checks if there was actually a non-empty line
        printf("\n%s\n", longest);
    }
}

void copy(char to[], char from[]) {
    int i = 0;

    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}

int getLineLen(char s[], int lim) {
    int c, i;

    // 3 conditions: not greater than maxLine limit; char isn't EOF; char isn't line break /n
    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    
    s[i] = '\0';
    return i;
}


int main(void) {
    printLongest();
    return 0;
}