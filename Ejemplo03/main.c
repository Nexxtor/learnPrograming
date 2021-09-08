/**
 * Declaracion e inicializacion de variables en C
 * @author Néstor Aldana <naldana@uca.edu.sv>
 * @date 30/08/2021
 **/
#include <stdio.h>

int main(void) {
    int numero;  // Declaracion
    int numero2;
    int numero3, numero4, numero5; // Declara tres variables de tipo entero

    // Inicializar, consisten asignar un valor inicial a la variable
    numero = 1;
    numero2 = 2;
    /* En la siguiente instrucción el valor 3 se esta guardado en numero5 y
    el valor de numero5 en numero4, el valor de numero4 en numero3, en otras palabras
    guardamos el numero 3 en numero3 nuemero4 y numero5 en una sola instucción*/
    numero3 = numero4 = numero5 = 3;

    /* Es posible declarar y inicializar una variable en una sola instucción
    el la instruccion siguiente se esta declarando la variables combinado,
    combinado1, combinado3 y combinado4, pero solo se estan inicializando
    combinado, combinado1 y combinado4 */
    int combinado = 5, combinado1 = 1, combinado3, combinado4 = 0;

    /* IMPORTANTE: Notar que la coma sirve para indicar que la declaracion variables continua
    cuando se usa el la instruciones de la linea 11 y 25. Pero luego veremos que tiene otros usos.
    A los carácteres de este tipo se les conoce como delimitadores */
    return 0;
}