#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>


double geom_avg(int n, ...) {
    double res = 1;
    va_list ptr;  // Указатель va_list
    va_start(ptr, n); // Устанавливаем указатель
    for (int i = 0; i < n; i++) {

        res *= va_arg(ptr, int);
    }
    res = pow(res, pow(n, -1));
    va_end(ptr); // Завершаем обработку параметров
    return res;
}

int main() {
    int n = 3;
    double result = geom_avg(n, 2, 4, 8);

    printf("The result is: %lf", result);

    return 0;

}
