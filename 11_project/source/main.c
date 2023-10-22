#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define M 5
#define K 3
#define N 6

int main() {
    srand(time(NULL));

    int **A, **B, **C;

    int i, j, k;

    int cur_total;

    A = (int **)malloc(M * sizeof(int));
    B = (int **)malloc(K * sizeof(int));
    C = (int **)malloc(M * sizeof(int));

    printf("A:\n");

    for (i = 0; i < M; ++i) {
        A[i] = (int *)malloc(K * sizeof(int));
        for (j = 0; j < K; ++j) {
            A[i][j] = rand() % 5;
            printf("%3d ", A[i][j]);
        }
        putchar('\n');
    }

    printf("\nB:\n");

    for (i = 0; i < K; ++i) {
        B[i] = (int *)malloc(N * sizeof(int));
        for (j = 0; j < N; ++j) {
            B[i][j] = rand() % 5;
            printf("%3d ", B[i][j]);
        }
        putchar('\n');
    }

    printf("\nC:\n");

    for (i = 0; i < M; ++i) {
        C[i] = (int *)malloc(N * sizeof(int));
        for (j = 0; j < N; ++j) {
            cur_total = 0;
            for (k = 0; k < K; ++k) {
                cur_total += A[i][k] * B[k][j];
            }
            C[i][j] = cur_total;
        }
    }

    for (i = 0; i < M; ++i) {
        for (j = 0; j < N; ++j) {
            printf("%3d ", C[i][j]);
        }
        putchar('\n');
    }
    free(A);
    free(B);
    free(C);
    return 0;

}
