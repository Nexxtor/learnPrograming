#include <stdio.h>

struct evaluacion {
    float nota, ponderacion;
};

int obtenerCantidadEvaluaciones();

int main(int argc, char const *argv[]) {
    int cant = obtenerCantidadEvaluaciones();
    struct evaluacion evaluaciones[cant];
  
    // Solicitar las datos de las evaluaciones
    for (int i = 0; i < cant ; i++) {
        printf("Evaluacion %d\n", i+1);
        printf("Nota: ");
        scanf("%f", &evaluaciones[i].nota);
        printf("Ponderacion: ");
        scanf("%f", &evaluaciones[i].ponderacion);
    }

    // Mostras tabla de calculo
    float notaFinal = 0;
    printf("#\tNota\tValor\tFinal\n");
    for (int i = 0; i < cant; i++) {
        struct evaluacion evaluacion = evaluaciones[i];
        float nota = evaluacion.nota * evaluacion.ponderacion;
        notaFinal += nota;
        printf("%d\t%2.2f\t%2.2f\t%2.2f\n", i+1, evaluacion.nota, evaluacion.ponderacion, nota);
    }
    printf("Total\t\t\t%2.2f\n",notaFinal);

    return 0;
}

int obtenerCantidadEvaluaciones(){
    int cantEvaluaciones = 0;
    printf("Ingrese la cantidad de evaluaciones: ");
    scanf("%d",&cantEvaluaciones);
    return cantEvaluaciones;
}