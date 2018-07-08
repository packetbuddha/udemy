#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess_count = 1;
    int guess_max = 5;
    int min = 1;
    int max = 20;
    int number = 0;
    int guess = 0;

    time_t t;

    srand((unsigned) time(&t));
    number = (rand() % max) + 1;

    printf("random number: %d\n", number);
    printf("I'm thinking of a number between %d and %d. Guess it in 5 tries.\n",min, max);

    while (1)
    {
        printf("guess %d: ", guess_count);
        scanf("%d", &guess);

        if (guess < number)
            printf("Your guess, %d, is too low\n", guess);
        else if (guess > number)
            printf("Your guess, %d, is too high\n", guess);
        else
        {
            printf("%d is correct!\n", guess);
            break;
        }
        
        guess_count++;
        if (guess_count > guess_max)
        {
            printf("You ran out of guesses!\n");
            break;
        }
    }

    return 0;
}

