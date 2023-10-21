#include <stdio.h>
#include <math.h>
int main()
{
    float t = 0.5;
    int z = 6;
    float y = t + 2 * (1 / tan(z));
    float x = 3 * pow(y, 2) / (4 * tan(z) - 2 * pow(t, 2));
    printf("X = %f", x);
    return 0;
}
