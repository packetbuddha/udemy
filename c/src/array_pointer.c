#include <stdio.h>

int main()
{
    char foo[] = "Hello World!";

    char *foo_p = foo;

    printf("%c\n", *foo_p);
    foo_p += 1;
    printf("%c\n", *foo_p);
}
