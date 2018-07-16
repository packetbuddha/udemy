#include <stdio.h>

int main()
{
    int foo = 10;
    char bar[10] = "Foo!";
    int *foo_p = &foo;

    printf("address of foo: %p\n", &foo);
    printf("address of bar: %p\n", &bar);
    printf("value of foo_p: %p\n", foo_p);
    printf("address of foo_p: %p\n", &foo_p);
    printf("dereference foo_p: %d\n", *foo_p);
    printf("sizeof foo_p: %lu\n", sizeof(foo_p));

    return 0;

}
