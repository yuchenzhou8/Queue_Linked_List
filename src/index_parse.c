#include "queue.h"
#include <time.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>

// Assumes little endian
void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    uint8_t bit;
    ssize_t i, j;

    for (i = size-1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            bit = (b[i] >> j) & 1;
            printf("%u", bit);
        }
    }
}


Queue* CreateIndexQueue(unsigned int num, unsigned int max_depth)
{
	Queue *q = CreateQueue(max_depth);

	unsigned char *b = (unsigned char*) &num;
    ssize_t i, j;

    for (i = 0; i <= 3; i++) {
        for (j = 0; j <= 7; j++) {
            if((b[i] >> j) & 1){
            	EnQueue(q, 8 * i + j);
            }
        }
    }
    return q;

}


int main(int argc, char const *argv[])
{
	
	srand(time(NULL));

	unsigned int num = rand()%UINT_MAX;
	printf("num: %d: \n", num);
	printBits(sizeof(num), &num);
	printf("\n");
	Queue* q = CreateIndexQueue(num, 32);
	if(q)
	{
		Display(q->Front);
	}

	return 0;
}