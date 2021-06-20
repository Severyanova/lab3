## ОТЧЕТ ПО ПРАКТИЧЕСКОЙ РАБОТЕ №6
Выполнил   
Студент группы 739-1  
Северьянова А.Д.
## Введение
Цель работы: получение практических навыков по работе с бинарными деревьями. В частности нужно реализовать обходы деревьев. Также необходимо закрепить навыки по работе с динамическими структурами.  

Таблица 1 - Постановленные задачи 

| Номер | Задание |
| ------------- | ------------- |
| 1| Должны быть выполнены предыдущие работы |
|2 | Прочитать про односвязные списки на СИ |
|3| Написать программу |
|4| Настроить pipeline |
|5| Написать отчет по работе в разметке Markdown (README.md)|
|6| Залить на gitlab и убедиться, что pipeline проходит успешно|
|7| Защитить работу у преподавателя|
## 1 Теоретические сведения
### 1.1 Бинарное дерево 
Бинарное дерево — это иерархическая структура данных, в которой каждый узел имеет значение (оно же является в данном случае и ключом) и ссылки на левого и правого потомка. Узел, находящийся на самом верхнем уровне (не являющийся чьим либо потомком) называется корнем. Узлы, не имеющие потомков (оба потомка которых равны NULL) называются листьями.

Бинарное дерево поиска — это бинарное дерево, обладающее дополнительными свойствами: значение левого потомка меньше значения родителя, а значение правого потомка больше значения родителя для каждого узла дерева. То есть, данные в бинарном дереве поиска хранятся в отсортированном виде. При каждой операции вставки нового или удаления существующего узла отсортированный порядок дерева сохраняется. При поиске элемента сравнивается искомое значение с корнем. Если искомое больше корня, то поиск продолжается в правом потомке корня, если меньше, то в левом, если равно, то значение найдено и поиск прекращается.

### 1.2 Обходы дерева.

Обход дерева (известный также как поиск по дереву) — вид обхода графа, обусловливающий процесс посещения (проверки и/или обновления) каждого узла структуры дерева данных ровно один раз. Такие обходы классифицируются по порядку, в котором узлы посещаются. Алгоритмы в статье относятся к двоичным деревьям, но могут быть обобщены и для других деревьев.

## 2 Ход работы
### 2.1 Реализация программы на языке СИ

Двоичное дерево — иерархическая структура данных, в которой каждый узел имеет не более двух потомков (детей). Как правило, первый называется родительским узлом, а дети называются левым и правым наследниками. Двоичное дерево не является упорядоченным ориентированным деревом. Для практических целей обычно используют два подвида двоичных деревьев — двоичное дерево поиска и двоичная куча.

Для практических целей обычно используют два подвида двоичных деревьев — двоичное дерево поиска и двоичная куча.

Для начала необходимо создать структуру tree, а также объявить прототипы функций.

Код представлен ниже:

```c
struct tree
{
    struct tree* right;
    struct tree* left;
    int data;
};
int deep(struct tree* t);
int insert(struct tree* t, int value);
void init(struct tree** t, int value);
int print_width(struct tree* t);
}

``` 
Реализованные функий вместе с полным кодом программы находятся в приложениях А,Б и В.

Функция main является начальной точкой для выполнения программы. Она обычно управляет выполнением программы, вызывая другие ее функции. Как правило, выполнение программы завершается в конце функции main, но по разным причинам это может случиться и в других местах программы.

Главная функция main представлена ниже, для всех трех программ она аналогична меняется лишь название функции в конце поэтому дублировать нет смысла: 

```c
int main()
{
    int main()
{
    struct tree* t;
    int i;
    int value;

    scanf("%d", &value);

    init(&t, value);

    for (i = 0; i < 6; i++)
    {
        scanf("%d", &value);
        insert(t, value);
    }

    print_width(t);
    
    return 1;
}
``` 

Для начала необходимо вручную протестировать работу программы, чтобы понять есть ли какие - либо очевединые ошибки, которые необходимо исправить. Программа не выдает ошибок при запуске - это означает, что она не содержит синтаксических ошибок. Так же при вводе нескольких разных значений программа выдает ожидаемый результат. Пример работы программы представлен на рисунке 1.

![](https://sun9-38.userapi.com/impg/iKZhWMkcfidEhFw9tdeg_uB9zE6bA7NSN95I6Q/oxZ5asgv50Y.jpg?size=260x62&quality=96&sign=1416e5235e4b615c5dc732321ac3a0a1&type=album)

Рисунок 1 — Пример работы программы первой программы.

![](https://sun9-23.userapi.com/impg/cL_th1AmeDZbK6y_hGXW_mPc0eAZOG8hVqwaPg/ycWkY9cxnME.jpg?size=267x68&quality=96&sign=4df3064a6fab5e14fb2905cbe7c8a188&type=album)

Рисунок 2 — Пример работы программы второй программы.

![](https://sun9-34.userapi.com/impg/Jf3mLpRugTf0Sl-YWMEND3ZJ613MLeT2UkQVYg/SlGPO74bd6Q.jpg?size=253x67&quality=96&sign=8e89f248e71119c22ce27cc4c0e462f1&type=album)

Рисунок 3 — Пример работы программы третьей программы.

Из рисунков 1, 2, 3 видно, что программа работает корректно (выдает ожидаемый результат), а значит код написан правильно. 

#### 2.2 Тестирование разработанной программы
Pipeline — это целый набор разных команд, которые можно выполнить для проекта в рамках одной итерации.
Для тестирования разработанной программы сперва необходимо настроить pipeline, после загрузить файл с программой в систему gitlab, после чего начнется проверка разработанной программы. Результаты проверки представлены на рисунке 2.

![](https://sun9-3.userapi.com/impg/OJOquNczsiUzgLDM4aKgWOSkoIkHB7foKaKwzw/h-0uDXf_sGU.jpg?size=217x205&quality=96&sign=d63479ac130ab3134a470a12c8e198d9&type=album)

Рисунок 2 — Результаты тестирования программы.

## 3 Вывод

В результате выполнения лабораторной работы были достигнуты поставленные цели и решины необходимые задачи. Получены практические навыки работы с указателями, бинарными деревьями и динамической памятью. В частности написаны функции для работы с бинарным деревом. Реализованы обходы деревьев: прямой, обратный и в ширину.

## Приложение A

(обязательное)

Листининг кода  первой программы

#include <stdio.h>
#include <stdlib.h>

// Структура для хранения дерева.
// Хранит ссылку на корень дерева и количество элементов в дереве


// Структура для хранения узла дерева.
// Необходимо хранить ссылки на потомков, предка и некоторое значение
typedef struct node {
    int value;
    struct node *parent; //предок
    struct node *left;  //потомки
    struct node *right;
} node;
typedef struct tree {
    struct node *root;
    int count;
} tree;
// Инициализация дерева
void init(tree* t)
{
    t -> root = NULL;
    t -> count = 0;
}

// Поиск элемента по значению. Вернуть NULL если элемент не найден
node *find(tree* t, int value)
{
    node * current;
    current = t->root;

    if (t->root == NULL)
    {
        return NULL;
    }
    while (current != NULL)
    {
        if (current->value == value)
        {
            return current;
        }
        else if (value > current->value)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }
    return NULL;
}

// Вставка значения в дерево:
// 0 - вставка выполнена успешно
// 1 - элемент существует
// 2 - не удалось выделить память для нового элемента
int insert(tree* t, int value)
{
    struct node *current,*last_n = NULL;

    node* check = find(t, value);
    if (check != NULL)
    {
        return 1;
    }
    current = t->root;

    while(current!=NULL)
    {
        last_n = current;
        if(value > current -> value)
            current = current->right;
        else
            current = current->left;
    }
    current = malloc(sizeof *current);
    if (current != NULL)
    {
        current->value= value;
        current->left = NULL;
        current->right = NULL;
        current->parent = last_n;
        if(last_n != NULL)
        {
            if(current -> value < last_n -> value)
                last_n -> left = current;
            else
                last_n -> right = current;
        }

        if(t->count == 0)
        {
            t -> root = current;
        }
        t->count++;
        return 0;
    }
    else  //не удалось выделить память для нового элемента
    {
        return 2;
    }
}

int deepness(node * n, int deep){
    if (n == NULL){
        return deep;
    }
    int d1 = deepness(n->left, deep + 1);
    int d2 = deepness(n->right, deep + 1);

    if (d1 > d2)
        return d1;
    else return d2;
}

void printNode(node * n, int level, int deep) // n - корень
{
    if (level == deep)
    {
        if(n != NULL)
            printf("%d ", n->value); // вывод узлов
    }
    else if (n != NULL)
    {
        printNode(n->left, level + 1, deep);
        printNode(n->right, level + 1, deep);
    }
    else
    {
        printNode(n, level + 1, deep);
        printNode(n, level + 1, deep);
    }
}

void bfs(struct node * n)
{
    int m = deepness(n, 0); // в m записываем значение глубины дерева
    for (int i = 1; i <= m; i++)
    {
        printNode(n, 1, i); // n=n 1=level i=deep
    }
}

int main() 
{
    tree * t = malloc(sizeof(tree));
    init(t);

    for (int i = 0; i < 7; i++)
    {
        int x;
        scanf("%d", &x);
        insert(t, x);
    }
    node *n = t->root;
    bfs(n);
    return 0;
}

## Приложение Б

(обязательное)

Листининг кода  второй  программы

```c
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
struct tree
{
    struct tree* right;
    struct tree* left;
    int data;
};
int insert(struct tree* t, int value);
void init(struct tree** t, int value);
int print_direct(struct tree* t);

int main()
{
    struct tree* t;

    int value;

    int i;

    scanf("%d", &value);

    init(&t, value);

    for (i = 0; i < 6; i++)
    {
        scanf("%d", &value);
        insert(t, value);
    }

    print_direct(t);

    return 1;
}

int insert(struct tree* t, int value)
{
    if (t->data == value)
        return 1;
    if (value > (t->data))
    {
        if ((t->right) != NULL)
            return(insert(t->right, value));
        else
        {
            t->right = (struct tree*)malloc(sizeof(struct tree));

            t->right->right = NULL;

            t->right->left = NULL;

            t->right->data = value;

            return 0;
        }
    }
    else
    {
        if ((t->left) != NULL)

            return(insert(t->left, value));

        else

        {
            t->left = (struct tree*)malloc(sizeof(struct tree));

            t->left->right = NULL;

            t->left->left = NULL;

            t->left->data = value;

            return 0;
        }
    }
}
void init(struct tree** t, int value)
{
    *t = (struct tree*)malloc(sizeof(struct tree));

    (*t)->right = NULL;

    (*t)->left = NULL;

    (*t)->data = value;

}
int print_direct(struct tree* t)
{
    struct tree* current[7];
    int i = 0;
    current[0] = t;
    printf("%d", (int)current[i]->data);
    while (1)
    {
        while (1)//запись до конца
        {
            while ((current[i]->left) != NULL)
            {
            current[i + 1] = current[i]->left;
            i++;
            printf(" %d", (int)current[i]->data);
            }
            if ((current[i]->right) != NULL)
            {
            current[i + 1] = current[i]->right;
            i++;
            printf(" %d", (int)current[i]->data);
            }
            else
            break;
        }
        while ((i != 0) && ((current[i - 1]->right) == current[i]))
        i--;
        if (i == 0)
        break;
        while (i != 0)
        {
        if ((current[i - 1]->right) != NULL)
        {
        current[i] = current[i - 1]->right;
        printf(" %d", (int)current[i]->data);
        break;
        }
        else
        {
        i--;
        if (i == 0)
        return 0;
        }
    }
}
return 0;
}
```

## Приложение В

(обязательное)

Листининг кода  третий  программы

```c
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
struct tree
{
    struct tree* right;

    struct tree* left;

    int data;

};
int print_reverse(struct tree* t);
void init(struct tree** t, int value);
int insert(struct tree* t, int value);

int main()
{
    struct tree* t;

    int value;

    int i;

    scanf("%d", &value);

    init(&t, value);

    for (i = 0; i < 6; i++)
    {
        scanf("%d", &value);
        insert(t, value);
    }

    print_reverse(t);

    return 1;

}

int insert(struct tree* t, int value)
{
    if (t->data == value)

        return 1;

    if (value > (t->data))
    {
        if ((t->right) != NULL)

            return(insert(t->right, value));

        else
        {
            t->right = (struct tree*)malloc(sizeof(struct tree));

            t->right->right = NULL;

            t->right->left = NULL;

            t->right->data = value;

            return 0;
        }
    }
    else
    {
        if ((t->left) != NULL)
            return(insert(t->left, value));
        else
        {
            t->left = (struct tree*)malloc(sizeof(struct tree));

            t->left->right = NULL;

            t->left->left = NULL;

            t->left->data = value;

            return 0;
        }
    }
}

void init(struct tree** t, int value)
{
    *t = (struct tree*)malloc(sizeof(struct tree));

    (*t)->right = NULL;

    (*t)->left = NULL;

    (*t)->data = value;
}

int print_reverse(struct tree* t)
{
    if(t==NULL)
    return;
    print_reverse(t->left);
    print_reverse(t->right);
    printf("%d ",t->data);
}
```


