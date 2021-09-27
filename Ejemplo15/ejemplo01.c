/**
 * +
 * ++
 * +++
 * ++++
 * 
 * 
 * +++++
 * ++++++
 * +++++++ 
 ***/

#include <stdio.h>

int main(int argc, char const *argv[]) {
    int cantLineas = 10;
    
    for (int i = 0; i < cantLineas ; i++) { // Mostra linea x lina
       for (int j = 0; j <= i ; j++) {
            printf("*");
       }
        printf("\n");
    }
    return 0;
}
