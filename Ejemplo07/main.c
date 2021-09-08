#include <stdio.h>

// Declarar
void sayHello();

int main(int argc, char *argv[]) {
    sayHello(); // Ejecutar o invocar una funcion
    sayHello(); // Se puede ejecutar cuantas veces sea necesario y donde sea necesaria
    return 0;
}

// Definir una funcion
void sayHello() {
    printf("Hello World!\n");
}