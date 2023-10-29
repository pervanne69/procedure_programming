#include <stdio.h>
#include <math.h>


int main() {
    float x, y;
    int code;
    float res;
    printf("Input x: ");
    scanf("%f", &x);
    printf("Input y: ");
    scanf("%f", &y);
    printf("oper:\n0 = exit the program\n1 = +\n2 = -\n3 = *\n4 = /\n5 = ^\nselect code = ");
    scanf("%d", &code);
    while (code != 0) {
        switch (code) {
            case 1: {
                res = x + y;
                printf("%f + %f = %f\n", x, y, res);
                break;
            }
            case 2: {
                res = x - y;
                printf("%f - %f = %f\n", x, y, res);
                break;
            }
            case 3: {
                res = x * y;
                printf("%f * %f = %f\n", x, y, res);
                break;
            }
            case 4: {
                if (y == 0) {
                    printf("Division by zero!\n");
                } else {
                    res = x / y;
                    printf("%f / %f = %f\n", x, y, res);
                }
                break;
            }
            case 5: {
                res = powf(x, y);
                printf("%f ^ %f = %f\n", x, y, res);
                break;
            }
            default: {
                printf("It is not a code. Please choose the right answer\n");
                break;
            }
        }
        printf("Input x: ");
        scanf("%f", &x);
        printf("Input y: ");
        scanf("%f", &y);
        printf("oper:\n0 = exit the program\n1 = +\n2 = -\n3 = *\n4 = /\n5 = ^\nselect code = ");
        scanf("%d", &code);
    }
    printf("Your exit the program. Have a nice day!");
    return 0;
}