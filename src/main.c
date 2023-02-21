#include "queue.h"

int* allocate_int(int value)
{
    int* num = (int*)malloc(sizeof(int));
    if(num) (*num) = value;
    return num;
}

void Display(QueueNode *head)
{
    if(head == NULL)
    {
        printf("||\n");
    }
    else
    {
        printf("%d ", (*(int*)(head -> Data)));
        Display(head->Next);
    }
}

int main(int argc, char const *argv[])
{
    Queue *q = CreateQueue(32);
    EnQueue(q, allocate_int(20));
    EnQueue(q, allocate_int(33));
    EnQueue(q, allocate_int(44));
    printf("Queue before DeQueue\n");
    Display(q->Front);
    DeQueue(q);
    printf("Queue after DeQueue\n");
    Display(q->Front);

    return 0;
}

