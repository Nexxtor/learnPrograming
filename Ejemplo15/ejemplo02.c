#include <stdio.h>

int main(int argc, char const *argv[]) {
    int numero;

    printf("Ingrese un numero entre 2 y 8: ");
    scanf("%d", &numero);

    if (numero >=2 && numero <= 8) {
        printf("Ingreso un numero correcto\n");
    } else{
        printf("Ingreso un numero fuera de rango\n");
    }
    return 0;
}
