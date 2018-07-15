#include <stdio.h> // printf, NULL
#include <stdlib.h> // strtod()

int main(void)
{
    const char data[] = "364.24 29.53 3.14159";
    char *data_p = NULL; // to hold last pointer location

    double result[3]; // array to store results

    printf("starting values\n");
    printf("data: %p, data_p: %p\n", data, data_p);

    result[0] = strtod(data, &data_p); // why pass the address of the pointer itself?
    printf("after first strtod()\n");
    printf("data: %p, data_p: %p, data[0]: %f\n", data, data_p, result[0]);
            
    result[1] = strtod(data_p, &data_p);
    printf("after second strtod()\n");
    printf("data: %p, data_p: %p, data[1]: %f\n", data, data_p, result[1]);
    
    result[2] = strtod(data_p, NULL);
    printf("after third strtod()\n");
    printf("data: %p, data_p: %p, data[2]: %f\n", data, data_p, result[2]);

    return 0;
}


