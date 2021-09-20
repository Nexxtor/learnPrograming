#include <stdio.h>
/**
 * Determinar si un numero es par o impar
 * */
int main(int argc, char const *argv[]){
    int numero;

    printf("Ingrese un número: ");
    scanf("%d", &numero);

    printf("El número %d es ", numero);
    
    // Logica negativa
    // El numero no es par
    if (numero % 2 != 0 ) {
        // Respuesta es verdadera
        printf("impar\n");
    } else {
        // Respuesta es falsa
        printf("par\n");
    }

    return 0;
}