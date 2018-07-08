#include <stdio.h>

int main() {

    int x = 41;
    _Bool true = 1;
    _Bool false = 0;
    _Bool r; 

    // ++<var> increments in place, <var>++ increments after line execution
    // so this prints 41 because x is not inc until after line execution
    printf("x++: %i\n", x++);

    // while this prints 42
    printf("++x: %i\n", ++x);

    r = true || false;
    printf("true or false: %d\n", r);

    r = true && false;
    printf("true and false: %d\n", r);

    unsigned int a = 60; // 0011 1100
    unsigned int b = 13; // 0000 1101
    unsigned int aa = 2; // 0000 0010
    int c = 0;
    int d = 0;
    int e = 0;
    int f = 0;
    int g = 0;

    c = a & b; // 0000 1100
    d = a | b; // 0011 1101
    e = b << 1; // 0001 1010
    f = e << 1; // 0011 0100
    g = aa << 2; // 0000 1000

    printf("60 & 13: %d\n", c);
    printf("60 | 13: %d\n", d);
    printf("13 << 1: %d\n", e);
    printf("26 << 1: %d\n", f);
    printf("2 << 2; %d\n", g);


    int int_s = sizeof(int);
    int short_s = sizeof(short);
    int long_s = sizeof(long);
    int long_long_s = sizeof(long long);
    int float_s = sizeof(float);
    int double_s = sizeof(double);
    int long_double_s = sizeof(long double);
    int bool_s = sizeof(_Bool);
    int char_s = sizeof(char);

    printf("\nsizes of types in memory\n");
    printf("int: %i\n", int_s);
    printf("short: %i\n", short_s);
    printf("long: %i\n", long_s);
    printf("long long: %i\n", long_long_s);
    printf("float: %i\n", float_s);
    printf("double: %i\n", double_s);
    printf("long double: %i\n", long_double_s);
    printf("bool: %i\n", bool_s);
    printf("char: %i\n", char_s);


    return 0;
}
