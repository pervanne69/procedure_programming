|<p></p><p>![](Aspose.Words.9a90204f-c362-4738-95fe-10f12dff877a.001.png)</p><p>МИНОБРНАУКИ РОССИИ</p><p></p>|
| :-: |
|<p>Федеральное государственное бюджетное образовательное учреждение</p><p>высшего образования</p><p>**«МИРЭА – Российский технологический университет»**</p><p><a name="_toc515529301"></a><a name="_toc515533522"></a><a name="_toc515541427"></a><a name="_toc515547227"></a><a name="_toc515721129"></a><a name="_toc515721286"></a><a name="_toc516321496"></a><a name="_toc516321541"></a><a name="_toc516318392"></a><a name="_toc516324462"></a><a name="_toc516412924"></a><a name="_toc516412996"></a><a name="_toc517814073"></a><a name="_toc517814245"></a><a name="_toc517814677"></a><a name="_toc517817451"></a><a name="_toc517817787"></a>**РТУ МИРЭА**</p>|
|Институт искусственного интеллекта|
|Кафедра  Технологий Искусственного Интеллекта|








Практическая работа № 13

по дисциплине

«Процедурное программирование» 








Обучающийся: Погосян С. А.

Группа: КВБО-07-23






Руководитель										*Яковлев Д. А*





Москва 2023

**Тема: «Работа с массивами. Сортировки различными способами».**

**Цель лабораторной работы:**

**Изучение работы с различными видами сортировок массивов. Работа с файловой системой.** 

**Описание работы:** 

1. **Сортировка вставками**
1. **Сортировка слиянием**

**Задание:** 

![](Aspose.Words.9a90204f-c362-4738-95fe-10f12dff877a.002.png)

![](Aspose.Words.9a90204f-c362-4738-95fe-10f12dff877a.003.png)


**Гномья сортировка**

**Код программы:** 

#include <time.h>

#include <stdio.h>

#include <stdlib.h>

int write\_to\_file\_input(FILE \*f, int \*n) {

`    `f = fopen("in.txt", "w");

`    `int current;

`    `for (int i = 0; i < (\*n); i++) {

`        `current = rand() % 21 - 10;

`        `fprintf(f, "%d\n", current);

`    `}

`    `fclose(f);

`    `return 0;

}

int read\_file\_input(FILE \*f, int \*n, int \*arr\_in) {

`    `f = fopen("in.txt", "r");

`    `for (int i = 0; i < (\*n); i++) {

`        `fscanf(f, "%d", &arr\_in[i]);

`    `}

`    `fclose(f);

`    `return 0;

}

int insertion\_sort(int \*arr\_in, int \*arr\_out\_1, int \*n) {

`    `int temp = 0;

`    `for (int i = 0; i < (\*n); i++) {

`        `arr\_out\_1[i] = arr\_in[i];

`    `}

`    `for (int i = 1; i < (\*n); i++) {

`        `for (int j = i; j > 0; j--) {

`            `if (arr\_out\_1[j] < arr\_out\_1[j - 1]) {

`                `temp = arr\_out\_1[j - 1];

`                `arr\_out\_1[j - 1] = arr\_out\_1[j];

`                `arr\_out\_1[j] = temp;

`                `temp = 0;

`            `} else {

`                `break;

`            `}

`        `}

`    `}

`    `return 0;

}

int gnome\_sort(int \*arr\_out\_2, int \*n) {

`    `size\_t i = 1; 

`    `while (i < (\*n)) {

`        `if (i == 0) {

`            `i = 1;

`        `}

`        `if (arr\_out\_2[i-1] <= arr\_out\_2[i]) {

`            `++i; 

`        `} else {



`            `long tmp = arr\_out\_2[i];

`            `arr\_out\_2[i] = arr\_out\_2[i-1];

`            `arr\_out\_2[i-1] = tmp;

`            `--i;

`        `}

`    `}

`    `return 0;

}

int write\_to\_out\_2(FILE \*f, int \*arr\_out\_2, int \*n) {

`    `f = fopen("out\_gnome.txt", "w");

`    `for (int i = 0; i < (\*n); i++) {

`        `fprintf(f, " %d ", arr\_out\_2[i]);

`    `}

`    `fclose(f);

`    `return 0;

}

int write\_to\_out\_1(FILE \*f, int \*arr\_out\_1, int \*n) {

`    `f = fopen("out\_insertion.txt", "w");

`    `for (int i = 0; i < (\*n); i++) {

`        `fprintf(f, " %d ", arr\_out\_1[i]);

`    `}

`    `fclose(f);

`    `return 0;

}

int main() {

`    `srand(time(NULL));

`    `FILE \*f = NULL;

`    `int n = 0;

`    `int temp = 0;

`    `int \*arr\_in = (int \*) calloc((n), sizeof(int));

`    `int \*arr\_out\_1 = (int \*) calloc((n), sizeof(int));

`    `int \*arr\_out\_2 = (int \*) calloc((n), sizeof(int));

`    `printf("Write the digits number: ");

`    `scanf("%d", &n);

`    `if (!n) {

`        `printf("0");

`        `return 0;

`    `} else {

`        `write\_to\_file\_input(f, &n);

`        `read\_file\_input(f, &n, arr\_in);

`        `printf("Initial Array:\n");

`        `for (int i = 0; i < n; i++) {

`            `printf("%d ", arr\_in[i]);

`        `}

`        `printf("\n\nArray insertion sort result:\n\n");

`        `insertion\_sort(arr\_in, arr\_out\_1, &n);

`        `for (int i = 0; i < n; i++) {

`            `printf("%d ", arr\_out\_1[i]);

`        `}

`        `write\_to\_out\_1(f, arr\_out\_1, &n);

`        `printf("\n\nArray gnome sort result:\n\n");

`        `for (int i = 0; i < n; i++) {

`            `arr\_out\_2[i] = arr\_in[i];

`        `}

`        `gnome\_sort(arr\_out\_2, &n);

`        `for (int i = 0; i < n; i++) {

`            `printf("%d ", arr\_out\_2[i]);

`        `}

`        `write\_to\_out\_2(f, arr\_out\_2, &n);

`    `}

`    `free(arr\_in);

`    `free(arr\_out\_1);

`    `free(arr\_out\_2);

`    `return 0;

}


**Результат работы программы:** 

![](Aspose.Words.9a90204f-c362-4738-95fe-10f12dff877a.004.png)








