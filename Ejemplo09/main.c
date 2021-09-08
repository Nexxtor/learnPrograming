/** Convertir bitcoins a dolares */
#include <stdio.h>

#define BITCOIN_TO_DOLAR 46578.80
#define DOLAR_TO_BITCOIN 0.000021

float bitcoinsToDolar(float bitcoins);
float dolarToBitcoins(float dolares);

int main(int argc,char* argv[] ) {
    float bitcoins = 0;

    printf("Ingrese la cantidad de bitcoins: ");
    scanf("%f", &bitcoins);

    float dolares = bitcoinsToDolar(bitcoins);
   
    printf("La cantidad en dolares es %.2f\n", dolares);

    printf("Ingrese la cantidad de dolares: ");
    scanf("%f", &dolares);   
    printf("La cantidad en bitcoins es %.2f\n", dolarToBitcoins(dolares));
}

float bitcoinsToDolar(float bitcoins) {
    float dolares = bitcoins * BITCOIN_TO_DOLAR;
    return dolares;
}

float dolarToBitcoins(float dolares) {
    return dolares * DOLAR_TO_BITCOIN;
}