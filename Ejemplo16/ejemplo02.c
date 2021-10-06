#include <stdio.h>

char const *yes = "si";
char const *no = "no";

int main(int argc, char const *argv[]){
    char *cadena = "Hola";
    printf("%s\n", cadena);
    printf("%c\n",cadena[0]);
    printf("%c\n",cadena[1]);
    printf("%c\n",cadena[2]);
    printf("%c\n",cadena[3]);
    printf("%i\n",cadena[4]);
    char *mensage = "El numero %s es par";
    int numero = 10;
    if (numero % 2 == 0) {
        printf(mensage,yes);
    } else {
        printf(mensage,no);
    }

    return 0;
}
