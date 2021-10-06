#include <stdio.h>

int main(int argc, char const *argv[]) {
    int cantNotas = 0;
    printf("Ingrese la cantidad de notas de la materia: ");
    scanf("%d", &cantNotas);
    
    float notas[cantNotas];
    float ponderacion[cantNotas];

    // Guardar la nota y la ponderacion
    for(int i = 0; i < cantNotas; i++) {
        //Llenado el arreglo  nota
        printf("Ingrese la nota %d: ", i + 1);
        scanf("%f",&notas[i]);
        
        // Llenando el arreglo ponderaciones
        printf("Ingrese la ponderacion %d: ", i + 1);
        scanf("%f",&ponderacion[i]);
    }

    // Mostrar tablas de notas
    // Y calcular la nota final
    float notaFinal = 0;
    printf("  #\tNota\tPonderacion\n");
   
    for (int i = 0; i < cantNotas; i++) {
        printf("%d \t %f \t %f \n",i+1,notas[i], ponderacion[i]);
       
        notaFinal += notas[i]*ponderacion[i];
    }
    printf("Total:\t%3.2f\n",notaFinal);
    return 0;
}
