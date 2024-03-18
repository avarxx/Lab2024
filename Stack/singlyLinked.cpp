#include "singlyLinked.h"

// Создание нового узла списка
struct Node* creatingNode(void * data, size_t elemSize) 
{ 
    // Проверка наличия данных для инициализации узла
    if (data == NULL)
    {
        printf("There is currently no data available for initializing a new node.");
        return NULL;
    }

    // Выделение памяти под структуру узла списка
    struct Node* node = (struct Node *) malloc(sizeof(struct Node));
    if (node == NULL) 
    {
        printf("Memory allocation error in creatingNode");
        return NULL;
    }
    // Выделение памяти под данные узла списка
    node->data = malloc(elemSize);
    if (node->data == NULL) 
    {
        printf("Memory allocation error in creatingNode");
        free(node); 
        return NULL;    
    // Возвращаем NULL в случае ошибки выделения памяти
    }

    // Копирование данных в узел списка
    memcpy(node->data, data, elemSize);
    node->next = NULL;  
    // Устанавливаем указатель на следующий элемент списка в NULL
    return node; 
}

// Уничтожение узла списка
void destructioNode (struct Node * node) 
{
    if (node != NULL) 
    {
        free(node -> data); // Освобождение памяти, выделенной под данные узла
        free(node);         // Освобождение памяти, выделенной для узла
    }
}


// Создание стека на основе связанного списка
struct StackLinked * stackCreatLinked(void) 
{
    // Выделение памяти под структуру стека
    struct StackLinked * stack = (struct StackLinked *) malloc(sizeof(struct StackLinked));
    if (stack == NULL) 
    {
        printf("Linked stack memory allocation failure\n");
        return NULL; 
    }
    // Возвращаем NULL в случае ошибки выделения памяти

    stack->head = NULL; // Инициализация указателя на вершину стека (голову списка)
    stack->size = 0;    // Инициализация размера стека (количество элементов)
    return stack;       // Возвращаем указатель на созданный стек
}


// Проверка параметров стека
bool checkStackLinked(struct StackLinked* stack) 
{
    if (stack == NULL)
        return false;
    else
        return true;
}



// Добавление элемента в стек
int linkedPush(struct StackLinked * stack, void * data) 
{
    // Проверка аргументов стека
    if (!checkStackLinked(stack) || data == NULL)
    {
        printf("Error with incorrect arguments to linkedPush\n");
        return 0;
    }
    // Создание нового узла списка для хранения данных
    struct Node * nodeNew = creatingNode(data, sizeof(data));
    if (nodeNew == NULL) 
    {
        printf("Memory allocation errors for a new node.\n");
        return 0; 
    }

    // Установка указателя на следующий элемент нового узла на текущую вершину стека
    nodeNew->next = stack->head;
    // Обновление указателя на вершину стека
    stack->head = nodeNew;
    // Увеличение размера стека
    stack->size++;
    return 1;
}


// Возвращает последний элемент стека на основе связанного списка
int linkedTop(struct StackLinked * stack, void * buffer) 
{
    // Проверка аргументов стека и наличия буфера
    if (!checkStackLinked(stack) || stack->size == 0 || buffer == NULL) 
    {
        printf("Error with incorrect arguments to linkedTop\n");
        return 0;
    }

    // Копирование данных из последнего узла в буфер
    memcpy(buffer, stack->head->data, sizeof(stack->head->data));
    return 1;
}


// Удаляет последний элемент стека на основе связанного списка
int linkedPop(struct StackLinked * stack) 
{

    // Проверка аргументов стека и наличия элементов в стеке
    if (!checkStackLinked(stack) || stack->size == 0) 
    {
        printf("Error with incorrect arguments to linkedPop\n");
        return 0;
    }

    struct Node *temp = stack->head;    // Сохранение указателя на вершину стека
    stack->head = stack->head->next;    // Обновление указателя на вершину стека на следующий элемент
    destructioNode(temp);               
    stack->size--;                      
    return 1; 
}

// Уничтожение стека на основе связанного списка
struct StackLinked * destructionStackLinked(struct StackLinked * stack) 
{
    // Проверка аргумента стека
    if (!checkStackLinked(stack)) 
    {
        printf("Error with incorrect arguments to destructionStack\n");
        return NULL; 
    }

    while (stack->head != NULL) 
    {
        struct Node *temp = stack->head; // Сохранение указателя на вершину стека
        stack->head = stack->head->next; // Обновление указателя на вершину стека на следующий элемент
        destructioNode(temp); 
    }
  
    free(stack); // Освобождение памяти, выделенной для структуры стека
    return NULL; 
}