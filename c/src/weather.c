#include <stdio.h>

int main()
{
    int years = 5;
    int months = 12;
    int y = 0;
    int m = 0;
    int x = 0;

    float rainfall_data[5][13] = {
        {2013, 1.5, 3.6, 2.6, 2.4, 1.5, 2.3, 3.6, 4.3, 1.2, 2.1, 3.2, 1.9},
        {2014, 1.3, 3.3, 2.3, 2.6, 1.3, 2.5, 3.2, 4.2, 1.3, 2.0, 2.3, 1.6},
        {2015, 1.1, 3.8, 2.6, 2.1, 1.9, 2.2, 3.2, 4.1, 1.3, 2.4, 2.7, 1.2},
        {2016, 1.4, 3.2, 2.2, 2.1, 1.6, 2.7, 3.1, 4.1, 1.1, 2.1, 3.1, 1.0},
        {2017, 1.2, 3.1, 1.4, 2.0, 1.7, 2.1, 3.7, 4.0, 1.2, 2.3, 3.3, 1.8},
    };
    // { {year, sum, avg}, {...} }
    float yearly_averages[5][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    }; 
    
    // { {month, sum, avg}, {...} }
    float monthly_averages[13][3] = {
        {0, 0, 0}, 
        {0, 0, 0}, 
        {0, 0, 0}, 
        {0, 0, 0}, 
        {0, 0, 0}, 
        {0, 0, 0}, 
        {0, 0, 0}, 
        {0, 0, 0}, 
        {0, 0, 0}, 
        {0, 0, 0}, 
        {0, 0, 0}, 
        {0, 0, 0}, 
        {0, 0, 0}
    };

    char month_index[13][5] = {"None", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    
    /* Loop over Years */

    // display the raw data and populate yearly_averages array
    for (y = 0; y < years; y++)
    {
        float year_sum = 0;
        for (m = 0; m < months + 1; m++)
        {
            if (m == 0)
                printf("%d ", (int) rainfall_data[y][m]);
            else
            {
                printf("%.2f ", rainfall_data[y][m]);
                year_sum += rainfall_data[y][m]; // summ for avg
                printf("year_sum: %f\n", year_sum);
            }
        }

        yearly_averages[y][0] = rainfall_data[y][0]; // add year
        yearly_averages[y][1] = year_sum;  // yearly sum 
        yearly_averages[y][2] = year_sum / months; // year avg

        printf("\n");
    }

    printf("year | sum | avg\n");
    for (x = 0; x < years; x++)
    {
        printf("%.2f %.2f %.2f \n", yearly_averages[x][0],
                yearly_averages[x][1], yearly_averages[x][2]);
    }

    /* Loop over Months */
    int m1;
    int y1;
    for (m1 = 1; m1 < months + 1; m1++)
    {
        float monthly_sum = 0; // reset sum
        for (y1 = 0; y1 < years; y1++)
        {
            monthly_sum += rainfall_data[y1][m1];
        }
        monthly_averages[m1][0] = m1;
        //monthly_averages[m1][1] = monthly_sum;
        monthly_averages[m1][2] = monthly_sum / years;
    }


    printf("month | sum | avg\n");
    int m2;
    for (m2 = 1; m2 < months + 1; m2++)
    {
        //printf("%s %.2f %.2f \n", month_index[(int) monthly_averages[m][0]],
        printf("%i %.2f %.2f \n", (int) monthly_averages[m2][0],
                yearly_averages[m2][1], yearly_averages[m2][2]);
    }



    return 0;
}
