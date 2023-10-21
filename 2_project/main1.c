#include <stdio.h>
#include <math.h>
int main() {
    double x, y;
    printf("x: ");
    scanf("%lf",&x);
    printf("y: ");
    scanf("%lf",&y);
    printf("x=%lf;  y=%lf\n",x,y);
    if (pow(x, 2) + pow(y, 2) <= 1 && y >= 1 - x) {
        printf("The point is in the area\n");
    } else {
        printf("The point isn't in the area");
    }
    return 0;
}
