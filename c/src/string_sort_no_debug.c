/*
TODO: optimize by passing back the largest ascii value, as well as the
      second largest.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const int NUMSTR = 8;
const int NUMCHAR = 10;
bool debug = 0;

char* get_next(char *strings_p[NUMSTR], int NUMSTR, int index);

int main(void)
{
 
    /* master string list (read-only) (make constant?) */
    char strings[NUMSTR][NUMCHAR] = {
        {"Juni"},
        {"Cassi"},
        {"Mischief"},
        {"Patches"},
        {"Lilah"},
        {"Lilly"},
        {"Larry"},
        {"Roxy"}
    };

    char *strings_p[NUMSTR]; // contains remaining strings to sort (read-write)
    char *sorted[NUMSTR]; // final sort
    int sorted_index = NUMSTR - 1; // track the last index written to
    int i, j;

    // initialize pointers
    for (i = 0; i < NUMSTR; i++)
        sorted[i] = NULL;

    // populate strings_p
    for (i = 0; i < NUMSTR; i++)
    {
        strings_p[i] = strings[i];
    }

    for (i = 0; i < NUMSTR; i++)
    {
        sorted[sorted_index] = get_next(strings_p, NUMSTR, 0);
        sorted_index--;
    }
        // Print final results
        for (j = 0; j < NUMSTR; j++)
        {
            printf("%s\n", sorted[j]);
        }

    return 0;
}

char* get_next(char *strings_p[NUMSTR], int NUMSTR, int index)
{
    int i, j;
    int ascii = 0; // temp var to store highest ascii value
    char *str_p = NULL; // temp var to store pointer to string owning value 
                        // in ascii var
    for (i = 0; i < NUMSTR; i++)
    {
        if (strings_p[i] != NULL)
        {
            if ((int) strings_p[i][index] > ascii)
            {
                ascii = strings_p[i][index]; // ascii value of CHAR
                str_p = strings_p[i];  // pointer to winning string
            }
            else if ((int) strings_p[i][index] == ascii)
            {
                char *sub_strings_p[2] = { str_p, strings_p[i] }; 

                str_p = get_next(sub_strings_p, 2, (index + 1));
            }
        }
    }

    // remove the winner from list of eligibles
    for (j = 0; j < NUMSTR; j++)
    {
        if (strings_p[j] == str_p)
            strings_p[j] = NULL;
    }

    return str_p;
}
