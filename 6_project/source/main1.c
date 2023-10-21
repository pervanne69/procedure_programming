#define N 10

#define M 20

#include <stdio.h>

#include <time.h>

#include <stdlib.h>

int main()

{

    srand(time(NULL));

    int array[N][M];

    int array_result[N];

    int total;

    printf("Matrix:\n\n");

    for (int i = 0; i < N; ++i) {

        total = 0;

        for (int j = 0; j < M; ++j) {

            array[i][j] = rand() % 10;

            total += array[i][j];

            printf("%d ", array[i][j]);

        }

        printf("\n\n");

        array_result[i] = total;

    }

    printf("Vector\n");

    for (int i = 0; i < N; ++i) {

        printf("%d ", array_result[i]);

    }

    return 0;

}