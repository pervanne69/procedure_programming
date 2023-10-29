|<p></p><p>![](Aspose.Words.c1354b6e-f565-4e9e-b4c6-4eab0cd706a1.001.png)</p><p>МИНОБРНАУКИ РОССИИ</p><p></p>|
| :-: |
|<p>Федеральное государственное бюджетное образовательное учреждение</p><p>высшего образования</p><p>**«МИРЭА – Российский технологический университет»**</p><p><a name="_toc515529301"></a><a name="_toc515533522"></a><a name="_toc515541427"></a><a name="_toc515547227"></a><a name="_toc515721129"></a><a name="_toc515721286"></a><a name="_toc516321496"></a><a name="_toc516321541"></a><a name="_toc516318392"></a><a name="_toc516324462"></a><a name="_toc516412924"></a><a name="_toc516412996"></a><a name="_toc517814073"></a><a name="_toc517814245"></a><a name="_toc517814677"></a><a name="_toc517817451"></a><a name="_toc517817787"></a>**РТУ МИРЭА**</p>|
|Институт искусственного интеллекта|
|Кафедра Технологий Искусственного Интеллекта|








Практическая работа № 16

по дисциплине

«Процедурное программирование» 








Обучающийся: Погосян С. А.

Группа: КВБО-07-23






Руководитель										*Яковлев Д. А*





Москва 2023

**Тема: «Функции с переменным числом аргументов»**

**Цель работы: Целью данной лабораторной работы является изучение работы с функциями, которые принимают переменное число аргументов**

**Описание работы: Составить три программы с использованием функций, которые принимают переменной число аргументов**


**Задание:** 

![](Aspose.Words.c1354b6e-f565-4e9e-b4c6-4eab0cd706a1.002.png)

**Код программы:** 

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

double difference\_of\_square(int n, ...) {
`    `double res = 0;
`    `va\_list ptr;  // Указатель va\_list
`    `va\_start(ptr, n); // Устанавливаем указатель
`    `res = pow(va\_arg(ptr, int), 2);
`    `for (int i = 1; i < n; i++) {
`        `res = res - pow(va\_arg(ptr, int), 2);  // Получаем текущее значение параметра типа int
`    `}
`    `va\_end(ptr); // Завершаем обработку параметров
`    `return res;
}

int main() {
`    `int n = 3;
`    `double result = difference\_of\_square(n, 10, 4, 5);

`    `printf("The result is: %.lf", result);

`    `return 0;

}

**Результат работы программы:** 

![](Aspose.Words.c1354b6e-f565-4e9e-b4c6-4eab0cd706a1.003.png)











**Задание:**

![](Aspose.Words.c1354b6e-f565-4e9e-b4c6-4eab0cd706a1.004.png)

**Код программы:** 

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

struct Element {
`    `int x;
`    `int y;
};

typedef struct Element Element;

double length\_of\_vector(int n, ...) {
`    `double res = 0;
`    `Element cur\_el;
`    `va\_list ptr;  // Указатель va\_list
`    `va\_start(ptr, n); // Устанавливаем указатель
`    `for (int i = 0; i < n; i++) {
`        `cur\_el = va\_arg(ptr, Element);  // Получаем текущее значение параметра типа Element
`        `res += pow(pow(cur\_el.x, 2) + pow(cur\_el.y, 2), 0.5);
`    `}
`    `va\_end(ptr); // Завершаем обработку параметров
`    `return res;
}

int main() {
`    `int n = 3;
`    `Element el1 = {1, 2};
`    `Element el2 = {2, 3};
`    `Element el3 = {3, 4};
`    `double result = length\_of\_vector(n, el1, el2, el3);

`    `printf("The result is: %lf", result);

`    `return 0;
}

**Результат работы программы:** 

![](Aspose.Words.c1354b6e-f565-4e9e-b4c6-4eab0cd706a1.005.png)






**Задание:** 

![](Aspose.Words.c1354b6e-f565-4e9e-b4c6-4eab0cd706a1.006.png)


**Код программы:** 

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>


double geom\_avg(int n, ...) {
`    `double res = 1;
`    `va\_list ptr;  // Указатель va\_list
`    `va\_start(ptr, n); // Устанавливаем указатель
`    `for (int i = 0; i < n; i++) {

`        `res \*= va\_arg(ptr, int);
`    `}
`    `res = pow(res, pow(n, -1));
`    `va\_end(ptr); // Завершаем обработку параметров
`    `return res;
}

int main() {
`    `int n = 3;
`    `double result = geom\_avg(n, 2, 4, 8);

`    `printf("The result is: %lf", result);

`    `return 0;

}

**Результат работы программы:** 

![](Aspose.Words.c1354b6e-f565-4e9e-b4c6-4eab0cd706a1.007.png)
