#define N 4

#define M 4

#include <stdio.h>

#include <time.h>

#include <stdlib.h>

int main()

{

    srand(time(NULL));

    int array[N][M], array_result[N][M];

    int array_1[2] = {0, 0};

    int array_2[2] = {0, 0};

    int maxi = -11, mini = 11;

    int total1 = 0, total2 = 0;

    printf("Initial Matrix: \n\n");

    for (int i =0; i < N; ++i) {

        for (int j = 0; j < M; ++j) {

            array[i][j] = rand() % (10+10+1) - 10;

            printf("%d ", array[i][j]);

            if (i < (N / 2) && j < (M / 2)) {

                total1 += array[i][j];

                if (maxi < array[i][j]) {

                    maxi = array[i][j];

                    array_1[0] = i;

                    array_1[1] = j;

                }

            } if (i >= (N / 2) && j >= (M / 2)) {

                total2 += array[i][j];

                if (array[i][j] < mini) {

                    mini = array[i][j];

                    array_2[0] = i;

                    array_2[1] = j;

                }

            }

        }

        printf("\n\n");

    }

    printf("\n\nMaxi = %d, Mini = %d, total1 = %d, total2 = %d\n\n", maxi, mini, total1, total2);

    printf("Maxi coordinate: %d %d \n\n", array_1[0], array_1[1]);

    printf("Mini coordinate: %d %d \n\n", array_2[0], array_2[1]);

    printf("Result Matrix: \n\n");

    for (int i = 0; i < N; ++i) {

        for (int j =0; j < M; ++j) {

            array_result[i][j] = array[i][j] + total1 + total2;

            printf("%d ", array_result[i][j]);

        }

        printf("\n\n");

    }

    return 0;

}