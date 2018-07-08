#include <stdio.h>

int main()
{
    enum gender {male, female};
    enum gender myGender = male;
    char character = 'x';
    char newline = '\n';
    int integer = 42;
    float decimal = 3.14;
    double bigdecimal = 6.022e+23;
    _Bool boolean = 1;
    char *home = "Venice, CA";

    printf("enum d: %d\n", myGender);
    printf("char c: %c\n", character);
    printf("char escape c: %c\n", newline);
    printf("int d: %d\n", integer);
    printf("int i: %i\n", integer);
    printf("float f: %f\n", decimal);
    printf("double e: %e\n", bigdecimal);
    printf("double g: %g\n", bigdecimal);
    printf("_Bool i: %i\n", boolean);

    printf("char string s: %s\n", home);

    return 0;
}

