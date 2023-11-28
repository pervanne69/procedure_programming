#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int c_n_k(int n, int k) {
    long long int n_fact = 1, n_k_fact = 1, k_fact = 1;
    long long int i;
    long long int res;
    for (i = 1; i <= n; i++) {
        n_fact *= i;
    }
    for (i = 1; i <= (n - k); i++) {
        n_k_fact *= i;
    }
    for (i = 1; i <= k; i++) {
        k_fact *= i;
    }
    res = (int)(n_fact / (n_k_fact * k_fact));
    return res;
}

int main() {
    long long int a, b, n, res = 0;
    printf("Let's calculate the expression (a + b) ^ n\n");
    printf("Input first number (a): ");
    scanf("%lld", &a);
    printf("Input second number (b): ");
    scanf("%lld", &b);
    printf("Input (n): ");
    scanf("%lld", &n);
    for (int i = 0; i <= n; i++) {
        if (i > 0) {
            res += (int)(pow(a, n - i)) * (int)(pow(b, i)) * c_n_k(n, i);
        } else {
            res += (int)(pow(a, n - i)) * (int)(pow(b, i));
        }
    }
    printf("Result = %lld", res);

    

}