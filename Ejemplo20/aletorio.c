#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    // pseudo-aletorios
    // Semilla -> secuencia de numeros
    srand(time(NULL));
    // printf("Tiempo  %d", );
    printf("%d\n", rand() % 11);        // 0 -- 10
    printf("%d\n", rand() % (11 + 1));  // 0 --- 11
    printf("%d\n",
           rand() % (16 - 5 + 1) + 5);  // (0 - 11) + 5 == [5 , 16]
                                        // [M , N] rand() % (N - M + 1 ) +M

    int n = 6, m = 4;
    int cantParejas = (n * m) / 2;
    char pareajas[cantParejas];

    char matriz[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matriz[i][j] = '\0';
        }
    }

    for (int i = 0; i < cantParejas; i++) {
        pareajas[i] = 'A' + rand() % 25;
      //  printf("%c\n", pareajas[i]);
    }

    int i = 0;  // EL avanze en la parejas
    while (i < cantParejas) {
        // Pos 1 y Pos 2
        int nPos1 = rand() % n, mPos1 = rand() % m;
        while (matriz[nPos1][mPos1] != '\0') {
            nPos1 = rand() % n, mPos1 = rand() % m;
        }

        int nPos2 = rand() % n, mPos2 = rand() % m;
        while (matriz[nPos2][mPos2] != '\0') {
            nPos2 = rand() % n, mPos2 = rand() % m;
        }
        printf("Insertando %c en las posiciones (%d, %d) (%d,%d)\n",pareajas[i], nPos1, mPos1, nPos2,mPos2);

        matriz[nPos1][mPos1] = pareajas[i];
        matriz[nPos2][mPos2] = pareajas[i];
        i++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
