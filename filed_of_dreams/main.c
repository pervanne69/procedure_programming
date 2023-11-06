#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main() {
    printf("Welcome to our game. You need to guess the word with your team.\nLet's start the game!\n");
    char s[1000]; 
    char letter;
    int target = 1;
    int count_of_m;
    int n = 0;
    int m = 1;
    int flag = 1;
    int winner = 1;
    printf("Write the word:\n");
    fgets(s, 1000, stdin);
    for (int i = 0; i < 1000; i++) putchar('\n'); 
    printf("Write the count of members: ");
    scanf("%d", &count_of_m);
    putchar('\n');
    for (int i = 0; s[i] != '\n'; i++) {
        n += 1;
        putchar('_');
    }
    putchar('\n');
    char s_guessed[n];
    for (int i = 0; i < n; i++) {
        s_guessed[i] = '_';
    }
    while (1) {
        if (target) {
            scanf("%*c");
        }
        target = 1;
        flag = 1;
        putchar('\n');
        printf("Write the letter:\n");
        scanf("%c", &letter);
        for (int i = 0; i < n; i++) {
            if (s[i] == letter && s_guessed[i] == '_') {
                flag = 0;
                s_guessed[i] = letter;
                for (int i = 0; i < n; i++) {
                    if (s[i] == s_guessed[i]) {
                        winner = 1;
                        continue;
                    } else {
                        winner = 0;
                        break;
                    }
                }
            } else {
                winner = 0;
            }
        }
        if (winner) {
            for (int i = 0; i < n; i++) {
                 putchar(s_guessed[i]);
            }
            printf("\nCongratulations! The player %d wins this game\n", m);
            printf("Press Enter to close the game.\n");
            getchar();
            getchar();
            break;
        }
        for (int i = 0; i < n; i++) {
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
            target = 0;
        }

    }
    return 0;
}