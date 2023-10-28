#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int get_avg_median_moda(int *arr, double *avg, double *median, int *moda, int *count_numbers_of_moda, int n) {

    // Нахождение среднего арифметического ряда
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    *avg = (double) (total) / (double) (n);


    // Нахождение медианы ряда

    if (n % 2 != 0) {
        *median = arr[n / 2];
    } else {
        *median = (double)(arr[n / 2] + arr[n / 2 - 1]) / 2;
    }

    // Нахождение моды ряда

    int max_count = 1, cur_count;
    for (int i = 0; i < n; i++) {
        cur_count = 1;
        for (int j = 0; j != i && j < n; j++) {
            if (arr[i] == arr[j]) {
                cur_count += 1;
            }
        }
        if (cur_count > max_count) {
            max_count = cur_count;
        }
    }
    if (max_count != 1) {
        int extra_j = 0; // Текущее значение, которое повторяется максимальное количество раз
        for (int i = 0; i < n; i++) {
            cur_count = 1;
            for (int j = 0; j != i && j < n; j++) {
                if (arr[i] == arr[j]) {
                    cur_count += 1;
                }
            }
            if (cur_count == max_count && arr[i] != extra_j) {
                moda[*count_numbers_of_moda] = arr[i];
                *count_numbers_of_moda = *count_numbers_of_moda + 1;
                extra_j = arr[i];

            }
        }
        moda = realloc(moda, *count_numbers_of_moda);
    } else {
        moda = NULL;
    }
    return 0;
}


int main() {
    srand(time(NULL));
    int n;
    int *arr;
    double avg, median;
    int *moda;
    int count_numbers_of_moda = 0;

    printf("Write the length of the array: ");
    scanf("%d", &n);

    arr = (int *) malloc(sizeof(int) * n);

    moda = (int *) malloc(sizeof(n) * n);

    printf("Initial Array:\n");


    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (10 + 10 + 1) - 10;
        printf("%d ", arr[i]);
    }
    putchar('\n');

    int (*gamm)(int *, double *, double *, int *, int *, int);

    gamm = get_avg_median_moda;

    gamm(arr, &avg, &median, moda, &count_numbers_of_moda, n);

    printf("The average of array is %.3lf\n", avg);
    printf("The median of array is %.3lf\n", median);


    if (count_numbers_of_moda == 0) {
        printf("The array have not moda because every value counts one more time\n");
    } else {
        printf("Mod of array is:\n");

        for (int i = 0; i < count_numbers_of_moda; i++) {
            printf("%d ", moda[i]);
        }
    }


    return 0;
}
