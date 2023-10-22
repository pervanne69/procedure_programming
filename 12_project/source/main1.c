#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING "pervanne69"

int to_space(int n, char *str, char *str2) {
    int index = 0;
    if (n <= strlen(STRING)) {
        for (int i = strlen(STRING) - n; i < strlen(STRING); ++i) {
            str2[index] = str[i];
            index += 1;
        }
    } else {
        for (int i = 0; i < n - strlen(STRING); ++i) {
            str2[i] = NULL;
        }
        for (int i = n - strlen(STRING); i < n; ++i) {
            str2[i] = str[index];
            index += 1;
        }
    }

    return 0;
}

int main() {
    char *str = malloc(sizeof(char) * (strlen(STRING) + 1));
    char *str2;
    int n;
    int size_res = 0;

    strcpy(str, STRING);
    printf("%s\n", str);

    printf("Set the string result length:\n");
    scanf("%d", &n);

    if (n <= strlen(STRING)) {
        size_res = strlen(STRING) - (strlen(STRING) - n);;
    } else {
        size_res = strlen(STRING) + (n - strlen(STRING));
    }
    str2 = malloc(sizeof(char) * (size_res + 1));

    printf("\nResult:\n");

    to_space(n, str, str2);

    for (int i = 0; i < size_res + 1; ++i) {
        printf("%c", str2[i]);
    }

    free(str);
    free(str2);

    return 0;
}
