#include <stdio.h>

int main(int argc, char const *argv[]) {
    int a = 2;

    printf("Operador de igualdad ? %d\n", a == 10);
    printf("Operador de mayor ? %d\n", a > 10);
    printf("Operador de mayor o igual ? %d\n", a >= 10);
    printf("Operador de menor ? %d\n", a < 10);
    printf("Operador de menor o igual ? %d\n", a <= 10);
    printf("Operador de diferencia ? %d\n", a != 10);


    printf("Operador de diferencia ? %d\n", !(a == 10));
    printf("Operador de mayor o igual ? %d\n", a > 10 || a ==10 );
    printf("Pregunta si a esta en un rango ]2 6] ? %d\n", a >= 2  && a < 6 );
    // Booleanos, Algebra de Bool
    return 0;
}
