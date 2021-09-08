#include <stdio.h>

// Declarar
float calcularIVA(float valor);

int main(int argc, char *argv[]) {
    float precio = 10;
    float precioTotal = precio + calcularIVA(precio);

    float precio2 = 20;
    float ivaPrecio2 = calcularIVA(precio2);
    printf("El precion total es %f\n", precioTotal);
    return 0;
}

// Definición
// Paramentros son los datos de entrada de la funcion
// Retorno son los datos de salida de un funcion
float calcularIVA(float valor) {
    float resultado = valor * 0.13;
    return resultado;
}
