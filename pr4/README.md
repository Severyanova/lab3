# **Отчёт по четвертой практической работе ТиМП**
Выполнил: 
студент гр. 739-1  
Северьянова А.Д.


### Задания на практическую работу:

1.считывает количество элементов n, 0 < n <= 2147483647;  
2.создает пустой список, считывает n элементов a, |a| <= 2147483647 и заносит их в список;  
3.выводит содержимое списка, используя функцию print;  
4.считывает k1, k2, k3 (|k| <= 2147483647) и выводит "1", если в списке существует элемент с таким значением и "0" если нет (выводить через пробел, например "1 0 1");  
5.считывает m, |m| <= 2147483647 и вставляет его в конец списка;  
6.выводит содержимое списка, используя функцию print_invers;  
7.считывает t, |t| <= 2147483647 и вставляет его в начало списка;  
8.выводит содержимое списка, используя функцию print;  
9.считывает j и x (0 < j <= 2147483647, |x| <= 2147483647) и вставляет значение x после j-ого элемента списка;  
10.выводит содержимое списка, используя функцию print_invers;  
11.считывает u и y (0 < u <= 2147483647, |y| <= 2147483647) и вставляет значение y перед u-ым элементом списка;  
12.выводит содержимое списка, используя функцию print;  
13.считывает z, |z| <= 2147483647 и удаляет первый элемент (при его наличии), хранящий значение z из списка;  
14.выводит содержимое списка, используя функцию print_invers;  
15.считывает r, |r| <= 2147483647 и удаляет последний элемент (при его наличии), хранящий значение r из списка;  
16.выводит содержимое списка, используя функцию print;  
17.очищает список.  


### Ход работы
---
#### __1 Настройка pipeline__

Перед началом работы необходимо было настроить pipeline в файле.gitlab_ci.yml, что представлено на рисунках 1 и 2.

![pipeline](https://sun9-54.userapi.com/impg/189ZNcraht0GE-ljGWw6hKYXTUXIObTpn2dg0g/ObC8OIYbKRE.jpg?size=128x173&quality=96&sign=bceb8ba9ae92caffba943d5a46676ce7&type=album)
>Рисунок 1 - Добавление четвертой работы

![pipeline](https://sun9-76.userapi.com/impg/JIwOqbXTbNRlooJ4Mdwm8vYiSV8R5-Gnrx-sIw/I7kgI4PdpTA.jpg?size=441x667&quality=96&sign=07547d0ad0666750d5094ba357afcb2f&type=album)
>Рисунок 2 - Добавление тестов
---

#### __3 Программа:__

Коды программ написаны с использованием IDE Visual Studio и CLion.  

 Для начала нужно создать структуры и ининициализацию. Далее,освободить память и присвоить значения для пустых узлов, а также максимальное значение данных, содержащее узел.  
 Инициализация списка представлена ниже:

```с
struct Line
{
	struct Line* Front;
	struct Line* Back;
	double Data;
};
void init(struct Line** l)//получаем значение, взятое по адресу адреса
{
	*l = (struct Line*)malloc(sizeof(struct Line));
	(*l)->Front = NULL;
	(*l)->Back = NULL;
	(*l)->Data = 2147483648;
}
```
Далее, происходит освобождение памяти для Temp.  
Ниже представлено заполение списка.

__Заполнение списка:__
```с
int push_front(struct Line** l, int value)
{
	struct Line* Temp = (struct Line*)malloc(sizeof(struct Line));//при этом здесь **l--это значение
	Temp->Data = value;//l--конкретно двойной адрес, *l--адрес блока, **l--блок
	Temp->Front = (*l);//то есть, в следующем элементе записан адрес начального эл-та списка
	Temp->Back = NULL;
	Temp->Front->Back = Temp;//указатель от прошлого первого элемента
	(*l) = Temp;//вот у нас есть список, засунутый в Temp(адрес), мы берём присваиваем адресу l адрес Temp
	return 0;
}
```
Функция print представлена ниже.
__Функция print:__
```с
void print(struct Line* l)
{
	while (l != NULL)
	{
		printf("%.0lf ", l->Data);
		l = l->Front;
	}
	printf("\n");
}
```

На рис. 3 представлен результат тестирования pipeline.

![Результат pipeline](https://sun9-40.userapi.com/impg/lvlI-U-NKE4sbeFiDGolgGsd31mC4LCb9mxydQ/tQZdM6nT4ME.jpg?size=1032x443&quality=96&sign=5d44fabebdcc9144df5e51d27ba00fd5&type=album)
>Рисунок 3 - Результат теста pipeline  
  
На рис. 4 представлен результат работы программы.    

![Результат работы программы](https://sun9-50.userapi.com/impg/fLms-D3xm-yq-dLiwWUxNLS5SzMFa19I6mh8BA/NGzJX9n3PPA.jpg?size=141x158&quality=96&sign=dff943a94abe7102db66ebde46ac49f5&type=album)
>Рисунок 4 - Результат работы программы

---


### __Заключение__
В ходе данной практической работы была решена задача по теме "Двусвязные списки". Программа успешно прошла все тесты и проверки.
### Приложение А

Листинг кода представлен ниже:  
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <malloc.h>

#include <stdbool.h>

struct Line

{

struct Line* Front;

struct Line* Back;

double Data;

};

struct Line

{

struct Line* Front;

struct Line* Back;

double Data;

};

void init(struct Line** l)//получаем значение, взятое по адресу адреса

{

*l = (struct Line*)malloc(sizeof(struct Line));

(*l)->Front = NULL;

(*l)->Back = NULL;

(*l)->Data = 2147483648;

}

void clean(struct Line* l)

{

struct Line* Temp = l;

free(Temp->Back);

do

{

Temp = Temp->Front;

free(l);

l = Temp;

} while (l != NULL);

}

bool is_empty(struct Line* l)//проверка на пустоту

{

if (l == NULL)

return 0;//0--список пуст

else

return 1;

}

struct Line* find(struct Line* l, int value)//найти элемент со значением

{

struct Line* Temp = l;

while (1)

{

if (Temp == NULL)

return NULL;

else

{

if ((Temp->Data) == value)

return ((struct Line*)l);

}

Temp = Temp->Front;

}

}

int push_back(struct Line* l, int value)//вставить в конец(0 при успехе)

{//а как может быть 1?

if (l->Data == 2147483648)

{

l->Data = value;

return 0;

}

struct Line* Temp = (struct Line*)malloc(sizeof(struct Line));

Temp = l;

while (Temp->Front != NULL)

Temp = Temp->Front;

Temp->Front = (struct Line*)malloc(sizeof(struct Line));

Temp->Front->Back = Temp;

Temp = Temp->Front;

Temp->Data = value;

Temp->Front = NULL;

return 0;

}

int push_front(struct Line** l, int value)

{

struct Line* Temp = (struct Line*)malloc(sizeof(struct Line));//при этом здесь **l--это значение

Temp->Data = value;//l--конкретно двойной адрес, *l--адрес блока, **l--блок

Temp->Front = (*l);//то есть, в следующем элементе записан адрес начального эл-та списка

Temp->Back = NULL;

Temp->Front->Back = Temp;//указатель от прошлого первого элемента

(*l) = Temp;//вот у нас есть список, засунутый в Temp(адрес), мы берём присваиваем адресу l адрес Temp

return 0;

}

int insert_after(struct Line* l, int value)//вставка на нужное место(0--успех)

{

if (l->Front != NULL)

{

struct Line* Temp = (struct Line*)malloc(sizeof(struct Line)), * Temp2;

Temp->Front = l->Front;//делаем привязки от элемента к соседним тут

Temp->Back = l;//и тут

Temp->Data = value;

l->Front->Back = Temp;//меняем указатель с последующего элемента на вставляемый

l->Front = Temp;

}

else

{

l->Front = (struct Line*)malloc(sizeof(struct Line));

l->Front->Front = NULL;

l->Front->Data = value;

l->Front->Back = l;

}

return 0;

}

int insert_before(struct Line* l, int value)//вставка на нужное место(0--успех)

{

if (l->Back != NULL)

{

struct Line* Temp = (struct Line*)malloc(sizeof(struct Line)), * Temp2;

Temp->Back = l->Back;//делаем привязки от элемента к соседним тут

Temp->Front = l;//и тут

Temp->Data = value;

l->Back->Front = Temp;//меняем указатель с последующего элемента на вставляемый

l->Back = Temp;

}

else

{

l->Back = (struct Line*)malloc(sizeof(struct Line));

l->Back->Back = NULL;

l->Back->Data = value;

l->Back->Front = l;

}

return 0;

}

int remove_first(struct Line* l, int value)//удаление(надо сделать удаление 1-го)

{

struct Line* Temp = l;

if (l != NULL)

{

while (1)

{

if ((Temp->Front) == NULL)

return 1;//не найдено

if ((Temp->Front->Data) == value)

{

Temp = Temp->Front;

if (Temp->Front != NULL)

{

Temp->Back->Front = Temp->Front;

Temp->Front->Back = Temp->Back;

free(Temp);

}

else

{

Temp->Back->Front = NULL;

free(Temp);

}

return 0;

}

Temp = Temp->Front;

}

}

else

return 1;

}

int remove_last(struct Line* l, int value)//удаление(надо сделать удаление 1-го)

{

struct Line* Temp = l, * TempSaving = NULL;

if (l != NULL)

{

while (Temp->Front != NULL)

{

if ((Temp->Front->Data) == value)

TempSaving = Temp->Front;

Temp = Temp->Front;

}

if (TempSaving != NULL)

{

if (TempSaving->Front != NULL)

{

TempSaving->Back->Front = TempSaving->Front;

TempSaving->Front->Back = TempSaving->Back;

free(TempSaving);

}

else

{

TempSaving->Back->Front = NULL;

free(TempSaving);

}

return 1;//не найдено

}

return 0;

}

else

return -1;

}

void print(struct Line* l)//вывести всё, что есть

{

while (l != NULL)

{

printf("%.0lf ", l->Data);

l = l->Front;

}

printf("\n");

}

void print_inverse(struct Line* l)//вывести всё, что есть

{

while (l->Front != NULL)

l = l->Front;

while (l != NULL)

{

printf("%.0lf ", l->Data);

l = l->Back;

}

printf("\n");

}

int main()

{

struct Line* l, * Temp;

int N, i;

double a, b;

scanf("%d", &N);//1 пункт

init(&l);//2 пункт, передаём адрес адреса

for (i = 0; i < N; i++)

{

scanf("%lf", &a);

push_back(l, a);

}

print(l);//3 пункт

for (i = 0; i < 3; i++)//4 пункт

{

scanf("%lf", &a);

if (find(l, a) == NULL)

printf("0");

else

printf("1");

if (i != 2)

printf(" ");

else

printf("\n");

}

scanf("%lf", &a);//5 пункт

push_back(l, a);

print_inverse(l);//6 пункт

scanf("%lf", &a);//7 пункт

push_front(&l, a);

print(l);//8 пункт

scanf("%lf", &a);//9 пункт, здесь a--это j, номер в списке

scanf("%lf", &b);//b--это x, само значение

struct Line* el = (struct Line*)l;

while (a != 1)

{

el = el->Front;

a--;

}

insert_after(el, b);

print_inverse(l);//10 пункт

scanf("%lf", &a);//11, a=u

scanf("%lf", &b);//b=y

if (a == 1)

{

el = (struct Line*)malloc(sizeof(struct Line));

el->Data = b;

el->Back = NULL;

el->Front = (struct Line*)l;

l->Back = (struct Line*)el;

l = l->Back;

}

else

{

el = (struct Line*)l;

while (a != 1)

{

el = el->Front;

a--;

}

insert_before(el, b);

}

print(l);//12 пункт

scanf("%lf", &a);//13 пункт

if (l->Data == a)

{

Temp = l->Front;

free(l);

l = Temp;

l->Back = NULL;

}

else

remove_first(l, a);

print_inverse(l);//14 пункт

scanf("%lf", &a);//15 пункт

if ((remove_last(l, a) == 0) && (l->Data == a))

{

Temp = l->Front;

free(l);

l = Temp;

}

print(l);//16 пункт

clean(l);//17 пункт

return 1;

}
