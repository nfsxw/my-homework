#ifndef STACK_LIB_H
#define STACK_LIB_H

typedef struct stack
{
    int data;
    struct stack *next;
} stack;

void Logic();
void Interface();
void Push(int, stack**);
void Pop(stack**, int*);
void Print(stack*);
void Is_empty(stack*);

#endif