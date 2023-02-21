#ifndef _queue_
#define _queue_

/* header file */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* definition */
#define TRUE 1
#define FALSE 0

/* structure */
struct _QueueNode
{
    int Data;
    struct _QueueNode *Next;
};
typedef struct _QueueNode QueueNode;

struct _Queue
{
    int Count;
    int SizeFull;
    QueueNode *Front;
    QueueNode *Rear;
};
typedef struct _Queue Queue;

/* methods */
Queue* CreateQueue(int depth);
bool IsEmpty(Queue *q);
void EnQueue(Queue *q, int value);
int DeQueue(Queue *q);
void Display(QueueNode *head);

#endif