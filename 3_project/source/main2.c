#include <stdio.h>
#include <stdlib.h>

int main()
{
    double a;
    printf("Input a number\n");
    scanf("%lf", &a);
    double result;
    while (a >= 0) {
        result += a;
        printf("a = %lf\n", a);
        scanf("%lf", &a);
        if (a <= 0) {
            printf("negative number!\n");
        }
    }
    printf("Result = %lf\n", result);
    return 0;

}
