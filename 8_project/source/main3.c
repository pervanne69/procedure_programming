#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int *A, *B;
    int i;
    int n_A = 100;
    int n_B = 100;
    A = (int*)malloc(n_A * sizeof(int));
    B = (int*)calloc(n_B, sizeof(int));
    printf("Address of A = %p\n", &A);
    printf("Address of B = %p\n\n", &B);
    printf("A: \n\n");
    for (i = 0; i < n_A; ++i) {
        printf("%d ", A[i]);
    }
    printf("\n\nB\n\n");
    for (i = 0; i < n_B; ++i) {
        printf("%d ", B[i]);
    }
    printf("\n\n");

    A = realloc(A, sizeof(int) * 200);
    B = realloc(B, sizeof(int) * 50);
    for (i = 0; i < 200; ++i) {
        printf("%d ", A[i]);
    }
    printf("\n\nB\n\n");
    for (i = 0; i < 50; ++i) {
        printf("%d ", B[i]);
    }
    free(A);
    free(B);
    return 0;
}
