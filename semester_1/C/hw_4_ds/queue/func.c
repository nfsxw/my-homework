#include "queue_lib.h"
#include <stdlib.h>
#include <stdio.h>

void Logic()
{
    queue *front = NULL;
    queue *rear = NULL;
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
                Enqueue(value, &front, &rear);
                printf("Element %d added to the queue.\n", value);
                break;
            case 2:
                Dequeue(&front, &value);
                break;
            case 3:
                if(front != NULL)
                {
                    printf("Queue (beginning -> ending): ");
                    Print(front);
                    printf("\n");
                }
                else
                {
                    printf("Queue is empty\n");
                }
                break;
            case 4:
                Is_empty(front);
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
    printf("1. Add element (enqueue)\n");
    printf("2. Delete element (dequeue)\n");
    printf("3. Print queue elements (print)\n");
    printf("4. Check emptiness(is_empty)\n");
    printf("0. Quit\n");
}

void Enqueue(int value, queue **front, queue **rear)
{
    queue *new_node = malloc(sizeof(queue));
    new_node -> data = value;
    new_node -> next = NULL;

    if(*rear == NULL)
    {
        *front = new_node;
        *rear = new_node;
    }
    else
    {
        (*rear) -> next = new_node;
        *rear = new_node;
    }
    
}

void Dequeue(queue **front, int *temp_value)
{
    if(*front != NULL)
    {
        int value;
        queue *temp = *front;
        value = temp -> data;
        *front = temp -> next;
        printf("Element %d is dequeued.\n", value);
        free(temp);
    }
    else
    {
        printf("Queue is empty!\n");
    }
}

void Print(queue *front)
{
    if(front != NULL)
    {
        printf("%d ", front -> data);
        Print(front -> next);
    }
}

void Is_empty(queue *front)
{
    if (front == NULL)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Queue is NOT empty!\n");
    }
}