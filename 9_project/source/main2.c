#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define N 10


int get_total(int *ar) {
    int total = 0;
    for (int i = 0; i < N; ++i) {
        if (ar[i] % 3 == 0) {
            total += i;
        }
    }
    return total;

}

int main() {

    srand(time(NULL));
    int *ar;

    ar = (int *)malloc(sizeof(int) * N);

    int total = 0;

    for (int i = 0; i < N; ++i) {
        ar[i] = rand() % 10;
        printf("%3d ", ar[i]);
    }

    total = get_total(ar);

    printf("\ntotal = %d\n", total);

    return 0;


}
