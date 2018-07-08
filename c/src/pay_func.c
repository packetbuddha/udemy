#include <stdio.h>

// globals
#define base_rate 12.00
#define base_hours 40.0
#define overtime_rate base_rate * 1.5
#define tax_bracket_300 .15
#define tax_bracket_450 .20
#define tax_bracket_max .25

float tax_max = 0.0;
float tax_450 = 0.0;
float tax_300 = 0.0;
float total_tax = 0.0;

void gross(float *bs, float *ot, float *gr)
{
    printf("%f", *bs);
    printf("%f", *ot);
    printf("%f", *gr);

}

void get_gross(hours_worked)
{
    float overtime_hours = 0;
    float base_pay = 0;
    float overtime_pay = 0;
    float gross_pay = 0;

    // Calculate base & overtime pay
    if (hours_worked >= base_hours)
    {
        base_pay = base_rate * base_hours;

        overtime_hours = hours_worked - base_hours;
        overtime_pay = overtime_rate * overtime_hours;

    } else
    {
        base_pay = base_rate * hours_worked;
    }

    // Calculate gross pay
    gross_pay = base_pay + overtime_pay;

}

float get_tax(float gross_pay)
{
    float tax_pay = 0;

    // Calculate Taxes
    tax_pay = gross_pay;
    if (tax_pay > 450) {
        tax_max = tax_bracket_max * (tax_pay - 450);
        total_tax += tax_max; 
        tax_pay = 450;
    }

    if (gross_pay > 300) {
        tax_450 = tax_bracket_450 * (tax_pay - 300);
        total_tax += tax_450;
        tax_pay = 300;
    }

    tax_300 = tax_bracket_300 * (tax_pay); 
    total_tax += tax_300;

    return total_tax;
}

int main()
{
    float base_pay = 0;;
    float overtime_pay = 0;;
    float gross_pay = 0;;
    float hours_worked = 0;
    float net_pay = 0;



    float bs = 0;
    float ot = 0;
    float gr = 0;

    gross(&bs, &ot, &gr);    



    printf("Enter number of hours worked: ");
    scanf("%f", &hours_worked);

    get_gross(hours_worked);   
    float total_tax = get_tax(gross_pay);
    net_pay = gross_pay - total_tax;

    printf("hours_worked: %f\n", hours_worked);
    printf("base_pay: %f\n", base_pay);
    printf("overtime_pay: %f\n", overtime_pay);
    printf("gross_pay: %f\n", gross_pay);
    printf("tax >450: %f\n", tax_max);
    printf("tax >300: %f\n", tax_450);
    printf("tax <300: %f\n", tax_300);
    printf("total_tax: %f\n", total_tax);
    printf("net_pay: %f\n", net_pay);

    return 0;
}
