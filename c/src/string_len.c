#include <stdio.h>

int string_len(const char *string_p);

int main()
{
    char string[] = "Welcome to the jungle!";
    const char *string_p = string;

    printf("length of string: %d\n", string_len(string_p));

    return 0;
}


int string_len(const char *string_p)
{
    const char *anchor = string_p;

    while(*string_p)
    {
        string_p++;
    }

    return (int) (string_p - anchor);
}

