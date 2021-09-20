#include <stdio.h>
/**
 * Determinar si un numero es par o impar
 * */
int main(int argc, char const *argv[]){
    int numero;

    printf("Ingrese un número: ");
    scanf("%d", &numero);

    printf("El número %d es ", numero);
    
    // Logica positiva
    // El numero es par?
    if (numero % 2 == 0 ) {
        // Respuesta es verdadera
        printf("par\n");
    } else {
        // Respuesta es falsa
        printf("impar\n");
    }

    return 0;
}
