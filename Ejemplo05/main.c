/**
 * Calcule el precio total de un producto dado el precio sin impuestos
 * @author Néstor Aldana
 * @date 01/09/2021
 **/

// Instrucciones de inclucion de cabeceras

#include <stdio.h>

/* Declaracion de funciones */

/*La funcion principal de nuestra programa*/
int main(int argc, char* argv[]) { // Las llaves inidica el inicio de un bloque de codigo
    // Instruccion de declaracion <tipo de dato> nombre
    // Instruccion de asignacion nombre = <expresion>
    // Instruccion de declaracion y asignacion <tipo de dato> nombre = <expresion>;
    float precio = 100; // En dolares
    float precioTotal = precio * 1.13;
    // precioTotal = precio + precio * 0.13;
    printf("El precio total es $%.2f\n",precioTotal);
    return 0; // Le indicamos al sistema que terminamos con exito la ejecucion del algoritmo
}

// Aplicaciones CLI