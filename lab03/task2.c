#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4 

int main() {
    int matrix[N][N];

    srand((unsigned int)time(NULL));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 10 - 5;
        }
    }

   
    printf("Matrix (%dx%d):\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    int is_symmetric = 1;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                is_symmetric = 0;
                break;
            }
        }
        if (!is_symmetric) {
            break;
        }
    }

    if (is_symmetric) {
        printf("The matrix IS symmetric with respect to its main diagonal.\n");
    } else {
        printf("The matrix IS NOT symmetric with respect to its main diagonal.\n");
    }

    return 0;
}