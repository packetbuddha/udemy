#include <stdio.h>
#include <stdbool.h>

int str_length(char *str);
void str_cat(char *str1, char *str2, char *result);
bool str_cmp(char *str1, char *str2);

int main(void)
{
    char str[] = "the opposite of love is indifference";
    char str1[] = "blood in the streets in the town of new haven ";
    char str2[] = "blood stains the roofs and the palm trees of venice";
    char str3[] = "foo bar";
    char str4[] = "foo bar";
    char *str_cat_result = NULL;

    printf("\nstr is of length: %d\n", str_length(str));

    str_cat(str1, str2, str_cat_result);
    printf("str_cat: %s\n", str_cat_result);

    printf("str_cmp: \"%s\" with \"%s\" = %d\n", str1, str2, str_cmp(str1, str2));
    printf("str_cmp: \"%s\" with \"%s\" = %d\n", str3, str4, str_cmp(str3, str4));

    return 0;
}

int str_length(char *str)
{
    int i = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
       continue;
    }
    return i;
}

void str_cat(char *str1, char *str2, char *result)
    /* Concatenate two strings together
     *
     *  params:
     *   str1 : first string
     *   str2 : second string
     *   result : pointer to contain the resulting string
     */   
{
    int str_len1 = str_length(str1);
    int str_len2 = str_length(str2);
    char temp[str_len1 + str_len2 + 1];

    printf("str_len1: %d\n", str_len1); 
    printf("str_len2: %d\n", str_len2); 

    int i;
    for (i = 0; i < str_len1; i++)
    {
        temp[i] = str1[i];
    }

    int j;
    for (j = 0; j < str_len2; j++)
    {
        temp[i + j] = str2[j];
    }

    printf("temp len: %d\n", str_length(temp));
    // the above loop ends with a j++ so j here is j + 1 from above
    temp[i + j] = '\0';

    int x;
    for (x = 0; x < str_length(temp); x++)
    {
        printf("%c", temp[x]);
    }
    printf("\n");
}

bool str_cmp(char *str1, char *str2)
{
    bool is_equal = 1;
    
    int i;
    for (i = 0; i < str_length(str1); i++)
    {
        if (str1[i] != str2[i])
        {
            is_equal = 0;
            break;
        }
    }

    return is_equal;
}
