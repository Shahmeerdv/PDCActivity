#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 500
#define M 500
#define P 500

void initializeMatrix(int matrix[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void matrixMultiplySequential(int A[N][M], int B[M][P], int C[N][P]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < P; j++) {
            C[i][j] = 0;
            for (int k = 0; k < M; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[N][M], B[M][P], C[N][P];

    srand(time(NULL));
    initializeMatrix(A);
    initializeMatrix(B);

    clock_t start = clock();
    matrixMultiplySequential(A, B, C);
    clock_t end = clock();
    
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Sequential Execution Time: %f seconds\n", time_taken);

    return 0;
}
