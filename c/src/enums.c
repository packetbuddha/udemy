#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    enum company {Google, Facebook, Xerox, Yahoo, Ebay, Microsoft};

    enum company xerox = Xerox;
    enum company google = Google;
    enum company ebay = Ebay;

    printf("Xerox: %i\n", xerox);
    printf("Google: %i\n", google);
    printf("Ebay: %i\n", ebay);
   
    /* 
    int i;
    for (i=1; i < argc; i++) {
        printf("arg: %s address: %p\n", argv[i], &argv[i] );
    }
    */
    
    return 0;

}
