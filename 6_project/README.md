﻿|<p></p><p>![](Aspose.Words.2063d7b9-1efb-48c6-8b74-9fc34b43ba6b.001.png)</p><p>МИНОБРНАУКИ РОССИИ</p><p></p>|
| :-: |
|<p>Федеральное государственное бюджетное образовательное учреждение</p><p>высшего образования</p><p>**«МИРЭА – Российский технологический университет»**</p><p><a name="_toc515529301"></a><a name="_toc515533522"></a><a name="_toc515541427"></a><a name="_toc515547227"></a><a name="_toc515721129"></a><a name="_toc515721286"></a><a name="_toc516321496"></a><a name="_toc516321541"></a><a name="_toc516318392"></a><a name="_toc516324462"></a><a name="_toc516412924"></a><a name="_toc516412996"></a><a name="_toc517814073"></a><a name="_toc517814245"></a><a name="_toc517814677"></a><a name="_toc517817451"></a><a name="_toc517817787"></a>**РТУ МИРЭА**</p>|
|Институт искусственного интеллекта|
|Кафедра Технологий Искусственного Интеллекта|








Практическая работа № 6

по дисциплине

«Процедурное программирование» 








Обучающийся: Погосян С. А

Группа: КВБО-07-23






Руководитель										*Яковлев Д. А*





Москва 2023





**Тема:** 

«Обработка данных в двумерных массивах» 

**Цель лабораторной работы:** 

Целью данной лабораторной работы освоить на практике работу с двумерными массивами в языке Си.

**Описание работы:** 

Составьте и выполните программу линейной структуры согласно вариантам заданий пункта 11 и 12.

**Задание:** 

![](Aspose.Words.2063d7b9-1efb-48c6-8b74-9fc34b43ba6b.002.png)

**Код программы:** 

#define N 10

#define M 20

#include <stdio.h>

#include <time.h>

#include <stdlib.h>

int main()

{

`    `srand(time(NULL));

`    `int array[N][M];

`    `int array\_result[N];

`    `int total;

`    `printf("Matrix:\n\n");

`    `for (int i = 0; i < N; ++i) {

`            `total = 0;

`        `for (int j = 0; j < M; ++j) {

`            `array[i][j] = rand() % 10;

`            `total += array[i][j];

`            `printf("%d  ", array[i][j]);

`        `}

`        `printf("\n\n");

`        `array\_result[i] = total;

`    `}

`    `printf("<Vector> ");

`    `for (int i = 0; i < N; ++i) {

`        `printf("%d ", array\_result[i]);

`    `}

`    `return 0;

}

**Алгоритм в виде блок-схемы:** 


![](Aspose.Words.2063d7b9-1efb-48c6-8b74-9fc34b43ba6b.003.png)

![](Aspose.Words.2063d7b9-1efb-48c6-8b74-9fc34b43ba6b.004.png)




**Результат работы программы:** 

![](Aspose.Words.2063d7b9-1efb-48c6-8b74-9fc34b43ba6b.005.png)


**Задание:** 

![](Aspose.Words.2063d7b9-1efb-48c6-8b74-9fc34b43ba6b.006.png)






**Код программы:** 

**#define N 4**

**#define M 4**

**#include <stdio.h>**

**#include <stdlib.h>**

**int main()**

**{**

`    `**srand(time(NULL));**

`    `**int array[N][M], array\_result[N][M];**

`    `**int array\_1[2] = {0, 0};**

`    `**int array\_2[2] = {0, 0};**

`    `**int maxi = -11, mini = 11;**

`    `**int total1 = 0, total2 = 0;**

`    `**printf("Initial Matrix: \n\n");**

`    `**for (int i =0; i < N; ++i) {**

`        `**for (int j = 0; j < M; ++j) {**

`            `**array[i][j] = rand() % (10+10+1) - 10;**

`            `**printf("%d  ", array[i][j]);**

`            `**if (i < (N / 2) && j < (M / 2)) {**

`                    `**total1 += array[i][j];**

`                    `**if (maxi < array[i][j]) {**

`                        `**maxi = array[i][j];**

`                        `**array\_1[0] = i;**

`                        `**array\_1[1] = j;**

`                    `**}**

`                `**} if (i >= (N / 2) && j >= (M / 2)) {**

`                    `**total2 += array[i][j];**

`                    `**if (array[i][j] < mini) {**

`                        `**mini = array[i][j];**

`                        `**array\_2[0] = i;**

`                        `**array\_2[1] = j;**

`                    `**}**

`                `**}**

`        `**}**

`        `**printf("\n\n");**

`    `**}**

`    `**printf("\n\nMaxi = %d, Mini = %d, total1 = %d, total2 = %d\n\n", maxi, mini, total1, total2);**

`    `**printf("Maxi coordinate: %d %d \n\n", array\_1[0], array\_1[1]);**

`    `**printf("Mini coordinate: %d %d \n\n", array\_2[0], array\_2[1]);**

`    `**printf("Result Matrix: \n\n");**

`    `**for (int i = 0; i < N; ++i) {**

`        `**for (int j =0; j < M; ++j) {**

`            `**array\_result[i][j] = array[i][j] + total1 + total2;**

`            `**printf("%d  ", array\_result[i][j]);**

`        `**}**

`        `**printf("\n\n");**

`    `**}**

`    `**return 0;**

**}**








**Алгоритм в виде блок-схемы:** 

![](Aspose.Words.2063d7b9-1efb-48c6-8b74-9fc34b43ba6b.007.png)

![](Aspose.Words.2063d7b9-1efb-48c6-8b74-9fc34b43ba6b.008.png)

**Результат работы программы:** 

![](Aspose.Words.2063d7b9-1efb-48c6-8b74-9fc34b43ba6b.009.png)

**Контрольные вопросы:** 

1. **Как объявить и инициализировать двумерный массив в языке Си?**

Перед использованием, двумерный массив, так же как и любую переменную в программе необходимо объявить и инициализировать, то есть присвоить первоначальное значения его элементам. 

**Сначала указывается тип данных**, в которые будут храниться в массиве, затем имя массива, а потом в квадратных скобках размерность массива. 

**Размерность массива** - это максимальное количество элементов, которое можно разместить в массиве. 

Поскольку массив двумерный, то в квадратных скобках указывается оба измерения **[мах\_строк][мах\_столбцов]** после имени массива, то есть максимальное количество строк и максимальное количество столбцов из которых состоит массив. 

**тип имя\_массива[количество строк][количество столбцов]**

1. **Как получить доступ к элементам двумерного массива?**

Доступ к элементам массива осуществляется по индексу - порядковому номеру элемента. 

Нумерация в языке Си начинается с нуля, поэтому первый элемент двумерного массива имеет индекс [ноль][ноль], а последний [размерность -1][ размерность -1]. В качестве первой размерности двумерного массива всегда указывается номер строки, а в качестве второй размерности номер столбца. 



1. **Как организовать просмотр элементов двумерного массива?** 

Чтобы получить доступ к элементу, стоящему в i-той строке и в j-том столбце в массиве array, надо написать array[i][j]. Вообще же это, будет (i+1)(j+1) элемент в массиве, так как нумерация начинается с нуля. С элементами массива можно проводить все те же операции, которые применимы к обычным переменным, например присваивание.


1. Как напечатать значения элементов матрицы по строкам? 

Допустим есть массив array, размерность которого N \* M. Нужно проитерировать массив двумя циклами, а именно: 

`	`For (int i = 0; I < N; ++i) {

`		`For (int j = 0; j < M; ++j) {

`			`Printf(“%d”, array[j][i])

}

}

1. Как напечатать значения элементов матрицы по столбцам?

Допустим есть массив array, размерность которого N \* M. Нужно проитерировать массив двумя циклами, а именно: 

`	`For (int i = 0; I < N; ++i) {

`		`For (int j = 0; j < M; ++j) {

`			`Printf(“%d”, array[i][j])

}}

1. Как организовать цикл, чтобы присвоить элементы одного массива другому?

Матрицы должны иметь одинаковую размерность!

for (int i = 0; i < 10; ++i)

`   `array1[i] = array2[i]






