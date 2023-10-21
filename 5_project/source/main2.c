#define N 100

#include <stdio.h>

#include <stdlib.h>

int main()

{

    int array[N];

    int total = 0;

    int count = 0;

    double average;

    for (int i = 0; i <= N; i++) {

        array[i] = rand()%(100+100+1) - 100;

        total += array[i];

    }

    average = (double)total / N;

    for (int i = 0; i <= N; i++) {

        if ((double)array[i] > average) {

            count += 1;

        }

    }

    printf("Count = %d", count);

    return 0;

}