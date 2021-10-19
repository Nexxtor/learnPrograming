#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    char saludo[] = "Hola como estas";
    char *nombre = "Nestor";
    char saludo2[25];
    
    printf("Largo de saludo %d \n", strlen(saludo));
    strcpy(saludo2, saludo);
    printf("%s\n",saludo2);

    strcat(saludo2, " ");
    strcat(saludo2, nombre);
    printf("%s", saludo2);

    char *nombre1 = "Nestor";
    char *nombre2 = "Santiago";
    char *nombre3 = "Juan";

    if( strcmp(nombre1, nombre2) > 0 && strcmp(nombre1, nombre3) > 0 ) {
        printf("%s\n",nombre1);
    }

    printf("\n%s comparando con %s %d\n" ,nombre1, nombre2, strcmp(nombre1, nombre2));
    printf("\n%s comparando con %s %d\n" ,nombre1, nombre3, strcmp(nombre1, nombre3));
    printf("\n%s comparando con %s %d\n" ,nombre2, nombre3, strcmp(nombre2, nombre3));
    
    printf("A comparado con B %d\n", strcmp("A", "B"));
    printf("a comparado con b %d\n", strcmp("a", "b"));
    printf("A comparado con AY %d\n", strcmp("A", "AY"));
    return 0;
}
