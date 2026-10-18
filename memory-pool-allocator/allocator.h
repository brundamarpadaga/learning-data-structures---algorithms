#ifndef ALLOCATOR_H
#define ALLOCATOR_H
#include <stdint.h>
#include<stdbool.h>

#define BLOCK_SIZE 32
#define BLOCK_COUNT 10

typedef struct {
    uint8_t  pool[BLOCK_COUNT][BLOCK_SIZE]; // 32 32 32 32 ... 32  
    bool     used[BLOCK_COUNT];
} mem_pool_t;

void*  pool_alloc(mem_pool_t *p);
void   pool_free(mem_pool_t *p, void *ptr);



#endif