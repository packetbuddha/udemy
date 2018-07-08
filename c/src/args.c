#include <stdio.h>

int main(int argc, char *argv[])
{
    int num_args = argc;
    char *arg1 = argv[0];
    char *arg2 = argv[1];

    printf("number args: %i\n", num_args);
    printf("program name (arg1): %s\n", arg1);
    printf("command line arg (arg2): %s\n", arg2);

    return 0;

}
