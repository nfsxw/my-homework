#include "list_lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void Logic()
{
    list *front = NULL;
    list *rear = NULL;
    int n = 1;
    while(n != 0)
    {
        Logic_interface();
        int value, num;
        printf("Enter your command: ");
        scanf("%d", &n);
        switch (n)
        {
            case 1:
                value = Input(VAL_MSG);
                Prepend(value, &front, &rear);
                break;
            case 2:
                value = Input(VAL_MSG);
                Append(value, &front, &rear);
                break;
            case 3:
                value = Input(VAL_MSG);
                num = Input(NUM_MSG);
                Insert(&front, &rear, value, num);
                break;
            case 4:
                num = Input(NUM_MSG);
                Delete(&front, &rear, num);
                break;
            case 5:
                Print(front, Direct, DIRECT_MSG );
                break;
            case 6:
                Print(rear, Reverse, REVERSE_MSG);
                break;
            case 7:
                Reduce(front);
                break;
            case 8:
                Concat(&front, &rear);
                break;
            case 9:
                int amnt = 0; 
                List_size(front, &amnt);
                printf("List contains %d elements\n", amnt);
                break;
            case 0:
                return;
            default:
                break;
        }
        getchar();
        getchar();
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    }    
}

int Input(const char* msg)
{
    int n;
    printf(msg);
    if(!(scanf("%d", &n)))
    {
        while((scanf("%d", &n)) != 1)
        {
            printf(msg);
            scanf("%d", &n);
        }
    }
    return n;
}

void Print(list *start, void (*Func)(list*), const char *msg)
{
    if(start != NULL)
    {
        printf(msg);
        Func(start);
        return;
    }
    else
    {
        printf("List is empty\n");
        return;
    }
}

void Direct(list *front)
{
    while(front != NULL)
    {
        printf("%d ", front -> data);
        front = front -> next;
    }
}

void Reverse(list *rear)
{
    while(rear != NULL)
    {
        printf("%d ", rear -> data);
        rear = rear -> prev;
    }
}

void Logic_interface()
{
    printf("========== DOUBLY LIST ==========\n");
    printf("1. Add element to the beginning (prepend)\n");
    printf("2. Add element to the ending (append)\n");
    printf("3. Insert into position\n");
    printf("4. Delete from the position\n");
    printf("5. Show list (direct order)\n");
    printf("6. Show list (reverse order)\n");
    printf("7. Perform a reduction (reduce)\n");
    printf("8. Concatenate with another list (concat)\n");
    printf("9. Show list size (list_size)\n");
    printf("0. Quit\n");
}

void Reduce_interface()
{
    printf("========== REDUCE ==========\n");
    printf("1. Sum\n");
    printf("2. Prouct\n");
    printf("3. Max\n");
    printf("4. Min\n");
    printf("0. Quit\n");
}

void Prepend(int value, list **front, list **rear)
{
    list *new_node = malloc(sizeof(list));
    new_node -> data = value;
    new_node -> prev = NULL;
    new_node -> next = NULL;

    if(*front == NULL)
    {
        *front = new_node;
        *rear = new_node;
    }
    else
    {
        (*front) -> prev = new_node;
        new_node -> next = *front;
        *front = new_node;
    }
    printf("Element %d added to the beginning.\n", value);
}

void Append(int value, list **front, list **rear)
{
    list *new_node = malloc(sizeof(list));
    new_node -> data = value;
    new_node -> prev = NULL;
    new_node -> next = NULL;

    if(*rear == NULL)
    {
        *front = new_node;
        *rear = new_node;
    }
    else
    {
        (*rear) -> next = new_node;
        new_node -> prev = *rear;
        *rear = new_node;
    }
    printf("Element %d added to the ending.\n", value);
}

void Insert(list **front, list **rear, int value, int num)
{
    if (num <= 0)
    {
        Prepend(value, front, rear);
        return;
    }

    list *curr = *front;
    for (int i = 1; i < num && curr != NULL; i++)
    {
        curr = curr->next;
    }

    if (curr == NULL)
    {
        Append(value, front, rear);
        return;
    }

    list *new_node = malloc(sizeof(list));
    new_node->data = value;
    new_node -> prev = NULL;
    new_node -> next = NULL;

    if (curr -> prev != NULL)
    {
        (curr -> prev) -> next = new_node;
        new_node -> prev = curr -> prev;
        new_node -> next = curr;
    } 
    else
    {
        new_node -> next = curr;
        *front = new_node;
    }
    curr -> prev = new_node;

    printf("Element %d added to the position %d.\n", value, num);
}

void Delete(list **front, list **rear, int num)
{
    list *curr = *front;
    for (int i = 1; i < num && curr != NULL; i++)
    {
        curr = curr->next;
    }

    if (curr == NULL)
    {
        printf("There is no elements with this number.\n");
        return;
    }

    if (curr -> prev != NULL)
    {
        (curr -> prev) -> next = curr -> next;
    }
    else 
    {
        *front = curr -> next;
    }

    if (curr -> next != NULL)
    {
        (curr -> next) -> prev = curr->prev;
    } else 
    {
        *rear = curr -> prev;
    }

    printf("Element %d deleted.\n", curr->data);
}

void Reduce(list *front)
{
    int n = 1, value;
    while(n != 0)
    {
        Reduce_interface();
        scanf("%d", &n);
        switch (n)
        {
            case 1:
                if(Reduce_func(Sum, front, &value)) break;
                printf("Reduce by addition: %d.\n", value);
                break;
            case 2:
                if(Reduce_func(Product, front, &value)) break;;
                printf("Reduce by multiplication: %d.\n", value);
                break;
            case 3:
                if(Reduce_func(Max, front, &value)) break;
                printf("Reduce by maximum: %d.\n", value);
                break;
            case 4:
                if(Reduce_func(Min, front, &value)) break;
                printf("Reduce by minimum: %d.\n", value);
                break;
            case 0:
                return;
            default:
                break;
        }
        getchar();
        getchar();
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    }
}

int Reduce_func(int (*func)(int, int), list *first, int *value)
{
    if(first == NULL)
    {
        printf("List is empty!\n");
        return 1;
    }
    *value = first -> data;
    list *temp = first -> next;
    while(temp != NULL)
    {
        *value = func(*value, temp -> data);
        temp = temp -> next;
    }
    return 0;
}

int Sum(int a, int b)
{
    return a + b;
}

int Product(int a, int b)
{
    return a * b;
}

int Max(int a, int b)
{
    return (a > b) ? a : b;
}

int Min(int a, int b)
{
    return (a < b) ? a : b;
}

void List_size(list *front, int *amnt)
{
    while(front != NULL)
    {
        (*amnt)++;
        front = front -> next;
    }  
}

void Concat(list **front, list **rear)
{
    list *front1 = NULL;
    list *rear1 = NULL;

    printf("Enter element of your new list: \n");
    int value;
    while(scanf("%d", &value) == 1)
    {
        Append(value, &front1, &rear1);
    }

    if(front1 == NULL)
    {
        printf("New list is empty!\n");
        return;
    }

    while(front1 != NULL)
    {
        Append_shad(front1 -> data, front, rear);
        front1 = front1 -> next;
    }

    printf("Your new list is attached to the end of the old one.\n");
}

void Append_shad(int value, list **front, list **rear)
{
    list *new_node = malloc(sizeof(list));
    new_node -> data = value;
    new_node -> prev = NULL;
    new_node -> next = NULL;

    if(*rear == NULL)
    {
        *front = new_node;
        *rear = new_node;
    }
    else
    {
        (*rear) -> next = new_node;
        new_node -> prev = *rear;
        *rear = new_node;
    }
}