#define N 100
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int array[N];
    int mini = 10;
    for (int i = 0; i < N; ++i) {
        array[i] = rand()%(9+9+1) - 9;
    }
    for (int i = 0; i < N; ++i) {
        if (array[i] > 0 && array[i] < mini) {
            mini = array[i];
        }
    }
    for (int i = 0; i < N; ++i) {
        if (array[i] < 0) {
            array[i] = mini;
        }
    }
    for (int i = 0; i < N; ++i) {
        printf("%d ", array[i]);
    }
}
