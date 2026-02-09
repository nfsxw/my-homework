#include "stack_lib.h"
#include <stdlib.h>
#include <stdio.h>

void Logic()
{
    stack *node = NULL;
    int n = 1;
    while(n != 0)
    {
        Interface();
        int value;
        printf("Enter your command: ");
        scanf("%d", &n);
        switch (n)
        {
            case 1:
                printf("Enter your value: \n");
                if(!(scanf("%d", &value)))
                {
                    while((scanf("%d", &value)) != 1)
                    {
                        printf("Enter your value: \n");
                        scanf("%d", &value);
                    }
                }
                Push(value, &node);
                printf("Element %d added to the stack.\n", value);
                break;
            case 2:
                Pop(&node, &value);
                break;
            case 3:
                if(node != NULL)
                {
                    printf("Stack (top -> bottom): ");
                    Print(node);
                    printf("\n");
                }
                else
                {
                    printf("Stack is empty\n");
                }
              
                break;
            case 4:
                Is_empty(node);
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

void Interface()
{
    printf("========== STACK ==========\n");
    printf("1. Add element (push)\n");
    printf("2. Delete element (pop)\n");
    printf("3. Print stack elements (print)\n");
    printf("4. Check emptiness(is_empty)\n");
    printf("0. Exit\n");
}

void Push(int value, stack **node)
{
    stack *new_node = malloc(sizeof(stack));
    new_node -> data = value;
    new_node -> next = *node;
    *node = new_node;
}

void Pop(stack **node, int *temp_value)
{
    if(*node != NULL)
    {
        int value;
        stack *temp = *node;
        value = temp -> data;
        *node = temp -> next;
        printf("Element %d is popped from the stack.\n", value);
        free(temp);
    }
    else
    {
        printf("Stack is empty!\n");
    }
}

void Print(stack *node)
{
    if(node != NULL)
    {
        printf("%d ", node -> data);
        Print(node -> next);
    }
}

void Is_empty(stack *node)
{
    if (node == NULL)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Stack is NOT empty!\n");
    }
}