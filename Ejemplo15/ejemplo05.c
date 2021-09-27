#include <stdio.h>

void menu();

int main(int argc, char const *argv[]) {
    int opcion = 7;

    while (opcion != 4) {
        menu();
        printf("Selecione una opcion (1-4)?: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                printf("Ejecutando opcion 1\n");
                break;
            case 2:
                printf("Ejecutando opcion 2\n");
                break;
            case 3:
                printf("Ejecutando opcion 3\n");
                break;
            case 4:
                printf("Adios!\n");
                break;
            default:
                printf("Ingrese una opcion correcta\n");
                break;
        }
    }

    return 0;
}

void menu() {
    printf("1. Opcion\n");
    printf("2. Opcion\n");
    printf("3. Opcion\n");
    printf("4. Salir\n");
}
