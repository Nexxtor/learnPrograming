#include "utilityBoard.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * Modifica la cantidad de filas y columnas
 * que tendra el tablero de memoria.
 * Obteniendo los datos desde parametros de consola
 *
 **/
struct size getBoardSize(int argc, const char *argv[]) {
    struct size board = {DEFAULT_ROWS, DEFAULT_COLUMNS};  // Tamaño por defecto
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
void initBoard(struct board *board) {
    int nRows = board->dimensions.n;
    int nColumns = board->dimensions.m;
    //  printf("Llenando el tablero %d x%d", nRows, nColumns);

    // Reservando espacio de memoria para las filas
    board->content = (struct cell **)malloc(sizeof(struct cell *) * nRows);
    if (board->content != NULL) {
        for (int i = 0; i < nRows; i++) {
            (board->content)[i] =
                (struct cell *)malloc(sizeof(struct cell) * nColumns);
            if ((board->content)[i] == NULL) {
                printf("No se puede reservar memoria para el tablero");
                exit(1);
            }
            // Ubicando las opciones en el tablero
            for (int j = 0; j < nColumns; j++) {
                board->content[i][j].card = '\0';
                board->content[i][j].status = SHOW;
            }
        }
    } else {
        printf("No se puede reservar memoria para el tablero");
        exit(1);
    }
}

/** Llena el contenido del tablero con
 * opciones aletorias */
void fillBoard(struct board *board) {
    int nRows = board->dimensions.n;
    int nColumns = board->dimensions.m;
    // Generando posible opciones
    srand(time(NULL));
    int nOptions = (nColumns * nRows) / 2;
    char options[nOptions];
    for (int j = 0; j < nOptions; j++) {
        options[j] = 'A' + rand() % 25;
    }

    int i = 0;
    while (i < nOptions) {
        int xPos1, yPos1, xPos2, yPos2;
        do {
            xPos1 = rand() % nRows;
            yPos1 = rand() % nColumns;
        } while (board->content[xPos1][yPos1].card != '\0');
        do {
            xPos2 = rand() % nRows;
            yPos2 = rand() % nColumns;
        } while (board->content[xPos2][yPos2].card != '\0');

        if (xPos1 == xPos2 && yPos1 == yPos2) {
            continue;
        }
        // printf("Llenando posion %d %d y %d %d %c\n", xPos1,yPos1, xPos2,
        // yPos2, options[i]);
        board->content[xPos2][yPos2].card = options[i];
        board->content[xPos1][yPos1].card = options[i];
        i++;
    }
}

/** Libera el espacio de memoria utilizado por el table
 * despues de llamar a esta funcion no se podra utilizar el tablero*/
void freeBoard(struct board *board) {
    int cRows = board->dimensions.n;
    for (int i = 0; i < cRows; i++) {
        free((board->content)[i]);
    }
    free(board->content);
}

/**
 * Muesta el contendio en consola del tablero de dado
 **/
void displayBoard(struct board *board) {
    // Print top decoration table
    printf("\n\n%s┌", board->borderColor);
    for (int j = 0; j < board->dimensions.m - 1; j++) {
        printf("───┬");
    }
    printf("───┐\n");
    // Print n-1 content table
    for (int i = 0; i < board->dimensions.n - 1; i++) {
        // content
        for (int j = 0; j < board->dimensions.m; j++) {
            char *contentColor = board->contentColor;
            char *borderColor = board->borderColor;
            displayCell(borderColor, contentColor, board->content[i][j]);
        }
        // divider
        printf("│\n├");
        for (int j = 0; j < board->dimensions.m - 1; j++) {
            printf("───┼");
        }
        printf("───┤\n");
    }
    // last line content
    for (int j = 0; j < board->dimensions.m; j++) {
        char *contentColor = board->contentColor;
        char *borderColor = board->borderColor;
        displayCell(borderColor, contentColor,
                    board->content[board->dimensions.n - 1][j]);
    }
    // Bottom decorator
    printf("│\n└");
    for (int j = 0; j < board->dimensions.m - 1; j++) {
        printf("───┴");
    }
    printf("───┘\033[0m\n\n");
}

/**
 * Muestra el contenido de una celda del tablero de memoria
 * de acuerdo al estado en el que se encuentra */
void displayCell(char *borderColor, char *contentColor, struct cell cell) {
    char *hiddenSymbol = "♠";  // Se muestra cuan la carta esta oculta
    char content[2];
    content[0] = cell.card;
    content[1] = '\0';        // Contenido de la carte en formato cadena
    char *matchString = " ";  // Se muesta cuando se ha encontrado la pareja

    // Seleccionando que cadena de text mostar
    char *displayString;
    switch (cell.status) {
        case HIDDEN:
            displayString = hiddenSymbol;
            break;
        case SHOW:
            displayString = content;
            break;
        case MATCH:
            displayString = matchString;
            break;
    }
    // Mostrando celda
    printf("│%s %s %s", contentColor, displayString, borderColor);
}

/** Determina si hay posibilidad de hacer parejas */
bool hasPairs(struct board *board) {
    int nRow = board->dimensions.n;
    int nColumns = board->dimensions.m;

    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j < nColumns; j++) {
            if (board->content[i][j].status == HIDDEN) {
                return true;
            }
        }
    }
    return false;
}