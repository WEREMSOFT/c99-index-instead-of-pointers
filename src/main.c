#include <stdio.h>
#include <stdlib.h>
#include "custom_allocator.h"

int main(void)
{
    initAllocator(50);

    int32_t myGameObject = customMalloc();
    int32_t myGameObject2 = customMalloc();
    int32_t myGameObject3 = customMalloc();
    int32_t myGameObject4 = customMalloc();

    GameObject *go = derreferenceIndex(myGameObject);
    go->x = 10;
    go->y = 20;
    go->health = 100;

    GameObject anotherGameObject = *((GameObject *)derreferenceIndex(myGameObject));

    printf("Gameobject health: %d\n", anotherGameObject.health);
    customFree(myGameObject);

    int32_t myAnotherGameObject = customMalloc();
    GameObject go2 = *(GameObject *)derreferenceIndex(myAnotherGameObject);
    printf("Gameobject health: %d - %d\n", go2.health, go2.x);

    printf("Hello World!!\n");
    finiAlloc();
    return 0;
}
