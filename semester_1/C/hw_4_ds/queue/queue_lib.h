#ifndef QUEUE_LIB_H
#define QUEUE_LIB_H

typedef struct queue
{
    int data;
    struct queue *next;
} queue;

void Logic();
void Interface();
void Enqueue(int, queue**, queue**);
void Dequeue(queue**, int*);
void Print(queue*);
void Is_empty(queue*);

#endif