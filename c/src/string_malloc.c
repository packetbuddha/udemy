#include <stdio.h>
#include <stdlib.h> // malloc, calloc

const int MAX = 100;

int main(void)
{
    // allocate memory block of MAX elements + 1 for NULL
    char *string_anchor_p = (char *) calloc((MAX + 1), sizeof(char));
    if (string_anchor_p == NULL)
        exit(-1);

    // input
    printf("Enter a sting up to %d characters in length\n", MAX);
    fgets(string_anchor_p, (MAX + 1), stdin); 
   
    // output 
    printf("You entered:\n");
    printf("%s\n", string_anchor_p);

    // cleanup
    free(string_anchor_p);
    string_anchor_p = NULL;

}
