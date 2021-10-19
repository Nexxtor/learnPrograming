#include <stdio.h>

void mostrarCadena(char cadena[]);
int largoCadena(char cadena[]);

int main(int argc, char const *argv[]) {
    char cadena[5] = "Hola"; 
    char cadena3[5] = {'H','O', 'L','A', '\0'} ;
    printf("%s", cadena);
    char cadena2[] = "Adios";
    mostrarCadena(cadena2);
    printf("El largo de la cadena es %d", largoCadena(cadena2));
    return 0;
}

void mostrarCadena(char cadena[]) {
   int i = 0;
    while (cadena[i] != '\0') {
        printf("%c", cadena[i]);
        i++;
    }
}

int largoCadena(char cadena[]) {
    int i = 0;
    while (cadena[i] != '\0') {
        i++;
    }
    return i;
}