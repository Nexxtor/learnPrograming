#include <stdio.h>

void sayHello();
void contarNumeros(int);
int factorial(int);
float dividir(int,int);
void sumarUno(int *);

int main(int argc, char *argv[]) {
    sayHello();
    int valor = factorial(3);
    int numerador = 5;
    int denominador = 10;
    float res =  dividir(numerador, denominador);
    
    int *punteroAValor = &valor;
    float *punteroARes = &res;

    printf("Valor --> %d %p\n", valor, punteroAValor);
    sumarUno(punteroAValor);
    printf("Valor --> %d %p\n", valor, punteroAValor);
    printf("Res --> %d %p\n", valor, punteroARes);

    scanf("%f", &res);


    return 0;
}

void sumarUno(int *ptrNumero) {
    *ptrNumero =  *ptrNumero + 1;
}

float dividir(int numerador ,int denominador) {
    numerador = 10;
    int res = numerador / denominador;
    return res;
}


int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

void sayHello() {
    char *nombre = "Nestor";
    printf("Hola %s", nombre);
    contarNumeros(10);
}

void contarNumeros(int numero) {
    for(int i = 0; i <numero; i ++) {
        printf("%d\n", i);
    }
}