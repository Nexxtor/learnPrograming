#include <stdio.h>

int main(int argc, char const *argv[]) {
    for(int letra = 0; letra < 256; letra++) {
        printf("%c \t %d\n",letra, letra);
    }
    
    char caracter = 'A';
    while ( caracter <='Z') {
        printf("%c \t %d\n",caracter, caracter);
        caracter++;
    }
    return 0;
}
