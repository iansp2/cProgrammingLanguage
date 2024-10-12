#include <stdio.h>

// Function prototypes
void helloWorld(void);
void printLine(void);
void fToC(void);
void cToF(void);

void helloWorld() {
    printf("hello, world\n");
}

void printLine() {
    printf("\n-----------------------\n");
}

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

void cToF() {
    /* I'm using #define below because it's in the book, but my understanding
    is that it is outdated and the const int above is safer (type and scope) */
    #define LOWER -20 /* Lower limit of the table */    
    #define UPPER 300 /* Upper limit of the table */
    #define STEP 20 /* Step size */

    float farh, c;
    
    printf("Celsius to Fahrenheit\n\n");
    printf("  C     F\n");
    
    for (c=UPPER; c>=LOWER; c=c-STEP) {
        farh = 32 + (9.0 / 5.0) * c;
        printf("%3.0f %6.0f \n", c, farh);
    }
}

int main(void) {
    printLine();
    helloWorld();
    printLine();
    fToC();
    printLine();
    cToF();
    printLine();

    return 0;
}