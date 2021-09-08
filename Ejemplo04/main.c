/**
 * Tipo de dato en C
 * @author Néstor Aldana <naldana@uca.edu.sv>
 * @date 30/08/2021
 **/
#include <stdio.h>

int main(void) {
    char caracter = 'A';
    short corto = 1;
    int entero = 0;
    float decimal = 5.5;
    double decimalG = 5.4;
    long grande = 30;
    long double decimalGG = 10;

    printf("Caracter %c\n", caracter);
    printf("Entero %d\n", entero);
    printSizes();
 
    return 0;
}