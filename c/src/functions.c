#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int get_gcd(int x, int y);
int get_abs(int x);
float get_sqrt(float x);

int main()
{
    float n1 = -48.0;
    int n2 = 18;

    printf("gcd of %i and %i: %i\n", (int) n1, n2, get_gcd((int) n1, n2));
    printf("sqrt of %.2f is: %.2f\n", n1, get_sqrt(n1));

    return 0;
}

float get_sqrt(float x)
{
    int res;
    if (x < 0)
    {
        printf("get_sqrt(): got negative number\n");
        res = -1.0;
    } else
        res = sqrt(x);

    return res;
}

int get_abs(int x)
{
    /* returns the absolute value (positive) */
    return abs(x);
}

int get_gcd(int x, int y)
{
    x = get_abs(x);
    y = get_abs(y);
    int n1;
    int n2;
    int gcd = -1; // -1 indicates our first iteration
    int last_gcd = -1;  // -1 indicates our first iteration

    if (x >= y)
    {
        n1 = x;
        n2 = y;
    } else
    {
        n1 = y;
        n2 = x;
    }

    int i;
    // using a counter to avoid infinite loop
    for (i = 0; i < 100; i++)
    {
        // this is our first time thru
        if (last_gcd == -1)
            gcd = n1 % n2;
        else
            gcd = n2 % last_gcd;

        if (gcd == 0)
            break;

        last_gcd = gcd;
    }

    return last_gcd;
}

