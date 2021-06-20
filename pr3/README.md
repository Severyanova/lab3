# **Отчёт по третьей практической работе ТиМП**
Выполнил: 
студент гр. 739-1
Северьянова А.Д.


### Задания на практическую работу:

Реализовать программу, которая:
1. считывает количество элементов n, 0 < n <= 2147483647;
2. создает пустой список, считывает n элементов a, |a| <= 2147483647 и заносит их в список;
3. выводит содержимое списка, используя функцию print;
4. считывает k1, k2, k3 (|k| <= 2147483647) и выводит "1", если в списке существует элемент с таким значением и "0", если нет (выводить через пробел, например "1 0 1");
5. считывает m, |m| <= 2147483647 и вставляет его в конец списка;
6. выводит содержимое списка, используя функцию print;
7. считывает t, |t| <= 2147483647 и вставляет его в начало списка;
8. выводит содержимое списка, используя функцию print;
9. считывает j и x (0 < j <= 2147483647, |x| <= 2147483647) и вставляет значение x после j-ого элемента списка;
10. выводит содержимое списка, используя функцию print;
11. считывает z, |z| <= 2147483647 и удаляет первый элемент (при его наличии), хранящий значение z из списка;
12. выводит содержимое списка, используя функцию print;
13. очищает список.



### Ход работы
---
#### __1 Настройка pipeline__

Перед началом работы необходимо было настроить pipeline в файле.gitlab_ci.yml, что представлено на рисунках 1 и 2.

![pipeline](https://sun9-75.userapi.com/impg/OulRbTclOnBRhlboC6pUK8qHqDMYHVH2y_bpUw/tTIC8Cbjy9M.jpg?size=116x108&quality=96&sign=3bb6f876fa3ef4df8842c81c9f27c8ff&type=album)
>Рисунок 1 - Добавление третьей работы

![pipeline](https://sun9-15.userapi.com/impg/cwbDAX2AHdl16rZInug58skX5poCYUgis2bo8w/ewUwhPCx5rY.jpg?size=312x477&quality=96&sign=689682f78a9b7a0ead87f3cb5c955bf5&type=album)
>Рисунок 2 - Добавление тестов
---

#### __3 Программа:__

В первую очередь необходимо было определить структуры, необходимые для решения данной задачи.

```c
typedef struct node
{
    int value; // значение, которое хранит узел
    struct node *next; // ссылка на следующий элемент списка
} node;
typedef struct list
{
    struct node *head; // начало списка
} list;
```

Ниже приведены все функции, реализованные в программе.

__Инициализация пустого списка:__
```c
{
    *l = (list*)malloc(sizeof(list));
    (*l)->head = NULL;
    return;
}
```

__Удаление всех элементов из списка:__
```c
void clean(list *l)
{
    if (! l -> head)
    {
        return;
    }
    node *current = l->head;
    node *temp;
    while (current)
    {
        temp = current->next;
        free(current);
        current = temp;
    }
    l->head = NULL;
    return;
}
```
__Проверка на пустоту списка:__
```c
bool is_empty(list *l)
{
    if(l -> head == NULL)
    {
        return true;
    }
    return false;
}
```

__Поиск элемента по значению, вернуть NULL если элемент не найден:__
```c
node *find(list *l, int key)
{
    node *current = l -> head;
    if(! l -> head)
    {
        return NULL;
    }
    while(current -> value != key)
    {
        current = current -> next;
        if(current == NULL)
        {
            return NULL;
        }
    }
    return current;
}
node* FindTail(list *l)
{
    if(l -> head == NULL)
    {
        return NULL;
    }
    node *current = l -> head;
    while(current -> next != NULL)
    {
        current = current -> next;
    }
    return current;
}
```

__Вставка значения в конец списка, вернуть 0 если успешно:__
```c
int push_back(list *l, int key)
{
    if (! is_empty(l))
    {
        node *last = FindTail(l);
        node *current = malloc(sizeof(node));
        last -> next = current;
        current -> next = NULL;
        current -> value = key;
    }
    else
    {
        node *current = malloc(sizeof(node));
        current -> value = key;
        current -> next = NULL;
        l -> head = current;
    }
    return 0;
}
```

__Вставка значения в начало списка, вернуть 0 если успешно:__
```c
int push_front(list *l, int key)
{
    node *current;
    current = malloc(sizeof(node));
    current -> value = key;
    current -> next = l -> head;
    l -> head = current;
    return 0;
}
```

__Вставка значения после указанного узла, вернуть 0 если успешно:__
```c
int insert_after(node *n, int key)
{
    if(n == NULL)
    {
        return 1;
    }
    node *New = malloc(sizeof(node));
    New -> value = key;
    New -> next = n -> next;
    n -> next = New;
    return 0;
}
```

__Удаление первого элемента из списка с указанным значением, вернуть 0 если успешно:__
```c
int remove_node(list *l, int key)
{
    node *current = l -> head;
    node *previous = NULL;
    if(l -> head == NULL)
    {
        return 1;
    }
    while(current -> value != key)
    {
        if(current -> next == NULL)
        {
            return 1;
        }
        else
        {
            previous = current;
            current = current -> next;
        }
    }
    if(current == l -> head)
    {
        l -> head = l -> head -> next;
    }
    else
    {
        previous -> next = current -> next;
    }
    free(current);
    return 0;
}
```

__Вывод всех значений списка в прямом порядке через пробел, после окончания вывода перейти на новую строку:__
```c
void print(list *l)
{
    node *current = l -> head;
    if (current == NULL)
    {
        return;
    }
    while(current != NULL)
    {
        printf("%d ", current-> value);
        current = current -> next;
    }
    printf("\n");
    return;
}
void checkingexist(node *n1, node *n2, node *n3)
{
    if(n1 == NULL)
    {
        printf("0 ");
    }
    else
    {
        printf("1 ");
    }
    if(n2 == NULL)
    {
        printf("0 ");
    }
    else
    {
        printf("1 ");
    }
    if(n3 == NULL)
    {
        printf("0 ");
    }
    else
    {
        printf("1 \n");
    }
}
node *findbyindex(list *l, int index)
{
    if(l -> head == NULL)
    {
        return NULL;
    }
    node *current = l -> head;
    int i = 0;
    while(i != index)
    {
        current = current -> next;
        if(current == NULL)
        {
            return NULL;
        }
        i++;
    }
    return current;
}
```
__Метод main:__
```c
int main()
{
    int i, n, k1, k2, k3, m, t, j, x, z, a;
    (void) scanf("%d", &n);
    list *link;
    
    init(&link);
    for(i = 1; i <= n; i++)
    {
        (void) scanf("%d", &a);
        push_back(link, a);
    }
    print(link);
    (void) scanf("%d %d %d", &k1, &k2, &k3);
    node *find1 = find(link, k1);
    node *find2 = find(link, k2);
    node *find3 = find(link, k3);
    checkingexist(find1, find2, find3);
    (void)scanf("%d", &m);
    push_back(link, m);
    print(link);
    (void)scanf("%d", &t);
    push_front(link, t);
    print(link);
    (void) scanf("%d %d", &j, &x);
    node *FindNode = findbyindex(link, j - 1);
    insert_after(FindNode, x);
    print(link);
    (void) scanf("%d", &z);
    remove_node(link, z);
    print(link);
    clean(link);
    link -> head = NULL;
    return 0;
}

```

На рис. 3 представлен результат тестирования pipeline.

![Результат pipeline](https://sun9-72.userapi.com/impg/64nPl6Gr5F-bS8Jp6EbFHlorkBd8hMx9QY3KkQ/l42ue4-dx0Q.jpg?size=1099x583&quality=96&sign=bf7e96d48c794872cb46f0362230e28f&type=album)
>Рисунок 3 - Результат теста pipeline

---


### __Заключение__
В ходе данной практической работы была решена задача по теме "Односвязные списки". Реализованы все заданные структуры и функции. Написанная программа успешно прошла все тесты и проверки.
