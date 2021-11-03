#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constantes
#define DEFAULT_ROWS 5
#define DEFAULT_COLUMNS 5
#define COLOR_STRING_SIZE 12

enum showStatus { HIDDEN, SHOW, MATCH };

struct size {
    int n;
    int m;
};

struct cell {
    char card;               // 'A' 'B' 'C'
    enum showStatus status;  // Si esta baca arribo o boca abajo
};

struct board {
    struct size dimensions;
    char borderColor[COLOR_STRING_SIZE];
    char contentColor[COLOR_STRING_SIZE];
    struct cell **content;
};

void showParameters(int, const char *[]);
struct size getBoardSize(int, const char *[]);
void initBoard(struct board *);
void freeBoard(struct board *);
void displayBoard(struct board *);
void displayCell(char *, char *, struct cell);

int main(int argc, const char *argv[]) {
    showParameters(argc, argv);
    struct board boardMemory;
    boardMemory.dimensions = getBoardSize(argc, argv);
    strcpy(boardMemory.borderColor, "\033[0;34m");
    strcpy(boardMemory.contentColor, "\033[1;31m");
    printf("Iniciando juego de memoria con tablero de dimensiones de %d x %d\n",
           boardMemory.dimensions.n, boardMemory.dimensions.m);
    initBoard(&boardMemory);
    displayBoard(&boardMemory);
    freeBoard(&boardMemory);
    return 0;
}


/**
 * Muestra las cadenas de texto guardas en @param argv,
 * de acuerdo a la cantidad indicada en @param argc
 * Con el formato
 * #1   valor
 **/
void showParameters(int argc, const char *argv[]) {
    printf("|============================================|\n");
    printf("|%17sArgumentos%17s|\n", "", "");
    printf("|============================================|\n");
    printf("|  #                      Valor              |\n");
    for (int i = 0; i < argc; i++) {
        printf("|[%.2d] [%*.*s]|\n", i, 37, 37, argv[i]);
    }

    printf("|============================================|\n\n");
}

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
    int cRows = board->dimensions.n;
    int cColumns = board->dimensions.m;
    printf("Llenando el tablero %d x%d", cRows, cColumns);

    // Reservando espacio de memoria para las filas
    board->content = (struct cell **)malloc(sizeof(struct cell *) * cRows);
    if (board->content != NULL) {
        for (int i = 0; i < cRows; i++) {
            (board->content)[i] =
                (struct cell *)malloc(sizeof(struct cell) * cColumns);
            if ((board->content)[i] == NULL) {
                printf("No se puede reservar memoria para el tablero");
                exit(1);
            }
            for (int j = 0; j < cColumns; j++) {
                // TODO: Generar parejas y posicinarlas de forma aletorias en la matriz
                board->content[i][j].card = 'A';
                board->content[i][j].status = MATCH;
            }
        }
    } else {
        printf("No se puede reservar memoria para el tablero");
        exit(1);
    }
}

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
    char *hiddenSymbol = "♠"; // Se muestra cuan la carta esta oculta
    char content[2];
    content[0] = cell.card; content[1] = '\0';  // Contenido de la carte en formato cadena
    char *matchString = " "; // Se muesta cuando se ha encontrado la pareja

    // Seleccionando que cadena de text mostar
    char *displayString; 
    switch (cell.status){
        case HIDDEN:
            displayString = hiddenSymbol;
            break;
        case SHOW:
            displayString = content;
            break;
        case MATCH:
            displayString =  matchString;
            break;
    }
    // Mostrando celda
    printf("│%s %s %s", contentColor, displayString ,borderColor);
}