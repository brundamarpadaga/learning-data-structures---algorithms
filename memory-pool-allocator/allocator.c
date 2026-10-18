#include"allocator.h"
#include<stdio.h>
#include<stdlib.h>

// Key challenge: pool_free needs to figure out which slot the pointer belongs to without storing metadata inside the block.

void*  pool_alloc(mem_pool_t *p){
    for( int i = 0; i < BLOCK_COUNT; i++){
        if(p->used[i] == false){
            p->used[i] = true;
            return (void*)&p->pool[i][0];
        }
    }
    printf("Pool cannot be allocated at this moment \n");
    return NULL;
    
}

void   pool_free(mem_pool_t *p, void *ptr){
    // address within pool boundaries check
    if( ptr > (void*)(&p->pool[0][0] + (BLOCK_COUNT * BLOCK_SIZE)) || ptr < (void*)(&p->pool[0][0])){
        printf(" WARNING: ptr does not belong to this pool! POOL COULD NOT BE FREED \n");
        return;
    }

    // address not falling on boundary check
    if( ((uint8_t*)ptr - &p->pool[0][0]) % BLOCK_SIZE != 0){
        printf(" WARNING: ptr does not point to the start of a block! POOL COULD NOT BE FREED \n");
        return;
    }

    int pool_number = ((uint8_t*)ptr - &p->pool[0][0])/ BLOCK_SIZE;

    // double free check
    if(!p->used[pool_number]){
        printf(" WARNING: block already freed \n");
        return;
    }
    p->used[pool_number] = false;
}

void print_pool(mem_pool_t *p){
    for(int i = 0; i < BLOCK_COUNT; i++){
        printf("Block %d: %s \n", i, p->used[i] ? "USED" : "FREE");
    }
}


int main(){
    static mem_pool_t pool;
    uint8_t* ptr1 = (uint8_t*)pool_alloc(&pool);
    uint8_t* ptr2 = (uint8_t*)pool_alloc(&pool);


    printf("ptr1: %p \n", ptr1);
    printf("ptr2: %p \n", ptr2);
    for ( int i = 0; i < BLOCK_SIZE; i++){
        ptr1[i] = i;
        
    }

    for ( int i = 0; i < BLOCK_SIZE; i++){
        printf(" Address: %p = %02x ", &ptr1[i], ptr1[i]); 
    }
    for ( int i = 0; i < BLOCK_SIZE; i++){
        printf(" Address: %p = %02x ", &ptr2[i], ptr2[i]); 
    }
    printf("\n");
    pool_free(&pool, ptr1);
    pool_free(&pool, ptr1);

    print_pool(&pool);

}