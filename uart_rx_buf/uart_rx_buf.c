#include<stdio.h>
#include <stdint.h>
#include "uart_rx_buf.h"
#include <stdbool.h> 



/* Called from UART RX ISR — writes one received byte */
void uart_rx_push(uart_rx_buf_t *rb, uint8_t byte){

    if( rb->head - rb->tail == RX_BUF_SIZE-1){
        printf("RX buffer is full \n");
        return;
    }
    rb->buf[rb->head & (RX_BUF_SIZE-1)] = byte;
    rb->head++;


}

/* Called from main loop — reads one byte, returns false if empty */
bool uart_rx_pop(uart_rx_buf_t *rb, uint8_t *out){
    if(rb->tail == rb->head){
        printf("buffer empty, cannot pop! \n");
        return false;
    }

    *out = rb->buf[rb->tail & (RX_BUF_SIZE-1)];
    rb->tail++;
    return true;

}

/* Returns number of bytes available to read */
uint32_t uart_rx_available(uart_rx_buf_t *rb){
    return (rb->head - rb->tail + 1);
}

int main(){

    uart_rx_buf_t uart_buffer = {0};

    uint8_t out;

    // Test 1: pop from empty buffer
    printf("Test 1: pop from empty ---\n");
    printf("pop returned: %s\n", uart_rx_pop(&uart_buffer, &out) ? "true" : "false");

    // Test 2: basic push/pop round-trip
    printf(" Test 2: push 'A','B','C' then pop all ---\n");
    uart_rx_push(&uart_buffer, 'A');
    uart_rx_push(&uart_buffer, 'B');
    uart_rx_push(&uart_buffer, 'C');
    printf("available: %u\n", uart_rx_available(&uart_buffer));
    while (uart_rx_pop(&uart_buffer, &out))
        printf("popped: %c\n", out);

    // Test 3: fill buffer completely, then push one more (should be dropped)
    printf(" Test 3: fill to capacity, push one more ---\n");
    for (int i = 0; i < RX_BUF_SIZE; i++)
        uart_rx_push(&uart_buffer, (uint8_t)i);

    printf("available after filling: %u\n", uart_rx_available(&uart_buffer));
    uart_rx_push(&uart_buffer, 0xFF);  // should be dropped
    printf("available after overflow push: %u\n", uart_rx_available(&uart_buffer));

    // Test 4: wrap-around — drain half, push more, verify order
    printf(" Test 4: wrap-around ---\n");
    for (int i = 0; i < 32; i++)
        uart_rx_pop(&uart_buffer, &out);
    printf("available after draining half: %u\n", uart_rx_available(&uart_buffer));
    for (int i = 0; i < 32; i++)
        uart_rx_push(&uart_buffer, (uint8_t)(100 + i));
    printf("available after refilling: %u\n", uart_rx_available(&uart_buffer));
    // verify head wrapped past index 63
    printf("head=%u tail=%u (head slot in buf: %u)\n",
           uart_buffer.head, uart_buffer.tail,
           uart_buffer.head & (RX_BUF_SIZE - 1));

    // Test 5: drain completely
    printf("Test 5: drain all ---\n");
    uint32_t count = 0;
    while (uart_rx_pop(&uart_buffer, &out)) count++;
    printf("drained %u bytes, available now: %u\n", count, uart_rx_available(&uart_buffer));

    return 0;


}