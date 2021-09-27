#include <stdio.h>

enum operaciones { SUMAR = 1, RESTAR, DIVIDIR, MULTIPLICAR };

void menu();

int main(int argc, char const *argv[]) {
    enum operaciones operacion;
    float operador1, operador2;

    do {
        menu();

        printf("Seleccione una operación 1-4: ");
        scanf("%d", &operacion);

        if (operacion == 5) {
            break;
        }

        printf("Ingrese el primer operador: ");
        scanf("%f", &operador1);
        printf("Ingrese el segundo operador: ");
        scanf("%f", &operador2);

        switch (operacion) {
            case SUMAR:
                printf("%f + %f = %f\n", operador1, operador2, operador1 + operador2);
                break;
            case RESTAR:
                printf("%f - %f = %f\n", operador1, operador2, operador1 - operador2);
                break;
            case DIVIDIR:
                printf("%f / %f = %f\n", operador1, operador2, operador1 / operador2);
                break;
            case MULTIPLICAR:
                printf("%f * %f = %f\n", operador1, operador2, operador1 * operador2);
                break;
        }
    } while (operacion != 5);

    return 0;
}

void menu() {
    printf("\n1.Sumar\n2.Restar\n3.Mutilplicar\n4.Dividir\n5.Salir\n");
}
