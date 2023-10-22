#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
    srand(time(NULL));
    int **ar;
    int i,j, *mas;
    int n = rand() % 10 + 1;
    ar = (int**)malloc(n*sizeof(int*));
    mas = (int*)malloc(n*sizeof(int)); // массив кол-ва элементов строк
    // Ввод элементов массива
    for(i = 0; i<n; i++) {
        mas[i] = rand() % 10 + 1;
        ar[i] = (int*)malloc(mas[i]*sizeof(int));
        for(j = 0; j<mas[i]; j++) {
            ar[i][j] = rand() % (50+50+1) - 50;
        }
    }

    for(i=0; i<n; i++) {
        for(j=0; j<mas[i]; j++) {
            printf("%5d ", ar[i][j]);
        }
        printf("\n");
        free(ar[i]);
    }
    free(ar);
    return 0;
}
