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

void EnQueue(Queue *q, int value)
{
    if (q->Count < q->SizeFull)
    {
        QueueNode *tmp;
        tmp = malloc(sizeof(QueueNode));
        tmp->Data = value;
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

int DeQueue(Queue *q)
{
    QueueNode *tmp;
    int n = q->Front->Data;
    tmp = q->Front;
    q->Front = q->Front->Next;
    q->Count--;
    free(tmp);
    return(n);
}

void Display(QueueNode *head)
{
    if(head == NULL)
    {
        printf("||\n");
    }
    else
    {
        printf("%d ", head -> Data);
        Display(head->Next);
    }
}