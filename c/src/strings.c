#include <stdio.h>
#include <string.h>

int main()
{

    // split string (tokenize) on delimeter '-'
    char bar[] = "hello, hello, hello - is there anybody in there - "
        "just nod if you can hear me";
    const char delimeter = '-';
    char *token_p = NULL;


    printf("original array conents:\n");

    // loop of a char array (string)
    int i;
    for (i = 0; i < strlen(bar); i++)
    {
          printf("%c", bar[i]);
    }
    printf("\n\n");

    token_p = strtok(bar, "-");

    // proving that the first token_p value equals the first address of bar
    printf("base address of bar: %p\n", bar);
    printf("first round token_p: %p\n", token_p);

    while (token_p != NULL)
    {
        // print each token and the associated starting address
        printf("%p : %s (%luB)\n", token_p, token_p, (strlen(token_p) + 1));

        token_p = strtok(NULL, "-");
    }
    printf("\n\n");

    // print the ascii values for each char, illustrating how strtoken has
    // updated the original string array - 0  == '\0'
    printf("ascii values of array after tokenization. Notice delimeters \
replaced with 0 == '\\0'\n");

    int x;
    for (x = 0; x < sizeof(bar); x++)
    {
        printf("%d ", bar[x]);
        if (bar[x] == '\0')
            printf("\n");
    }

    return 0;

}
