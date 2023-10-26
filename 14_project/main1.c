#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int get_count_of_prime_numbers(int *arr, int len) {
    int count = 0; // Количество элементов
    int count_of_div; // Количество делителей числа
    printf("Count of prime numbers:\n");
    for (int i = 0; i < len; i++) {
        if (arr[i] != 1 && arr[i] != 0) {
            count_of_div = 0;
            for (int j = 1; j < arr[i]; j++) {
                if (arr[i] % j == 0) {
                    count_of_div += 1;
                    if (count_of_div > 1) {
                        break;
                    }
                }
            }
            if (count_of_div == 1) {
                printf("%d ", arr[i]);
                count += 1;
            }
        }
    }
    putchar('\n');
    return count;

}

double get_min_prime_number(int *arr, int len, int *mini) {
    *mini = 1000000;
    int count_of_div;
    int count_of_prime = get_count_of_prime_numbers(arr, len);
    for (int i = 0; i < len; i++) {
        if (arr[i] != 1 && arr[i] != 0) {
            count_of_div = 0;
            for (int j = 1; j < arr[i]; j++) {
                if (arr[i] % j == 0) {
                    count_of_div += 1;
                    if (count_of_div > 1) {
                        break;
                    }

                }
            }
            if (count_of_div == 1) {
                if (*mini > arr[i]) {
                    *mini = arr[i];
                }
            }
        }

    }
    return count_of_prime;
}

int main() {
    srand(time(NULL));
    int n;
    printf("Set the array length: ");
    scanf("%d", &n);
    int *arr = (int *) malloc(sizeof(int) * n);
    // создаем указатель на функцию
    double (*fptr)(int *, int, int *) = NULL;
    printf("Initial Array:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    putchar('\n');
    fptr = get_min_prime_number;
    int mini;
    int get_count_of_prime = fptr(arr, n, &mini);

    printf("Count of prime numbers = %d\n", get_count_of_prime);
    printf("Minimal of prime numbers = %d\n", mini);

    free(arr);

    return 0;


}