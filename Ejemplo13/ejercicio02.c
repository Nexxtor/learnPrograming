/**
 * Dada las varaibles A,B,C de enteros, determine
 * el numero mayor y mueste en consola
 * el mensaje el "El número mayor es X"
 * donde X es A,B o C
 * 
 * A = 10 , B = 11 , C = 2;
 * 
 * El número mayor es B
 */
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int a = 1 ; b = 2; c = 3

    // Existen mas de  un forma de lograr el objetivo
    // Asegurarse de que la solucion escrita
    // se la mos optimo posible que siempre sea eficaz
    // Efeciente y eficaz
    
    if (a == b && b == c) {
        printf("Todos los numeros son iguales");
    } else {
        if ( a > b && a > c) {
            printf("A es el mayor");
        } else {
            if (b > c) {
                printf("B es el mayor");
            } else {
                printf ("C es el menor");
            }
        }
    }


    if ( a > b) {
        if (a > c) {
            printf("A es el mayor");
        } else {
            printf("C es el mayor");
        }
    } else {
        if ( b > c) {
            printf("B es el mayor");
        } else {
             printf("C es el mayor");
        }
    }

    if (a == b && b == c) {
         printf("Todos los numeros son iguales");
    }


    return 0;
}
