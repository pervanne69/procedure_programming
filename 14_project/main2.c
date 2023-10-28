#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int get_total_negative_and_count_positive(int *arr, int *count_p, int len) {
    int total_negative = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] < 0) {
            total_negative += arr[i];
        } else if (arr[i] > 0) {
            *count_p = *count_p + 1;
        }
    }
    return total_negative;
}


int main() {
    srand(time(NULL));
    int n;
    int *arr;
    int count_positive = 0;

    printf("Write the length of the array: ");

    scanf("%d", &n);

    arr = (int *) malloc(sizeof(int) * n);

    printf("Initial Array:\n ");

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (100 + 100 + 1) - 100;
        printf("%d ", arr[i]);
    }
    putchar('\n');

    int (*gtncp)(int *, int *, int) = NULL;

    gtncp = get_total_negative_and_count_positive;

    int get_total_negative = gtncp(arr, &count_positive, n);

    printf("Total of negative numbers is %d\n", get_total_negative);
    printf("Count of positive numbers is %d\n", count_positive);

    free(arr);

    return 0;
}
