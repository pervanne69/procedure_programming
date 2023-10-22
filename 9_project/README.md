|<p></p><p>![](Aspose.Words.0ceb35b6-0c21-4291-b864-d2e83bf4e26d.001.png)</p><p>МИНОБРНАУКИ РОССИИ</p><p></p>|
| :-: |
|<p>Федеральное государственное бюджетное образовательное учреждение</p><p>высшего образования</p><p>**«МИРЭА – Российский технологический университет»**</p><p><a name="_toc515529301"></a><a name="_toc515533522"></a><a name="_toc515541427"></a><a name="_toc515547227"></a><a name="_toc515721129"></a><a name="_toc515721286"></a><a name="_toc516321496"></a><a name="_toc516321541"></a><a name="_toc516318392"></a><a name="_toc516324462"></a><a name="_toc516412924"></a><a name="_toc516412996"></a><a name="_toc517814073"></a><a name="_toc517814245"></a><a name="_toc517814677"></a><a name="_toc517817451"></a><a name="_toc517817787"></a>**РТУ МИРЭА**</p>|
|Институт искусственного интеллекта|
|Кафедра Технологий Искусственного Интеллекта|








Практическая работа № 9

по дисциплине

«Процедурное программирование» 








Обучающийся: Погосян С. А. 

Группа: КВБО-07-23






Руководитель										*Яковлев Д. А*





Москва 2023




**Описание работы:** 

Выделите память для массива чисел и заполнить его любым способом. Создайте функцию, выполняющую задачу, указанную в варианте. Вызовите её из основной функции, получите её результат и выведите его.

**Задание:** 

![](Aspose.Words.0ceb35b6-0c21-4291-b864-d2e83bf4e26d.002.png)

**#include <stdio.h>**

**#include <time.h>**

**#include <stdlib.h>**

**#include <math.h>**

**#define N 20**


**int get\_3k(int \*ar) {**

`    `**for (int i = 0; i < N; ++i) {**

`        `**if ((abs(ar[i]) - 1) % 3 == 0) {**

`            `**printf("%3d ", ar[i]);**

`        `**}**

`    `**}**

`    `**return 0;**

**}**

**int main() {**

`    `**srand(time(NULL));**

`    `**int \*ar;**

`    `**ar = (int \*)malloc(N \* sizeof(int));**

`    `**printf("Initial Array:\n ");**

`    `**for (int i = 0; i < N; ++i) {**

`        `**ar[i] = rand() % (100 + 100 + 1) - 100;**

`        `**printf("%3d ", ar[i]);**

`    `**}**

`    `**putchar('\n');**

`    `**printf("Result array:\n");**

`    `**get\_3k(ar);**

`    `**free(ar);**

**}**

**Результат работы программы:** 

![](Aspose.Words.0ceb35b6-0c21-4291-b864-d2e83bf4e26d.003.png)

![](Aspose.Words.0ceb35b6-0c21-4291-b864-d2e83bf4e26d.004.png)


**Алгоритм в виде блок схемы:** 

![](Aspose.Words.0ceb35b6-0c21-4291-b864-d2e83bf4e26d.005.png)










**Задание:** 

![](Aspose.Words.0ceb35b6-0c21-4291-b864-d2e83bf4e26d.006.png)

**Код программы:** 

**#include <stdio.h>**

**#include <time.h>**

**#include <stdlib.h>**

**#include <math.h>**

**#define N 10**


**int get\_total(int \*ar) {**

`    `**int total = 0;**

`    `**for (int i = 0; i < N; ++i) {**

`        `**if (ar[i] % 3 == 0) {**

`            `**total += i;**

`        `**}**

`    `**}**

`    `**return total;**

**}**

**int main() {**

`    `**srand(time(NULL));**

`    `**int \*ar;**

`    `**ar = (int \*)malloc(sizeof(int) \* N);**

`    `**int total = 0;**

`    `**for (int i = 0; i < N; ++i) {**

`        `**ar[i] = rand() % 10;**

`        `**printf("%3d ", ar[i]);**

`    `**}**

`    `**total = get\_total(ar);**

`    `**printf("\ntotal = %d\n", total);**

`    `**return 0;**


**}**


**Результат работы программы:** 

![](Aspose.Words.0ceb35b6-0c21-4291-b864-d2e83bf4e26d.007.png)

![](Aspose.Words.0ceb35b6-0c21-4291-b864-d2e83bf4e26d.008.png)






**Алгоритм в виде блок-схемы:** 

![](Aspose.Words.0ceb35b6-0c21-4291-b864-d2e83bf4e26d.009.png)














**Задание:** 

![](Aspose.Words.0ceb35b6-0c21-4291-b864-d2e83bf4e26d.010.png)

**Код программы:** 

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 300

int fill\_res\_arr(int \*arr, int \*res\_arr, int \*new\_size) {
`    `int a, b, c, d, e = 0;
`    `for (int i = 0; i < N; ++i) {
`        `a = arr[i] / 10000;
`        `b = (arr[i] % 10000) / 1000;
`        `c = (arr[i] % 1000) / 100;
`        `d = (arr[i] % 100) / 10;
`        `e = arr[i] % 10;
`        `if (a + b == d + e && a + b == c) {
`            `res\_arr[\*new\_size] = arr[i];
`            `\*new\_size = \*new\_size + 1;
`        `}
`    `}

`    `return 0;
}

int main() {

`    `srand(time(NULL));


`    `int new\_size = 0;

`    `int \*arr = (int \*) malloc(sizeof(int) \* N);
`    `int \*res\_arr = (int \*) calloc(N, sizeof(int));

`    `printf("Initial Array\n\n");

`    `for (int i = 0; i < N; ++i) {
`        `arr[i] = rand() % (99999 - 10000 + 1) + 10000;
`        `printf("%d ", arr[i]);

`    `}
`    `fill\_res\_arr(arr, res\_arr, &new\_size);

`    `res\_arr = realloc(res\_arr, sizeof(int) \* new\_size);

`    `printf("\n\nResult Array\n\n");

`    `for (int i = 0; i < new\_size; ++i) {
`        `printf("%d ", res\_arr[i]);
`    `}

`    `free(arr);
`    `free(res\_arr);


`    `return 0;
}




**Алгоритм в виде блок-схемы:**

![](Aspose.Words.0ceb35b6-0c21-4291-b864-d2e83bf4e26d.011.png) **![](Aspose.Words.0ceb35b6-0c21-4291-b864-d2e83bf4e26d.012.png)**










**Результат работы программы:** 

![](Aspose.Words.0ceb35b6-0c21-4291-b864-d2e83bf4e26d.013.png)


