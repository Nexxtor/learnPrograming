/**
 * Calcule el precio total de un producto, dado desde teclado
 * el precio sin impuestos
 * @author Néstor Aldana
 * @date 01/09/2021
 **/
#include <stdio.h>

int main(int argc, char* argv[]) {
    float precio, precioTotal; // En dolares, camelCase, CamelCase

    printf("Ingrese el precio del producto ($): ");
    scanf("%f",&precio);

    // precioTotal = precio * 1.13;
    precioTotal = precio + precio * 0.13;

    printf("El precio total es $%.2f", precioTotal);

    printf("\n");
    return 0;
}