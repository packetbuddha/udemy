#include <stdio.h>

int main()
{
    int foo = 10;
    int *foo_p = &foo;

    printf("address of foo: %p\n", &foo);
    printf("value of foo_p: %p\n", foo_p);
    printf("address of foo_p: %p\n", &foo_p);
    printf("dereference foo_p: %d\n", *foo_p);
    printf("sizeof foo_p: %lu\n", sizeof(foo_p));

    int bar = 42;
    const int *bar_p = &bar;

    printf("const on pointer indirect value (deref): const int *bar_p = &bar;\n");
    printf("bar_p -> bar: %d\n", bar);
    bar_p = &foo;
    printf("update bar_p -> foo: %d\n", foo);
    foo = 69;
    printf("update foo directly: %d\n", foo);
    printf("attempt to update *bar_p = 42; results in:\n");
    printf("pointers.c:23:12: error: read-only variable is not assignable\n");

    int *const foobar_p = &foo;
    printf("const on pointer value (addy of var): int *const foobar_p = "
            "&foo : %d\n", *foobar_p); 
    printf("attempt to update foobar_p = &bar; results in:\n");
    printf("pointers.c:28:14: error: read-only variable is not assignable\n");
    printf("\n");
    printf("also possible to combine both: const int *const foobar_p = &foo;\n");

    return 0;

}
