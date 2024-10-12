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
    float farh, c;
    const int low = -20;
    const int high = 160;
    const int step = 20;
    
    c = low;

    printf("Celsius to Fahrenheit\n\n");
    printf("  C     F\n");
    
    while (c <= high) {
        farh = 32 + (9.0 / 5.0) * c;
        printf("%3.0f %6.0f \n", c, farh);
        c = c + step;
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