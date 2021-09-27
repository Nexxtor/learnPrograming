#include <stdio.h>

int main(int argc, char const *argv[]) {
    int cantNotas = 0;
    printf("Ingrese la cantidad de notas de la materia: ");
    scanf("%d", &cantNotas);
    float notaFinal = 0;
    for(int i = 0; i < cantNotas; i++) {
        float nota, ponderacion;
        printf("Ingrese la %d° nota: ", i+1);
        scanf("%f", &nota);
        printf("Ingrese el porcentaje para la nota %d°: ", i+1);
        scanf("%f", &ponderacion);
        //notaFinal = notaFinal + nota * ponderacion;
        notaFinal += nota * ponderacion;
    }
    
    printf("Su nota final es %.2f\n", notaFinal);
    return 0;
}
