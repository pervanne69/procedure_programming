#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 2

int main() {

    srand(time(NULL));
    int **ar;

    int total = 0, amount = 0;

    double average;

    ar = (int **)malloc(sizeof(int) * N);

    printf("Initial Array:\n");

    for (int i = 0; i < N; ++i) {
        ar[i] = (int *)malloc(sizeof(int) * N);
        for (int j = 0; j < N; ++j) {
            ar[i][j] = rand() % 10;
            printf("%3d ", ar[i][j]);
            if (i < j) {
                total += ar[i][j];
                amount += 1;
            }
        }
        putchar('\n');
    }
    putchar('\n');

    average = (double)(total) / (double)(amount);

    printf("Total = %d, Amount = %d, Average = %7.3lf", total, amount, average);

    free(ar);

}
