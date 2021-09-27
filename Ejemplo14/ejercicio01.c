/**
 * Solicita desde teclado la cantidad de numeros enteros que 
 * el usuario desea ingresar.
 * Para cada numero ingresado determinar si es multiplo de un segundo
 * numero dado por el usuario
 * 
 * Salida
 * Ingrese la cantidad de numeros: 2
 * 
 * Ingrese el numero: 4
 * Ingrese el numero con el que desea comprar si es multiplo: 2
 * 4 es multiplo de 2
 * 
 * Ingrese el numero: 3
 * Ingrese el numero con el que desea comprar si es multiplo: 2
 * 3 no es multiplo de 2
 * */

#include <stdio.h>

int main(int argc, char const *argv[]) {
    int cantNumeros, numero1, numero2;

    printf("Ingrese la cantidad de numeros que desea ingresar: ");
    scanf("%d", &cantNumeros);

    for (int i = 0 ; i < cantNumeros ; i++ ) {
        printf("Ingrese el primer numero: ");
        scanf("%d",&numero1);
        printf("Ingrese el segundo numero: ");
        scanf("%d", &numero2);

        if ( numero1 % numero2 == 0) {
            printf("El numero %d es multiplo de %d\n", numero1, numero2);
        } else {
            printf("El numero %d no es multiplo de %d\n", numero1, numero2);
        }

    } 
    return 0;
}
