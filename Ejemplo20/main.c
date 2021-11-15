#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utilityBoard.h"

void showParameters(int, const char *[]);
void initGame(struct board *);
int memoryGame(struct board *);
void reconfigGame(struct board *);
void showGameMenu();
void cleanBuffer();

int main(int argc, const char *argv[]) {
    // showParameters(argc, argv);
    FILE *pointFile;
    struct board boardMemory;
    boardMemory.dimensions = getBoardSize(argc, argv);
    initGame(&boardMemory);
    system("clear");
    printf("Bienvenido al juego de memoria de FP 02/2021\n\n\n");

    int opcion;

    do {
        showGameMenu();
        printf("\n: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                int puntaje = memoryGame(&boardMemory);
                char nombre[20];
                printf("Ingresa tu nombre: ");
                scanf("%s", nombre);
                pointFile = fopen("./puntos.txt","a");
                fprintf(pointFile,"%d,%s\n",puntaje,nombre);
                fclose(pointFile);
                // Guardar en un archivo
                break;
            case 2:
                system("clear");
                int puntajeTop = 0;
                char nombreJugador[20];
                pointFile = fopen("./puntos.txt","r");
                while(fscanf(pointFile,"%d,%s", &puntajeTop, nombreJugador)!= EOF) {
                    printf("%s\t%d\n",nombreJugador,puntajeTop);
                }
                fclose(pointFile);
                printf("\n\n");
                break;
            case 3:
                reconfigGame(&boardMemory);
                break;
            case 4:
                printf("Gracias por jugar a memory game\n");
                freeBoard(&boardMemory);
                break;
            default:
                printf("Por favor ingrese una opcion valida\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}

void reconfigGame(struct board *boardMemory) {
    int n = 1, m = 1;

    while ((n * m) % 2 != 0) {
        printf("Ingrese la cantidad de filas");
        scanf("%d", &n);
        printf("Ingrese la cantidad de columnas");
        scanf("%d", &m);
    }

    freeBoard(boardMemory);

    boardMemory->dimensions.n = n;
    boardMemory->dimensions.m = m;

    initGame(boardMemory);

    system("clear");
}

void showGameMenu() {
    printf("1.Jugar\n2.Ver Puntajes\n3.Configuración\n4.Salir");
}

int memoryGame(struct board *boardMemory) {
    char cont;
    int puntajes = 0;
    do {
        int xPos1, yPos1, xPos2, yPos2;
        printf("\nPuntos %d", puntajes);
        displayBoard(boardMemory);  // Mostramos el tablero

        printf("Seleccione la tarjeta que desea ver (#,#): ");
        scanf("%d,%d", &xPos1, &yPos1);
        xPos1--;
        yPos1--;  // [0,n-1] [0, m-1]
        system("clear");

        // Configuramos la posicion como visible
        boardMemory->content[xPos1][yPos1].status = SHOW;

        printf("\nPuntos %d", puntajes);
        displayBoard(boardMemory);

        printf("Seleccione la segunda tarjeta que desea ver (#,#): ");
        scanf("%d,%d", &xPos2, &yPos2);
        xPos2--;
        yPos2--;
        system("clear");

        boardMemory->content[xPos2][yPos2].status = SHOW;
        printf("\nPuntos %d", puntajes);
        displayBoard(boardMemory);

        scanf("%c", &cont);  // Limpia el buffer

        if (boardMemory->content[xPos2][yPos2].card ==
            boardMemory->content[xPos1][yPos1].card) {
            boardMemory->content[xPos2][yPos2].status = MATCH;
            boardMemory->content[xPos1][yPos1].status = MATCH;
            printf("\nHas encontrado una pareja\n");
            puntajes++;
        } else {
            printf("\nLa seleccion no forma una pareja\n");
            boardMemory->content[xPos2][yPos2].status = HIDDEN;
            boardMemory->content[xPos1][yPos1].status = HIDDEN;
        }

        printf("Presione cualquier tecla para continuar o N para salir: ");
        scanf("%c", &cont);  // Esperar para continuar
        system("clear");
        if (cont == 'N' || cont == 'n') {
            return puntajes;
        }
        cleanBuffer();
    } while (hasPairs(boardMemory));

    return puntajes;
}

void cleanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void initGame(struct board *boardMemory) {
    strcpy(boardMemory->borderColor, "\033[0;34m");
    strcpy(boardMemory->contentColor, "\033[1;31m");
    initBoard(boardMemory);
    fillBoard(boardMemory);
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