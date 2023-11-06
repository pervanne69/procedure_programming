#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main() {
    printf("Welcome to out game. You need to guess the word with your team.\nLet's start the game!\n");
    char s[1000]; 
    char letter;
    int count_of_m;
    int n = 0, i = 0;
    int m = 1;
    int flag = 1;
    printf("Write the word:\n ");
    fgets(s, 1000, stdin);
    printf("Write the count of members: ");
    scanf("%d", &count_of_m);
    putchar('\n');
    for (i = 0; s[i] != '\n'; i++) {
        n += 1;
        putchar('_');
    }
    putchar('\n');
    char s_guessed[n];
    for (i = 0; i < n; i++) {
        s_guessed[i] = '_';
        putchar(s_guessed[i]);
    }
    while (1) {
        putchar('\n');
        printf("Write the letter: ");
        scanf("%c", &letter);
        for (i = 0; s[i] != '\n'; i++) {
            if (s[i] == letter && s_guessed[i] == '_') {
                flag = 0;
                s_guessed[i] == letter;
                break;
            }
        }
        for (i = 0; s_guessed[i] != '\n'; i++) {
            putchar(s_guessed[i]);
        }
        if (flag) {
            if (m < count_of_m) {
                m += 1;
            } else {
                m = 1;
            }
            flag = 1;
            putchar('\n');
            printf("You're wrong.\n");
            printf("The next player is %d", m); 
        }

    }
    return 0;
}