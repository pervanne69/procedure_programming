#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N1 2
#define M1 2

#define N2 3
#define M2 3

int main() {
    srand(time(NULL));

    int **x, **y, **z;

    x = (int **)malloc(sizeof(int) * N1);
    y = (int **)malloc(sizeof(int) * N2);
    z = (int **)calloc(N1 + N2, sizeof(int));

    printf("X:\n");

    for (int i = 0; i < N1; ++i) {
        x[i] = (int*)malloc(sizeof(int) * M1);
        for (int j = 0; j < M1; ++j) {
            x[i][j] = rand() % (10 + 10 + 1) - 10;
            printf("%6d ", x[i][j]);
        }
        putchar('\n');
    }

    printf("\nY:\n");

    for (int i = 0; i < N2; ++i) {
        y[i] = (int *)malloc(sizeof(int) * M2);
        for (int j = 0; j < M2; ++j) {
            y[i][j] = rand() % (10 + 10 + 1) - 10;
            printf("%6d ", y[i][j]);
        }
        putchar('\n');
    }

    printf("\nZ:\n");

    for (int i = 0; i < (N1 + N2); ++i) {
        z[i] = (int *)calloc(M1 + M2, sizeof(int));

        for (int j = 0; j < (M1 + M2); ++j) {
            printf("%d ", z[i][j]);
        }
        putchar('\n');
    }

    printf("\nZ Result:\n");

    for (int i = 0; i < N1; ++i) {
        for (int j = 0; j < M2; ++j) {
            z[i][j] = x[i][j];
        }
        free(x[i]);
    }
    for(int i = N1 ;i < N1 + N2; ++i) {
        for(int j = M1; j < M1 + M2; ++j) {
            z[i][j] = y[i-N1][j-M1];
        }
        free(y[i]);
    }

    for (int i = 0; i < (N1 + N2); ++i) {
        for (int j = 0; j < (M1 + M2); ++j) {
            if (z[i][j] != 0 && abs(z[i][j]) > 10) {
                z[i][j] = 0;
            }
            printf("%8d ", z[i][j]);
        }
        free(z[i]);
        putchar('\n');
    }
    free(x);
    free(y);
    free(z);
    return 0;
}
