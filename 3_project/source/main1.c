#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void get_two_power() {
    long int n;
    printf("n: ");
    scanf("%ld", &n);
    for (long int i = 0; i <= n; i++) {
        if (pow(2, i) <= n) {
            printf("2 pow %ld: %.f\n", i, pow(2, i));
        } else {
            break;
        }
    }
}

int main()
{
    get_two_power();
    return 0;

}

