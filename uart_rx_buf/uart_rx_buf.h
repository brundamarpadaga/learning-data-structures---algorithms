#ifndef UART_BUF
#define UART_BUF

#include<stdbool.h>

#define RX_BUF_SIZE  64


typedef struct {
    uint8_t  buf[RX_BUF_SIZE];
    volatile uint32_t head;   /* advanced by ISR (producer) */
    volatile uint32_t tail;   /* advanced by main loop (consumer) */
} uart_rx_buf_t;


/* Called from UART RX ISR — writes one received byte */
void uart_rx_push(uart_rx_buf_t *rb, uint8_t byte);

/* Called from main loop — reads one byte, returns false if empty */
bool uart_rx_pop(uart_rx_buf_t *rb, uint8_t *out);

/* Returns number of bytes available to read */
uint32_t uart_rx_available(uart_rx_buf_t *rb);

#endif