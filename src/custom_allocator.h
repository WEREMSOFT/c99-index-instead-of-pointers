#include <stdint.h>
#include <stdlib.h>

typedef struct
{
    char data[100];
} MemDataHolder;

typedef union
{
    int32_t nextIndex;
    MemDataHolder bucket;
} MemBucket;

static MemBucket *arena;
static int32_t lastFreeBucketIndex = 0;

void initAllocator(unsigned long numElements)
{
    arena = (MemBucket *)calloc(numElements, sizeof(MemBucket));

    for (int i = 0; i < numElements; i++)
    {
        arena[i].nextIndex = i + 1;
    }

    arena[numElements - 1].nextIndex = -1;
}

int32_t customMalloc(size_t size)
{
    int32_t returnValue = lastFreeBucketIndex;
    lastFreeBucketIndex = arena[lastFreeBucketIndex].nextIndex;
    return returnValue;
}

void customFree(int index)
{
}
