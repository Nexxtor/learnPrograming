#include <stdio.h>
#include <stdbool.h>

bool esMutiplo(int, int);
void fizzBuzz(int);

int main(int argc, char const *argv[]) {
    int numero;
    printf("Ingrese un numero entero: ");
    scanf("%d",&numero);
    fizzBuzz(numero);
    printf("\n");
    return 0;
}

/**
 * Determina si numero es multiplo de numero2
 * @param numero entero (dividendo)
 * @param numero2 entero (divisor)
 * @return true si es multiplo y false si no es multiplo
 * */
bool esMutiplo(int numero,int numero2) {
    return numero % numero2 == 0;
}


/**
 * Muesta Fizz en consola cuando el numero es multiplo de 3 
 * Muesta Buzz en consola cuando el numero es multiplo de 5
 * Muesta FizzBuzz en consola cuando el numero es multiplo de 3 y 5
 * Muesta el numero en consola cuando este no es multiplo de 3 o 5
 * @param numero entero
 * */
void fizzBuzz(int numero) {
    bool esMutiplo3 = esMutiplo(numero,3);
    bool esMutiplo5 = esMutiplo(numero,5);

    if (esMutiplo3 || esMutiplo5) {
        if (esMutiplo3) {
            printf("Fizz");
        }
        
        if (esMutiplo5) {
            printf("Buzz");    
        }

    } else {
        printf("%d",numero);
    }
}

