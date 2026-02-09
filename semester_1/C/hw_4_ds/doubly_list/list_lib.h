#ifndef LIST_LIB_H
#define LIST_LIB_H

#define NUM_MSG "Enter the position number (from the beginning): \n"
#define VAL_MSG "Enter your value: \n"
#define DIRECT_MSG "Your list (beginning -> ending)"
#define REVERSE_MSG "Your list (ending -> beginning)"

typedef struct list
{
    int data;
    struct list *next;
    struct list *prev;
} list;

void Logic();
void Logic_interface();
void Reduce_interface();
int Input(const char*);
void Prepend(int, list**, list**);
void Append(int, list**, list**);
void Insert(list**, list**, int, int);
void Delete(list**, list**, int);
void Direct(list*);
void Reverse(list*);
void Reduce(list*);
void Concat(list**, list**);
void List_size(list*, int*);
int Reduce_func(int (*)(int, int), list *, int*);
int Sum(int, int);
int Product(int, int);
int Max(int, int);
int Min(int, int);
void Print(list*, void (*)(list*), const char*);
void Append_shad(int, list **, list **);

#endif