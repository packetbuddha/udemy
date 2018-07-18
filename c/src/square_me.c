#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int * square(int *foo_p);

int main()
{
    int *foo_anchor_p = (int *) calloc(5, sizeof(int)); 
    int * foo_p = foo_anchor_p;
    *foo_p = 10;
    *(foo_p + 1) = 20;;
    
    printf("offset: %d, anchor: %p, current: %p\n", (int) 
            (foo_anchor_p - foo_p), foo_anchor_p, foo_p);

    foo_p++;
    printf("offset: %d, anchor: %p, current: %p\n", (int) 
            (foo_anchor_p - foo_p), foo_anchor_p, foo_p);
    foo_p--;
    printf("%d ^ 2 = %d\n", *foo_p, *(square(foo_p)));

    int i;
    int *ptr = foo_p;
    for (i = 0; i < 5; i++)
    {
       printf("%p : %d\n", ptr, *ptr); 
       ptr++;
    }

    free(foo_anchor_p);

    return 0;
}

int * square(int *foo_p)
{
    *foo_p = pow((float) *foo_p, 2.0);

    return foo_p;
}
