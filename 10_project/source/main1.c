#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define N 10
#define M 10

int main() {

    srand(time(NULL));

    int **ar;

    int *x;

    ar = (int **) malloc(sizeof(int) * N);

    x = (int *) malloc(sizeof(int) * M);

    printf("X:\n ");

    for (int i = 0; i < M; ++i) {
        x[i] = rand() % (10 + 10 + 1) - 10;
        printf("%3d ", x[i]);
    }

    putchar('\n');

    printf("Array:\n");

    for (int i = 0; i < N; ++i) {
        ar[i] = (int *) malloc(sizeof(int) * M);
        for (int j = 0; j < M; ++j) {
            ar[i][j] = rand() % (100 + 100 + 1) - 100;
            printf("%5d ", ar[i][j]);
        }
        putchar('\n');
    }

    putchar('\n');

    printf("Result Array:\n ");

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (i % 2 != 0) {
                printf("%5d ", x[j]);
            } else {
                printf("%5d ", ar[i][j]);
            }

        }
        free(ar[i]);
        putchar('\n');
    }
    free(ar);
    free(x);
    return 0;
}
