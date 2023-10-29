#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

struct Element {
    int x;
    int y;
};

typedef struct Element Element;

double length_of_vector(int n, ...) {
    double res = 0;
    Element cur_el;
    va_list ptr;  // Указатель va_list
    va_start(ptr, n); // Устанавливаем указатель
    for (int i = 0; i < n; i++) {
        cur_el = va_arg(ptr, Element);  // Получаем текущее значение параметра типа Element
        res += pow(pow(cur_el.x, 2) + pow(cur_el.y, 2), 0.5);
    }
    va_end(ptr); // Завершаем обработку параметров
    return res;
}

int main() {
    int n = 3;
    Element el1 = {1, 2};
    Element el2 = {2, 3};
    Element el3 = {3, 4};
    double result = length_of_vector(n, el1, el2, el3);

    printf("The result is: %lf", result);

    return 0;

}