#include <math.h>
#include <stdio.h>

struct point {
    int x;
    int y;
    char tag;
};

struct point fillPointFromKeyBoard();
float getDisctanceBetween(struct point, struct point);

int main(int argc, char const *argv[]) {
    // int x1, y1, x2 ,y2 ,x3,y3;
    struct point p1, p2, p3;

    // Solicita desde teclado
    p1 = fillPointFromKeyBoard();
    p2 = fillPointFromKeyBoard();
    p3 = fillPointFromKeyBoard();

    // Calcuala la distancia entre el p1 y p2
    float distanceP1toP2 = getDisctanceBetween(p1, p2);
    // Calcula la distancia entre p1 y p3
    float distanceP1toP3 = getDisctanceBetween(p1, p3);
    // Calcula la distancia entre p3 y p2
    float distanceP2toP3 = getDisctanceBetween(p3, p2);
    // Suman las distancias
    float perimeter = distanceP1toP2 + distanceP1toP3 + distanceP2toP3;
    // Mostra el resultado
    printf("The perimeter is %.2f\n", perimeter);
    return 0;
}

struct point fillPointFromKeyBoard() {
    struct point newPoint = {0, 0};
    printf("Ingrese los corrdenadas\n");
    printf("Componente x = ");
    scanf("%d", &newPoint.x);
    printf("Componente y = ");
    scanf("%d", &newPoint.y);
    return newPoint;
}

float getDisctanceBetween(struct point p1, struct point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}