#include <stdio.h>

int main() {
    enum days { Mon, Tue, Wed, Thu, Fri, Sat, Sun };

    enum days today = Wed;

    switch (today) {
        case Mon:
            printf("Monday\n");
            break;
        case Tue:
            printf("Tuesday\n");
            break;
        case Wed:
            printf("Wednesday\n");
            break;
        case Thu:
            printf("Thu\n");
            break;
        case Fri:
            printf("Fri\n");
            break;
        case Sat:
            printf("Sat\n");
            break;
        case Sun:
            printf("Sun\n");
            break;
        default:
            printf("whatevs dude...\n");
            break;
    }

    return 0;
}
