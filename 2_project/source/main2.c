#include <stdio.h>
#include <math.h>

int main()
{
    double x = 5.7;
    double y = 1.2;
    double r, t;
    if (x > y) {
        r = cos(x + pow(y, 2));
    }
    else {
        r = log10((x + y) / (x - y));
    }

    if (r < x) {
        t = (x + r) / cos(x - r);
    }
    else if (r == x) {
        t = sqrt(y - pow(r - x, 1/3));
    }
    else {
        t = fabs(pow(x, 2) - r) / (1 + sin(r));
    }
    printf("x = %lf, y = %lf, r = %lf, t = %lf", x, y, r, t);

    return 0;
}
