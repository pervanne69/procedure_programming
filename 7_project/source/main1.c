#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 100

double get_total(double *ar) {
    double total = 0;
    for (int i =0; i < N; i++) {
        if (ar[i] > 0) {
            total += ar[i];
        }
    }
    return total;
}

int get_amount(double *ar) {
    int amount = 0;
    for (int i =0; i < N; i++) {
        if (ar[i] > 0) {
            amount += 1;
        }
    }
    return amount;
}

int main()
{
    srand(time(NULL));
    double *ar;
    ar = (double *)malloc(N * sizeof(double));
    for (int i = 0; i < N; ++i) {
        ar[i] = rand() % (100 + 100 + 1) - 100;
        printf("%3.2lf ", ar[i]);
    }
    printf("\n\n");
    double total = get_total(ar);
    int amount = get_amount(ar);
    double average = total / (double)(amount);
    printf("Total = %lf Amount = %d Average = %lf\n\n", total, amount, average);
    for (int i = 0; i <N; ++i) {
        if (ar[i] < 0) {
            ar[i] = average;
        }
        printf("%3.2lf ", ar[i]);

    }
    return 0;
}

