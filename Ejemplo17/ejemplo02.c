#include <stdio.h>

#define CANT_ALUMNOS 3
#define CANT_NOTAS 3

int main(int argc, char const *argv[]) {
    //         CANT_FILAS   CANT_COLUMNAS
    float notas[CANT_ALUMNOS][CANT_NOTAS];

    // A mano
    // Llenando primera fila
    notas[0][0] = 5;
    notas[0][1] = 7;
    notas[0][2] = 6;

    // Llenando segunda fila
    notas[1][0] = 8;
    notas[1][1] = 9.5;
    notas[1][2] = 1;

    // Llenando tercera fila
    notas[2][0] = 9;
    notas[2][1] = 1;
    notas[2][2] = 5.9;

    printf("01\t02\t03\tFinal\n");
    for (int i = 0; i < CANT_ALUMNOS; i++) {
        float notaFinal = 0;
        for (int j = 0; j < CANT_NOTAS; j++) {
            printf("%2.2f\t", notas[i][j]);
            notaFinal += notas[i][j];
        }
        printf("%2.2f", notaFinal / 3);
        printf("\n");
    }

    return 0;
}
