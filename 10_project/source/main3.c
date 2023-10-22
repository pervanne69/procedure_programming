#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define N 5

double get_avg_geometrical(int **ar) {
    int total = 1;
    int amount = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i + j > N - 1 && ar[i][j] < 0) {
                printf("%8d [%d][%d]", ar[i][j], i, j);
                total *= abs(ar[i][j]);
                amount += 1;
            }
        }
    }
    double result = (double)(pow(total, ((double)1 / (double)amount)));
    return result;

}

int main() {
    srand(time(NULL));
    int **ar;

    ar = (int**)malloc(sizeof(int) * 5);

    printf("Initial Array:\n");

    for (int i = 0; i < N; ++i) {
        ar[i] = (int*)malloc(sizeof(int) * N);
        for (int j = 0; j < N; ++j) {
            if (i < j) {
                ar[i][j] = 0;
            } else {
                ar[i][j] = rand() % (10 + 10 + 1) - 10;
            }
            printf("%8d ", ar[i][j]);
        }
        free(ar[i]);
        putchar('\n');
    }

    double avg_geom = get_avg_geometrical(ar);
    putchar('\n');
    printf("Average = %8.5lf", avg_geom);
    free(ar);
}

