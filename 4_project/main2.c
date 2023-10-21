#define N 200
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[N];
    int total_ar[N];
    int k =0;
    int count = 0;
    int total = 0;
    for (int i =0; i < N; i++) {
        total_ar[i] = 0;
    }
    for (int i = 0; i < N; ++i) {
        array[i] = rand()%(10+10+1) - 10;
        if (array[i] > 0) {
            total += 1;
        } else {
            if (total > 0) {
                count += 1;
                total_ar[k] = total;
                total = 0;
                k += 1;
            }

        }
    }
    printf("\n%d\n", count);
    int t = 0;
    for (int i = 0; i < N; i++) {
        t += total_ar[i];
    }
    double result = (double)t / count;
    printf("%lf", result);

    return 0;
}
