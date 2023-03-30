#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int **A, **B, **C;
int M, N, P;

int main() {
    int num_threads;
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    printf("Enter the matrix dimensions (M N P): ");
    scanf("%d %d %d", &M, &N, &P);
    A = (int **)malloc(M * sizeof(int *));
    B = (int **)malloc(N * sizeof(int *));
    C = (int **)malloc(M * sizeof(int *));
    for (int i = 0; i < M; i++) {
        A[i] = (int *)malloc(N * sizeof(int));
        C[i] = (int *)malloc(P * sizeof(int));
    }
    for (int i = 0; i < N; i++) {
        B[i] = (int *)malloc(P * sizeof(int));
    }
    printf("Enter matrix A:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    printf("Enter matrix B:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < P; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    omp_set_num_threads(num_threads);

    #pragma omp parallel for
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    printf("Matrix A:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("Matrix B:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < P; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    printf("Matrix C:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < M; i++) {
        free(A[i]);
        free(C[i]);
    }
    for (int i = 0; i < N; i++) {
        free(B[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}
