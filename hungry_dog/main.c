#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define N 10
#define M 21

int main() {
    // Добавить врагов
    // Добавить расширение
    // Определенное кол-во съеденных яблок - след.уровень (больше врагов через уровень)
    // зелье добавить, которое восстанавливает жихни
    srand(time(NULL));
    // Первая размерность матрица - высота, Вторая размерность матрица - ширина
    int mas[N][M];  // Карта
    int i, j;
    int current_level = 1;
    int first_level = 3, second_level = 7, third_level = 10, final_level = 20;
    int count_enemy = 1;
    char heart[] = "<3";
    int count_heart = 3;
    int x = 10, y = 5; // Начальное положение собаки
    int ox, oy;  // Координаты собаки до перемещения
    int x_old_enemy, y_old_enemy;
    int ax = 5, ay = 3;
    int x_enemy = 4, y_enemy = 3;
    int x_f_enemy, y_f_enemy;
    int x_f_old_enemy, y_f_old_enemy;
    int count_a = 0;
    char key;  // Нажатый символ

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
        mas[y_enemy][x_enemy] = '&';
        if (current_level == 4) {
            x_f_enemy = rand() * 1.0 / RAND_MAX * (M - 3) + 1;
            y_f_enemy = rand() * 1.0 / RAND_MAX * (N - 2) + 1;
            while ((x_f_enemy == x_enemy) && (y_f_enemy == y_enemy)) {
                x_f_enemy = rand() * 1.0 / RAND_MAX * (M - 3) + 1;
                y_f_enemy = rand() * 1.0 / RAND_MAX * (N - 2) + 1;
                while ((x == x_f_enemy) && (y == y_f_enemy)) {
                    x_f_enemy = rand() * 1.0 / RAND_MAX * (M - 3) + 1;
                    y_f_enemy = rand() * 1.0 / RAND_MAX * (N - 2) + 1;
                }
            }
            mas[y_f_enemy][x_f_enemy] = '&';
        }
        system("cls"); // Очистка экрана
        if (count_a == first_level) {
            if (current_level == 1) {
                current_level += 1;
            }
        } else if (count_a == second_level) {
            if (current_level == 2) {
                current_level += 1;
            }
        } else if (count_a == third_level) {
            if (current_level == 3) {
                current_level += 1;
                count_enemy += 1;
            }
        } else if (count_a == final_level) {
            printf("You're win. But i will come back...\n");
            break;
        }
        if (current_level == 1) {
            printf("First level. You must collect 3 apples\n");
        } else if (current_level == 2) {
            printf("Second level. You must collect 7 apples\n");
        } else if (current_level == 3) {
            printf("Third level. You must collect 10 apples\n");
        } else {
            printf("Final level. You must collect 20 apples\n");
        }
        for (i = 0; i < count_heart; i++) {
            printf("%s", heart);
        }
        putchar('\n');
        for (i = 0 ; i < N; i++) {
            for (j = 0; j < M; j++) {
                printf("%c", mas[i][j]);
            }
            putchar('\n');
        }
        printf("\nCount of apples = %d\n", count_a);

        key = getch();  // Ждем нажатие клавиши

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
        if (x_enemy > ax + 1) {
            x_enemy -= 1;
        } else if (x_enemy < ax - 1) {
            x_enemy += 1;
        } else if (ax == x_enemy + 1) {
            if (y_enemy > ay) {
                y_enemy -= 1;
            } else if (y_enemy < ay) {
                y_enemy += 1;
            }
        }
        // Обработка выхода за границу карты
        if (mas[y][x] == '#') {
            x = ox;
            y = oy;
        }
        if ((x == x_enemy) && (y == y_enemy)) {
            if ((count_heart - 1) == 0) {
                count_heart -= 1;
                printf("You're dead(\n");
                break;
            } else {
                x_old_enemy = x_enemy;
                y_old_enemy = y_enemy;
                while ((x_old_enemy == x_enemy) && (y_old_enemy == y_enemy)) {
                    x_enemy = rand() * 1.0 / RAND_MAX * (M - 3) + 1;
                    y_enemy = rand() * 1.0 / RAND_MAX * (N - 2) + 1;
                    while ((x == x_enemy) && (y == y_enemy)) {
                        x_enemy = rand() * 1.0 / RAND_MAX * (M - 3) + 1;
                        y_enemy = rand() * 1.0 / RAND_MAX * (N - 2) + 1;
                    }
                }
                count_heart -= 1;
            }
        }
        if (current_level == 4) {
            if ((x_f_enemy == x) && (y_f_enemy == y))
            x_f_old_enemy = x_enemy;
            y_f_old_enemy = y_enemy;
            while ((x_f_old_enemy == x_f_enemy) && (y_f_old_enemy == y_f_enemy)) {
                x_f_enemy = rand() * 1.0 / RAND_MAX * (M - 3) + 1;
                y_f_enemy = rand() * 1.0 / RAND_MAX * (N - 2) + 1;
                while ((x == x_f_enemy) && (y == y_f_enemy)) {
                    x_f_enemy = rand() * 1.0 / RAND_MAX * (M - 3) + 1;
                    y_f_enemy = rand() * 1.0 / RAND_MAX * (N - 2) + 1;
                }
            }
        }
        // Реализация поедания яблока
        if ((x == ax) && (y == ay)) {
            count_a += 1;
            while ((x == ax) && (y == ay)) {
                ax = rand() * 1.0 / RAND_MAX * (M - 3) + 1;
                ay = rand() * 1.0 / RAND_MAX * (N - 2) + 1;
                while ((ax == x_enemy) && (ay == y_enemy)) {
                    ax = rand() * 1.0 / RAND_MAX * (M - 3) + 1;
                    ay = rand() * 1.0 / RAND_MAX * (N - 2) + 1;
                }
                if (current_level == 4) {
                    while ((ax == x_f_enemy) && (ay == y_f_enemy)) {
                        ax = rand() * 1.0 / RAND_MAX * (M - 3) + 1;
                        ay = rand() * 1.0 / RAND_MAX * (N - 2) + 1;
                    }
                }

            }
        }
    } while (key != 'e');
    printf("\nCount of collected apples is %d\n", count_a);
    getchar();
    return 0;
}
