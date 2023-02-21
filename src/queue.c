#include "queue.h"

Queue* CreateQueue(int depth)
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
    q->SizeFull = depth;
	q->Front = q->Rear = NULL;
	return q;
}

bool IsEmpty(Queue *q)
{
    return (q->Rear == NULL);
}

void EnQueue(Queue *q, void *data)
{
    if (q->Count < q->SizeFull)
    {
        QueueNode *tmp;
        tmp = malloc(sizeof(QueueNode));
        tmp->Data = data;
        tmp->Next = NULL;
        if(!IsEmpty(q))
        {
            q->Rear->Next = tmp;
            q->Rear = tmp;
        }
        else
        {
            q->Front = q->Rear = tmp;
        }
        q->Count++;
    }
    else
    {
        printf("List is full\n");
    }
}

void* DeQueue(Queue *q)
{
    QueueNode *tmp;
    void* ret = q->Front->Data;
    tmp = q->Front;
    q->Front = q->Front->Next;
    q->Count--;
    free(tmp);
    return(ret);
}