#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define N 20


int get_3k(int *ar) {
    for (int i = 0; i < N; ++i) {
        if ((abs(ar[i]) - 1) % 3 == 0) {
            printf("%3d ", ar[i]);
        }
    }
    return 0;
}

int main() {

    srand(time(NULL));
    int *ar;

    ar = (int *)malloc(N * sizeof(int));
    printf("Initial Array:\n ");

    for (int i = 0; i < N; ++i) {
        ar[i] = rand() % (100 + 100 + 1) - 100;
        printf("%3d ", ar[i]);
    }

    putchar('\n');

    printf("Result array:\n");
    get_3k(ar);
    free(ar);
}
