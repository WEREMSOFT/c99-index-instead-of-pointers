#include <stdint.h>
#include <stdlib.h>

typedef struct
{
    int32_t x, y;
    int32_t health;
    int32_t sprite;
    int32_t childs[5];
} GameObject;

typedef struct
{
    char data[sizeof(GameObject)];
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

void finiAlloc()
{
    free(arena);
}

int32_t customMalloc()
{
    int32_t returnValue = lastFreeBucketIndex;
    lastFreeBucketIndex = arena[lastFreeBucketIndex].nextIndex;
    return returnValue;
}

void customFree(int index)
{
    arena[index].nextIndex = lastFreeBucketIndex;
    lastFreeBucketIndex = index;
}

void *derreferenceIndex(int index)
{
    return &arena[index];
}