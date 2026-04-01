#ifndef CIRC_BUFFER_H
#define CIRC_BUFFER_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 5

typedef struct packet{
    int sensor_value;
    time_t timeStamp;
    int id;
} packet_t;

typedef struct  {
    packet_t buffer[BUFFER_SIZE]; // 1 2 3 4 5 
    packet_t *head;
    packet_t *tail;
    int count;
} circular_buffer_t;

circular_buffer_t* new_circular_buffer();
packet_t* create_packet(int id);
void enqueue( circular_buffer_t *cb, packet_t *packet);
packet_t* dequeue( circular_buffer_t *cb);
void discardAtHead( circular_buffer_t *cb);
void delete_buffer(circular_buffer_t *cb);
void print_buffer(circular_buffer_t *cb);


#endif