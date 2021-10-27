#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constantes
#define DEFAULT_ROWS 5
#define DEFAULT_COLUMNS 5

struct size {
    int n;
    int m;
};

struct board {
    struct size dimensions;
    char *content[]; // Letra + \0
    // char **content
};

// Prototipos, declaración de funciones
void showParameters(int, const char *[]);
struct size getBoardSize(int, const char *[]);
void initBoard(struct board*);
void displayBoard(struct board*);

int main(int argc, const char *argv[]) {
    showParameters(argc, argv);
    struct board boardMemory;
    boardMemory.dimensions = getBoardSize(argc, argv);
    printf("Iniciando juego de memoria con tablero de dimensiones de %d x %d\n",
           boardMemory.dimensions.n, boardMemory.dimensions.m);
    initBoard(&boardMemory);
    displayBoard(&boardMemory);
    return 0;
}

// Definicion de funciones

/**
 * Muestra las cadenas de texto guardas en @param argv,
 * de acuerdo a la cantidad indicada en @param argc
 * Con el formato
 * #1   valor
 **/
void showParameters(int argc, const char *argv[]) {
    printf("Parametros\n");
    for (int i = 0; i < argc; i++) {
        printf("#%d\t%s\n", i, argv[i]);
    }
    printf("Fin\n");
}

/**
 * Modifica la cantidad de filas y columnas
 * que tendra el tablero de memoria.
 * Obteniendo los datos desde parametros de consola
 *
 **/
struct size getBoardSize(int argc, const char *argv[]) {
    struct size board = {DEFAULT_ROWS,
                           DEFAULT_COLUMNS};  // Tamaño por defecto
    if (argc >= 3) {
        int n = atoi(argv[1]);
        int m = atoi(argv[2]);
        // Validar los valores
        board.n = (n == 0) ? DEFAULT_ROWS : n;  // Operador ternario
        board.m = (m == 0) ? DEFAULT_COLUMNS : m;

        if ((board.n * board.m) % 2 != 0) {
            printf(
                "Seleccione una dimension de tablero que contenga una cantidad "
                "par de elementos\n");
            exit(1);
        }
    }
    return board;
}

/**
 * Llenar el contendio del tablero con parajes
 * posicionadas de forma aleatoria segun las dimensiones 
 * del tablero
 **/
void initBoard(struct board* board) {
    int cRows = board->dimensions.n;
    int cColumns = board->dimensions.m;
    printf("Llenando el tablero %d x%d", cRows, cColumns);
    // Tarea 1: Investigar que es la  Memoria dinamica -> malloc
}

/**
 * Muesta el contendio en consola del tablero de dado
 **/
void displayBoard(struct board *board) {
    printf("\n\n");
    for (int i = 0 ; i < board->dimensions.n ; i ++) {
        for( int j = 0 ; j < board->dimensions.m; j ++) {
            printf("| %c ",'A');
        }
        printf("|\n");
    }
    printf("\n\n");
}