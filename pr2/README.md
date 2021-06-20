### 1 Введение

Задание:

1.Должна быть выполнена 1 практическая работа

2.Написать программы в соответствии с вариантом 

3.Настроить pipeline

4.Составить блок-схемы программ

5.Написать отчет по работе в разметке Markdown (README.md)

6.Загрузить на gitlab и убедиться, что проверка pipeline проходит успешно

7.Защитить работу у преподавателя

Задания на первую практическую работу представлены в таблице 1.

Таблица 1 - Задани
| Номер | Задание |
| ------------- | ------------- |
|  1  | Написать программу, которая находит минимум.  |
| 2  | Написать программу, которая вычисляет невозрастающую последовательность. |

### 2 Ход работы
#### 2.1 Работа с кодом
С помощью онлайн компилятора были написаны коды, которые представлены ниже.
Код для программы №1, соответствующий 1 заданию из вариантов, выглядит следующим образом:
```с
#include <stdio.h>

int main()
{
int n = 0, i = 0;
double x = 0, min = 0;

if ((scanf("%d", &n) == 1))
{
for (i = 0; i < n; i++)
{
if (scanf("%lf", &x) == 1)
{
if(i == 0)
{
min = x;
}

if(x < min)
{
min = x;
}
}
else
{
printf("Ошибка ввода\n");
break;
}
}
printf("%lf\n",min);
}
else
{
printf("Ошибка ввода\n");
}

return 0;
}
 
```
Результат работы программы №1 представлен на рисунке 1.

<p align="center">  
<img width="450" height="250" src="https://sun9-73.userapi.com/impg/7WDbNZyjypH8BccKTkSoxt0lmIxSpJ7xJhlBSw/iLzLS9QfUTQ.jpg?size=515x271&quality=96&sign=aae3f2dca6a2b14f9feef08324362a27&type=album"
</p>

Рисунок 1 — Результат работы программы №1

Код для программы №2, соостветствующий 11 варианту заданий, выглядит следующим образом:
```с
#include <stdio.h>
int main()
{
int n, i = 1, a = 1;
double x, x1;
(void)scanf("%d", &n);
(void)scanf("%lf", &x);
if(n>1)
{
for(i;i<n;i++)
{
(void)scanf("%lf",&x1);
if(x > x1)
{
a = 0;
break;
}
x = x1;
}
printf("%d", a);
}
else
{
printf("Ошибка ввода");
}
return 0;
}
```
Результат работы программы №2 представлен на рисунке 2.


<p align="center">  
<img width="450" height="250" src="https://sun9-57.userapi.com/impg/86h1LtlysFIdODwJGR9pX8_x5xpf5oIuv7WdIA/Q75RACo2ZXo.jpg?size=510x211&quality=96&sign=97d63af539dae273199360010894ee91&type=album"
</p>


Рисунок 2 — Результат работы программы №2

#### 2.2 Настройка pipeline

Для корректной загрузки файлов на удаленный репозиторий в файле .gitlab_cy.yml наужно найти пункт stages и добавить pr2. Далее все места, где написано \<NN> заменить на номера программ в разделе, где описываются программы второй практической работы. На рисунке 5 представлено то, как это должно выглядеть. 

<p align="center">  
<img width="400" height="400" src="https://sun9-32.userapi.com/impg/eCSt0gVh1RlGFEKYzhVgoMA0RHzl6KKc35WfYQ/ovuL6l396Z8.jpg?size=599x717&quality=96&sign=5deaf44adf3742ba8a552f06885627bb&type=album"
</p>

Рисунок 5 — Настройка pipeline
#### 2.3 Работа с GitLab

После написания кодов необхожимо загрузить файлы в локальные проект, а затем загрузить их на удаленный репозиторий с помощью CLion.
После загрузки проекта он должен пройти pipeline проверку. Результаты проверки представлены на рисунке 6.


<p align="center">  
<img width="400" height="400" src="https://psv4.userapi.com/c536132/u224943784/docs/d51/5b50e60d95e2/1111.png?extra=9Pl0GFNXoSX8VDnrpeCeGLwDtEXcauxTf529GZIFsQK4ODn1iX17OLjI-BnEKQrEOhmIWayc8ARXp60UZqG8UGp1Cyfnd_03FguWzMLxEhTL1JZ4o_eSe8jpSJAoIDAvSmCrt2Tt25y3IiXmERg3D4-m"
</p>

Рисунок 6 — Результаты pipeline-проверки

#### 2.3 Составление блок-схем
Создадим блок схемы для программ (рисунок 4,5)

<p align="center">  
<img width="400" height="800" src="https://sun4-10.userapi.com/impg/Z8oVSZyUvopSHUopzUQGVCl9N-i3Mtz_59isgw/qU7029FOxCg.jpg?size=349x881&quality=96&sign=70e44835d33892dde231f83e74f52ebc&type=album"
</p>


Рисунок 7 — Блок схема для первой программы

<p align="center">  
<img width="400" height="800" src="https://psv4.userapi.com/c537232/u158331155/docs/d21/1028d643bda9/Untitled_Diagram_2.png?extra=yw1dEqANbPyxTxzpcQ4R-OEOgjTV1izq9BLhxjxuBWaVg5L7BcrWoLir2kWnOxu4j8k9QN6j4uckc6mI5xeQfVSElw6lGB2yJ2AlWlYfaLKb-w1joZQZhhf023ugESqA3KJ1KTRaC4wOmPLxzOt3K2AR"
</p>


Рисунок 8 — Блок схема для второй программы
### 3 Заключение
В ходе выполнения практической работы были разработаны две программы на языке C, которые прошли pipeline тестирование.




