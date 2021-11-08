#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utilityBoard.h"

void showParameters(int, const char *[]);
void initGame(struct board *);

int main(int argc, const char *argv[]) {
    showParameters(argc, argv);
    struct board boardMemory;
    boardMemory.dimensions = getBoardSize(argc, argv);
    initGame(&boardMemory);
    char cont = 'Y';
    do {
        int xPos1, yPos1, xPos2, yPos2;
        displayBoard(&boardMemory);
        printf("Seleccione la tarjeta que desea ver (#,#): ");
        scanf("%d,%d",&xPos1,&yPos1);
        xPos1--; yPos1--;
        boardMemory.content[xPos1][yPos1].status = SHOW;
        system("clear"); 
        displayBoard(&boardMemory);
        printf("Seleccione la segunda tarjeta que desea ver (#,#): ");
        scanf("%d,%d",&xPos2,&yPos2);
        xPos2--;yPos2--;
        boardMemory.content[xPos2][yPos2].status = SHOW;
        displayBoard(&boardMemory);
        // TODO: Hacer tiempo para que el usuario vea el contenido de la opcion 2
        if (boardMemory.content[xPos2][yPos2].card == boardMemory.content[xPos1][yPos1].card) {
             boardMemory.content[xPos2][yPos2].status = MATCH;
             boardMemory.content[xPos1][yPos1].status = MATCH;
             printf("Has encontrado una pareja");
        } else {
             printf("La seleccion no forma una pareja");
             boardMemory.content[xPos2][yPos2].status = HIDDEN;
             boardMemory.content[xPos1][yPos1].status = HIDDEN;
        } 
        scanf("%c",&cont);
        scanf("%c",&cont);
        system("clear");       
    } while(hasPairs(&boardMemory));
    freeBoard(&boardMemory);
    return 0;
}

void initGame(struct board *boardMemory) {
    strcpy(boardMemory->borderColor, "\033[0;34m");
    strcpy(boardMemory->contentColor, "\033[1;31m");
    initBoard(boardMemory);
    fillBoard(boardMemory);
    system("clear"); 
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