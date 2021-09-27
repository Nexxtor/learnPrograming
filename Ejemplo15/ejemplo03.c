#include <stdio.h>

int main(int argc, char const *argv[]) {
    int numero;

    printf("Ingrese un numero entre 2 y 8: ");
    scanf("%d", &numero);

    // while (condicion expresion boolean) {
    // codigo que se repite mientras la condicon sea verdadera
    // Las variables usadas en la condicion siempre deben de cambiar
    // dentro del while
    //}
    //
    while (numero < 2 || numero > 8) {
        printf("El numero esta fuera de rango\n");
        printf("Ingrese un numero entre 2 y 8: ");
        scanf("%d", &numero);
    }

    return 0;
}
