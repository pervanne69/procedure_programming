#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

double difference_of_square(int n, ...) {
    double res = 0;
    va_list ptr;  // Указатель va_list
    va_start(ptr, n); // Устанавливаем указатель
    res = pow(va_arg(ptr, int), 2);
    for (int i = 1; i < n; i++) {
        res = res - pow(va_arg(ptr, int), 2);  // Получаем текущее значение параметра типа int
    }
    va_end(ptr); // Завершаем обработку параметров
    return res;
}

int main() {
    int n = 3;
    double result = difference_of_square(n, 10, 4, 5);

    printf("The result is: %.lf", result);

    return 0;

}