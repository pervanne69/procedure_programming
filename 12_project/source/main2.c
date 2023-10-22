#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING1 "pervanne69"
#define STRING2 "cool"

int fasten_strings(char *str1, char *str2, char *str3) {
    for (int i = 0; i < strlen(STRING1); ++i) {
        str3[i] = str1[i];
    }
    for (int i = 0; i < strlen(STRING2); ++i) {
        str3[strlen(STRING1) + i] = str2[i];
    }
    return 0;
}


int main() {

    char *str1 = malloc(sizeof(char) * (strlen(STRING1) + 1));
    char *str2 = malloc(sizeof(char) * (strlen(STRING2) + 1));
    char *str3 = malloc(sizeof(char) * (strlen(STRING1) + strlen(STRING2) + 1));
    strcpy(str1, STRING1);
    strcpy(str2, STRING2);
    printf("%s\n", str1);
    printf("%s\n", str2);

    fasten_strings(str1, str2, str3);
    for (int i = 0; i < strlen(STRING1) + strlen(STRING2); ++i) {
        printf("%c", str3[i]);
    }
    putchar('\n');
    free(str1);
    free(str2);
    free(str3);

    return 0;
}
