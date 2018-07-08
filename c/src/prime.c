#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define start 2
#define end 100

bool is_prime(int num, int *primes, int prime_array_len)
{
    // calculate sqrt of num, rounded up to sqrt_round_upest int
    int sqrt_round_up = ceil(sqrt(num));

    bool prime = 1;  // current status

    int p;
    for (p = 0; p < prime_array_len - 1; p++)
    {
        // basic check to root out issues with 2 and 4 
        if (num > 2 && num % 2  == 0)
        prime = 0;;

        // skip zero value/unasigned elements 
        if (primes[p] != 0)
        {
            // check if the prime is less than the sqrt_round_up number
            if (primes[p] < sqrt_round_up)
            {
                //int prime_modulus = num % primes[p];
                if (num % primes[p] == 0)
                    prime = 0;
            }
        }
    }
    return prime;
}


int main()
{
    int primes[100] = {};
    int primes_array_len = sizeof(primes) / sizeof(int);
    int primes_array_index = 0; 

    // main loop testing each number
    int i;
    for (i = start; i <= end; i++)
    {
        if (is_prime(i, primes, primes_array_len) == 1)
        {
            // add number as next element in array
            primes[primes_array_index] = i;
            primes_array_index++;
        }
    }

    // results output
    printf("The prime number between %d and %d are:\n", start, end);
    int x;
    for (x = 0; x < primes_array_len -1; x++)
    {
        if (primes[x] !=0)
        {
            printf("%d,", primes[x]);
        }
    }
    printf("\n");

    return 0;
}

