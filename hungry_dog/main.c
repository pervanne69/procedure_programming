#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define N 10
#define M 21

int main() {
    srand(time(NULL));
    // ������ ����������� ������� - ������, ������ ����������� ������� - ������
    int mas[N][M];  // �����
    int i, j;
    int x = 10, y = 5; // ��������� ��������� ������
    int ox, oy;  // ���������� ������ �� �����������
    int ax = 5, ay = 3;
    int count_a = 0;
    char key;  // ������� ������

    do {
         for (i = 0; i < M; i++) {
            mas[0][i] = '#';
            mas[9][i] = '#';
        }
        for (i = 1; i < N - 1; i++) {
            for (j = 0; j < M; j++) {
                if (j == 0 || j == M - 1) {
                    mas[i][j] = '#';
                } else {
                    mas[i][j] = '# ';
                }
            }
        }
        mas[y][x] = '@';
        mas[ay][ax] = '*';
        system("cls"); // ������� ������
        for (i = 0 ; i < N; i++) {
            for (j = 0; j < M; j++) {
                printf("%c", mas[i][j]);
            }
            putchar('\n');
        }

        key = getch();  // ���� ������� �������

        ox = x;
        oy = y;

        switch (key) {
            case 'w':
                y--;
                break;
            case 's':
                y++;
                break;
            case 'a':
                x--;
                break;
            case 'd':
                x++;
                break;
        }
        // ��������� ������ �� ������� �����
        if (mas[y][x] == '#') {
            x = ox;
            y = oy;
        }
        // ���������� �������� ������
        if ((x == ax) && (y == ay)) {
            count_a += 1;
            ax = rand() * 1.0 / RAND_MAX * (M - 3) + 1;
            ay = rand() * 1.0 / RAND_MAX * (N - 2) + 1;
        }
    } while (key != 'e');
    printf("\nCount of collected apples is %d\n", count_a);
    return 0;
}
