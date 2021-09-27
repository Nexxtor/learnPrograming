#include <stdio.h>

int main(int argc, char const *argv[]) {
    // Pares forma 1
    for(int i = 0; i <= 100; i = i + 2) {
        printf("%d\n",i);
    }

    //impares forma 1
    for(int i = 1; i <= 100; i = i + 2) {
        printf("%d\n",i);
    }

    // Escribir en consala cuando un numero es impar o par
    for(int i = 0; i <= 100; i++) {
        printf("El numero %d es ", i);
        if ( i % 2 == 0) {
            printf("par");    
        } else {
            printf("impar");
        }
        printf("\n");
    }
    return 0;
}
