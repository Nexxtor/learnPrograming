#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    int n = 10;
    printf("%d\n", n);

    int *ptrN = &n;

    printf("%p\n", ptrN);
    *ptrN = 1;
    printf("%d\n", n);

    int arreglo[5] = {1, 2, 3, 4, 5};
    printf("%p\n", arreglo);

    printf("%d\n", *arreglo);        // 1
    printf("%d\n", arreglo[1]);      // 2
    printf("%d\n", *(arreglo + 1));  // 2

    // Memoria dinamica
    int *ptrNumero = NULL;
    // Solicitar memoria para guardar un entero
    // Almacenado la direccion de la memoria dado
    ptrNumero = (int *)malloc(sizeof(int));
    if (ptrNumero != NULL) {
        printf("%p %d\n", ptrNumero, *ptrNumero);
        *ptrNumero = 10;
        printf("%p %d\n", ptrNumero, *ptrNumero);
        free(ptrNumero);
    } else {
        printf("No se pudo reservar memoria\n");
    }

    int *ptrArreglo = NULL;

    ptrArreglo = (int *)malloc(sizeof(int) * 5);

    if (ptrArreglo != NULL) {
        *ptrArreglo = 1;
        *(ptrArreglo + 1) = 2;
        *(ptrArreglo + 2) = 3;
        *(ptrArreglo + 3) = 4;
        *(ptrArreglo + 4) = 5;
        // printf("%p %d",ptrArreglo, *(ptrArreglo+1));
        printf("%p %d\n", ptrArreglo, ptrArreglo[0]);
        printf("%p %d\n", &ptrArreglo[1], ptrArreglo[1]);
        printf("%p %d\n", &ptrArreglo[2], ptrArreglo[2]);
        printf("%p %d\n", &ptrArreglo[3], ptrArreglo[3]);
        printf("%p %d\n", &ptrArreglo[4], ptrArreglo[4]);
        free(ptrArreglo);
    } else {
        printf("No se pudo reservar memoria\n");
    }

    int **matrix = NULL;

    matrix = (int **) malloc(sizeof(int *) * 2);

    if (matrix != NULL) {
        *matrix = malloc(sizeof(int)*5);
        *(matrix +1) = malloc(sizeof(int)*5);
        if ( *matrix != NULL && *(matrix+1)!= NULL ) {
            for (int i = 0; i <2; i++) {
                for (int j = 0; j < 5; j++) {
                    matrix[i][j] = i * j;
                }
            }

            for (int i = 0; i <2; i++) {
                for (int j = 0; j < 5; j++) {
                    printf("(%d,%d) %p  --> %d\n",i,j,&matrix[i][j], matrix[i][j]);
                }
            }
        }
        free(*(matrix+1));
        free(*matrix);
        free(matrix);
    }

    printf("\n");
    return 0;
}
