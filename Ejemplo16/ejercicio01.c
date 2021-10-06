/**
 Cree un arreglo de capacidad para 10 enteros y guarde los primero 10 números
 pares en el arreglo. Luego muestre los 10 números pares almacenados desde el
 arreglo*/

 // 2,4,6,8,10,12,14,16,18,20

#include <stdio.h>

int main(int argc, char const *argv[]) {
    int pares[10];

    // Solucion 1
    for (int i = 0; i <10; i++) {
        pares[i] = 2 * (i+1);
    }

    // Solucion 2
    int j = 0, numero = 2;
    while (j < 10) {
        pares[j] = numero;
        j++;
        numero += 2;
    }

    for (int i = 0; i < 10 ; i++) {
        printf("%d\n",pares[i]);
    }

    return 0;
}
