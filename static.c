#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define N 500
#define M 500
#define P 500
#define NUM_THREADS 8  // Define number of threads

void initializeMatrix(int matrix[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void matrixMultiplyStatic(int A[N][M], int B[M][P], int C[N][P]) {
    #pragma omp parallel for collapse(2) schedule(static)
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

    omp_set_num_threads(NUM_THREADS);  // Set OpenMP to use 12 threads

    double start = omp_get_wtime();
    matrixMultiplyStatic(A, B, C);
    double end = omp_get_wtime();

    printf("Static Scheduling Execution Time for 12 threads %f seconds\n", end - start);
  //  printf("Number of threads used: %d\n", NUM_THREADS);  // Print number of threads

    return 0;
}
