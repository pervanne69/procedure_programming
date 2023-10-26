#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>



#define N 1000

//int cut_res(char str, char *result_str) {
//    for (int i = 0; i < N; i++) {
//        if (islower(str[i]) == str[i]) {
//
//        }
//    }
//}

int main() {
    char str[N];

    char *result_res = malloc(N);

    int count = 0;

    printf("Write the string: ");
    fgets(str, 102, stdin);
    printf("You wrote: ");
    puts(str);

    for (int i = 0; i < N; i++) {
        printf("%c", str[i]);
    }


    return 0;
}
