#include<stdio.h>

int main(int argc, char const *argv[]){
    int numeros[10]; // Arreglos, Arrays

    numeros[0] = 1;
    numeros[1] = 2;
    numeros[2] = 3;
    numeros[3] = 4;
    numeros[4] = 5;
    numeros[5] = 6;
    numeros[6] = 7;
    numeros[7] = 8;
    numeros[8] = 9;
    numeros[9] = 10; //esto es eficinete?

    printf("%d\n", numeros[0]);
    printf("%d\n", numeros[1]);
    printf("%d\n", numeros[2]);
    printf("%d\n", numeros[3]);
    printf("%d\n", numeros[4]);
    printf("%d\n", numeros[5]);
    printf("%d\n", numeros[6]);
    printf("%d\n", numeros[7]);
    printf("%d\n", numeros[8]);
    printf("%d\n", numeros[9]);

    // Llenar
    for (int i = 0 ; i < 11; i++) {
        numeros[i] = i + 10;
    }

    //Mostrar, Leer
    for (int i = 0; i < 11; i++) {
        printf("%d\n", numeros[i]);
    }


    return 0;
}
