#include "queue.h"

// Assumes little endian
void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;
    
    for (i = size-1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

int main(int argc, char const *argv[])
{
    Queue *q = CreateQueue(32);
    EnQueue(q,10);
    EnQueue(q,20);
    EnQueue(q,30);
    printf("Queue before DeQueue\n");
    Display(q->Front);
    DeQueue(q);
    printf("Queue after DeQueue\n");
    Display(q->Front);

    return 0;
}

