#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    double width;
    double height;
    double perimeter;
    double area;

    // atof converts string to float of type double
    width = atof(argv[1]);
    height = atof(argv[2]);

    perimeter = (width  + height) * 2;
    area = width * height;;

    printf("perimeter: %f\n", perimeter);
    printf("area: %f\n", area);

    return 0;

}
