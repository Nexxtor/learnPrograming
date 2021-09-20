#include <stdio.h>

int esMultiplo(int, int);

/**
 * Determinar si un numero es par o impar
 * */
int main(int argc, char const *argv[]){
    int numero, multiplo;
    
    // Solicitamos datos
    printf("Ingrese un número: ");
    scanf("%d", &numero);
    printf("Ingrese segundo número: ");
    scanf("%d", &multiplo);

    // Mostramos la respuesta
    printf("El número %d ", numero);
    
    // Procesamos los datos
    if (esMultiplo(numero,multiplo)) {
        printf("es");
    } else {
        printf("no es ");
    }

    printf(" multiplo de %d\n", multiplo);

    return 0;
}

int esMultiplo(int numero, int multiplo) {
    return numero % multiplo == 0;
}