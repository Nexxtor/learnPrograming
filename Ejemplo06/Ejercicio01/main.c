/**
 * Escriba un programa que dado desde teclado,
 * tres notas y tres ponderaciones.
 * Calcule la nota final.
 * 
 * Datos de entrada
 * 
 * Nota 1: 10
 * Ponderación: 0.5
 * 
 * Nota 2: 7
 * Ponderación: 0.2
 * 
 * Nota 3: 6
 * Ponderación: 0.3
 * 
 * Datos de salida
 * 
 * La nota final es 8.2
 * 
 * Productos esperados son:
 * 
 * 1. Diagrama de flujo con la herramienta draw.io.
 * 2. Código fuente escrito en C.
 * 
 **/

#include <stdio.h>

int main(int argc, char *argv[]){
    float nota1, nota2, nota3; // De 0 a 10
    float porcentaje1, porcentaje2, porcentaje3; // De 0 a 1
    float notaFinal;

    printf("Ingrese nota: ");
    scanf("%f", &nota1);
    printf("Ingrese ponderacion: ");
    scanf("%f", &porcentaje1);

    printf("Ingrese nota: ");
    scanf("%f", &nota2);
    printf("Ingrese ponderacion: ");
    scanf("%f", &porcentaje2);

    printf("Ingrese nota: ");
    scanf("%f", &nota3);
    printf("Ingrese ponderacion: ");
    scanf("%f", &porcentaje3);

    notaFinal = nota1 * porcentaje1 + nota2 * porcentaje2 + nota3 * porcentaje3;
    
    /*notaFinal = nota1 * porcentaje1;
    notaFinal = notaFinal + nota2 * porcentaje2;
    notaFinal += nota3 * porcentaje2;*/

    printf("La nota final es %.1f\n", notaFinal);

    return 0;
}
