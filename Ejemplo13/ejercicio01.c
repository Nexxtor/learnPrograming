/***
 * Solicitar un número entero desde teclado
 * y mostrar la palabra Fizz si el numero es multiplo de 3
 * la palabra Buzz si es mutiplo de 5
 * la palabra FizzBuzz si el numero es multiplo de ambos
 * y el numero si no cumple con las anteriores
 * Usar funciones
 * Usar if
 * Escribir la menor cantidad posible de printfs
 * 
 * */

#include <stdio.h>
#include <stdbool.h>

bool esMutiplo(int, int);

int main(int argc, char const *argv[]) {
    int numero;

    printf("Ingrese un número entero: ");
    scanf("%d",&numero);
   /* if ( esMutiplo(numero,3) && esMutiplo(numero,5)) {
        printf("FizzBuzz\n");
    } else {
        if (esMutiplo(numero,3)) {
            printf("Fizz\n");
        } else {
            if (esMutiplo(numero,5)) {
                printf("Fuzz\n");
            } else {
                printf("%d\n", numero);
            }
        }
    }*/
    bool esMutiplo3 = esMutiplo(numero,3);
    bool esMutiplo5 = esMutiplo(numero,5);

    if (esMutiplo3 || esMutiplo5) {
        if (esMutiplo3) {
            printf("Fizz");
        }
        
        if (esMutiplo5) {
            printf("Buzz");    
        }

    } else {
        printf("%d",numero);
    }

    printf("\n");

    return 0;
}


bool esMutiplo(int numero,int numero2) {
    return numero % numero2 == 0;
}
