# Отчет по практической работе №1

## Задание

Задания на первую практическую работу представлены в таблице 1.

Таблица 1 - Задания
| Номер | Задание |
| ------------- | ------------- |
|  1  | Написать программу, печатающую в stdout фразу "Hello, World!" на отдельной строке.  |
| 2  | Написать программу, принимающую на вход два числа, разделённые пробелом, и суммирующую их. Ввод чисел производить из stdin, вывод результата - в stdout. Вводимые числа не превосходят по модулю 2147483647.  |
| 3 | Написать программу, принимающую на вход числа x и y, разделённые пробелом, и вычисляющую x в степени y. Ввод чисел производить из stdin, вывод результата - в stdout. Вводимые числа не превосходят по модулю 2147483647. Реализовывать возведение в степень через цикл/рекурсию не допускается. |
## Ход работы
На рисунке 1 представлена работа всех программ

  <img width="250" height="450" src="https://sun9-16.userapi.com/impf/-LVxJWja6go5tDQxNZaIoF2fTUXRQsSCovfOGQ/Sg49zqnUUf0.jpg?size=196x374&quality=96&sign=b0a6fc0ff9f08451d0bf3f70853cda21&type=album">

Листинг первой программы: 
```C

#include <stdio.h>

int main()
{
    printf("Hello, World");

    return 0;
}

```
На рисунке 1 представлен результат работы программы.

<p align="center">

  <img width="450" height="250" src="https://sun9-24.userapi.com/impg/IQYFv3eCMc8EpmaobJC-UkNzFMVF3Q9sYvULbg/Kik7aknws20.jpg?size=552x226&quality=96&sign=ed9d5190bb331487453aca3bd8da8265&type=album">

</p>
Рисунок 1 - Результат работы программы

Листинг кода второй программы:
```C

#include <stdio.h>

int main()
{
    double i, o, p;
    (void) scanf ("%lf %lf", &i, &o);
    p=i+o;
    printf ("%lf\n", p);
    return 0;
}
```
На рисунке 2 представлен результат работы программы.

<p align="center">

  <img width="450" height="250" src="https://sun9-52.userapi.com/impg/zrKBMiXeKDvhZNXKe286U71CGUBqAIysyUp02Q/nXWQ7HeILhg.jpg?size=428x178&quality=96&sign=eaec577e5264b31decd0c5e02db99f86&type=album">

</p>
Рисунок 2 - Результат работы программы

Листинг кода третьей программы:
```C
#include <stdio.h>
#include <math.h>

int main()
{
double i, p;
(void)scanf("%lf %lf", &i, &p);
printf("%lf\n", pow(i, p));
return 0;
}
```
На рисунке 3 представлен результат работы программы.
<p align="center">

  <img width="450" height="250" src="https://sun9-69.userapi.com/impg/QBoNeFLPmXFGnHC9CujTUzPqSadmPh12taTa0Q/EUwWVfB96yc.jpg?size=488x221&quality=96&sign=906504d4c462b898231b89a2edf583af&type=album">

</p>




## Результат
В ходе выполнения практической работы были разаработаны 3 программы. Все они выполняют свои задачи корректно, следовательно раота была выполнена правильно

