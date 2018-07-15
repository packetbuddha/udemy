#include <stdio.h>

int main() {
    int minutes;
    int mins_in_day = 60 * 24; // 1440
    int mins_in_year = mins_in_day * 365.25; // 525960 
    double days;
    double years; 

    // printf("minutes address: %p\n", &minutes);
   
    printf("enter number of minutes: \n"); 
    scanf("%d", &minutes);
    
    days = (double) minutes / mins_in_day;
    years =  (double) minutes / mins_in_year;

    printf("%d minutes is equivalent to:\n", minutes);
    printf("  %f days\n  %f years\n", days, years);


    return 0;
}
