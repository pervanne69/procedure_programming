#include <stdio.h>




int main() {
    char s1_p[] = "(o o)";
    char s2_p[] = "/ V \\";
    char s3_p[] = "/(_)\\";
    char s4_p[] = "^^ ^^";

    char s1_c[] = "/\\_/\\";
    char s2_c[] = "/@ @\\";
    char s3_c[] = "(~~0~~)";

    int cnt_p = 0, cnt_c = 0;
    printf("Input count of penguins: ");
    scanf("%d", &cnt_p);
    printf("Input count of cats: ");
    scanf("%d", &cnt_c);

    for (int i = 0; i < cnt_p; i++) {
        printf("%s\t", s1_p);
    }
    for (int i = 0; i < cnt_c; i++) {
        printf("%s\t", s1_c);
    }
    putchar('\n');
    for (int i = 0; i < cnt_p; i++) {
        printf("%s\t", s2_p);
    }
    for (int i = 0; i < cnt_c; i++) {
        printf("%s\t", s2_c);
    }
    putchar('\n');
    for (int i = 0; i < cnt_p; i++) {
        printf("%s\t", s3_p);
    }
    for (int i = 0; i < cnt_c; i++) {
        printf("%s\t", s3_c);
    }
    putchar('\n');
    for (int i = 0; i < cnt_p; i++) {
        printf("%s\t", s4_p);
    }

    return 0;
}
