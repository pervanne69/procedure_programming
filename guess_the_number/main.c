#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main() {
    srand(time(NULL));
    printf("Hello my friend.\nYou are in the game which is called 'GUESS THE NUMBER!'\n");
    printf("Now you are must guess the initial number with some tips.\n");
    printf("We are call it 'less-more'\n");
    printf("Let's start this game:\n");
    int initial_number, guess_number;
    int count = 0;
    initial_number = rand() % (1000 + 1000 + 1) - 1000;
    while (1) {
        printf("Initial number = ");
        scanf("%d", &guess_number);
        if (guess_number > initial_number) {
            printf("More then initial number\n");
            count += 1;
        } else if (guess_number < initial_number) {
            printf("Less then initial number\n");
            count += 1;
        } else {
            count += 1;
            printf("Congratulations! You are right. The initial number is %d\nYou guessed this number in %d attempts", guess_number, count);
            break;
        }
    }
    return 0;

}