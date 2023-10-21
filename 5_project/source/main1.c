#define N 100

#include <stdio.h>

#include <stdlib.h>

int main()

{

    int array[N];

    int count;

    int maxi = -101;

    for (int i = 0; i <= N; i++) {

        array[i] = rand()%(100+100+1) - 100;

    }

    for (int i =0; i <= N; i++) {

        if (array[i] > maxi) {

            maxi = array[i];

        }

    }

    printf("max = %d\n", maxi);

    for (int i = 0; i <= N; i++) {

        count = 0;

        for (int j = 0; j <= N; j++) {

            if (array[i] == array[j] && i != j) {

                count += 1;

                break;

            }

        }

        if (count > 0) {

            array[i] = maxi;

        }

        printf("%d ", array[i]);

    }
    return 0;

}