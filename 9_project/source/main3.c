#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 300

int fill_res_arr(int *arr, int *res_arr, int *new_size) {
    int a, b, c, d, e = 0;
    for (int i = 0; i < N; ++i) {
        a = arr[i] / 10000;
        b = (arr[i] % 10000) / 1000;
        c = (arr[i] % 1000) / 100;
        d = (arr[i] % 100) / 10;
        e = arr[i] % 10;
        if (a + b == d + e && a + b == c) {
            res_arr[*new_size] = arr[i];
            *new_size = *new_size + 1;
        }
    }

    return 0;
}

int main() {

    srand(time(NULL));


    int new_size = 0;

    int *arr = (int *) malloc(sizeof(int) * N);
    int *res_arr = (int *) calloc(N, sizeof(int));

    printf("Initial Array\n\n");

    for (int i = 0; i < N; ++i) {
        arr[i] = rand() % (99999 - 10000 + 1) + 10000;
        printf("%d ", arr[i]);

    }
    fill_res_arr(arr, res_arr, &new_size);

    res_arr = realloc(res_arr, sizeof(int) * new_size);

    printf("\n\nResult Array\n\n");

    for (int i = 0; i < new_size; ++i) {
        printf("%d ", res_arr[i]);
    }

    free(arr);
    free(res_arr);


    return 0;
}