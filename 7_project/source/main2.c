#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 100

int to_left_side(int *ar, int *left_ar, int *count_left) {
    int index = 0;
    for (int i = 0; i < N; ++i) {
        if (ar[i] > 0) {
            left_ar[index] = ar[i];
            index += 1;
            *count_left = *count_left + 1;
        }
    }
    return 0;
}

int to_right_side(int *ar, int *right_ar, int *count_right) {
    int index = 0;
    for (int i = 0; i < N; ++i) {
        if (ar[i] < 0) {
            right_ar[index] = ar[i];
            index += 1;
            *count_right = *count_right + 1;
        }
    }
    return 0;
}


int main() {
    srand(time(NULL));

    int * ar;
    int *left_ar;
    int *right_ar;
    int *middle_ar;

    int count_left = 0;
    int count_right = 0;

    int value = 0;

    ar = (int *)malloc(N * sizeof(int));
    left_ar = (int *)malloc(N * sizeof(int));
    right_ar = (int *)malloc(N * sizeof(int));

    printf("Initial Array:\n ");

    for (int i = 0; i < N; ++i) {
        value = rand() % (100 + 100 + 1) - 100;
        if (value == 1) {
            ar[i] = 0;
        } else {
            ar[i] = value;
        }
        printf("%d ", ar[i]);
    }

    to_left_side(ar, left_ar, &count_left);
    to_right_side(ar, right_ar, &count_right);

    left_ar = (int *)realloc(left_ar, sizeof(int) * count_left);
    right_ar = (int *)realloc(right_ar, sizeof(int) * count_right);

    middle_ar = (int *)calloc(N - (count_right + count_left), sizeof(int));

    putchar('\n');

    printf("Result Array:\n");

    for (int i = 0; i < count_left; ++i) {
        printf("%3d ", left_ar[i]);
    }

    for (int i = 0; i < (N - (count_left + count_right)); ++i) {
        printf("%3d ", middle_ar[i]);
    }

    for (int i = 0; i < count_right; ++i) {
        printf("%3d ", right_ar[i]);
    }
    free(ar);
    free(left_ar);
    free(right_ar);
    free(middle_ar);

}
