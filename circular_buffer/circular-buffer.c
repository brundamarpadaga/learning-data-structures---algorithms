#include "circular-buffer.h"

circular_buffer_t* new_circular_buffer(){
    circular_buffer_t* cb = (circular_buffer_t*) malloc(sizeof(circular_buffer_t));
    cb->head =  cb->tail = cb->buffer;
    cb->count = 0;
    return cb;
}

packet_t* create_packet(int id){
    packet_t *packet = (packet_t*) malloc(sizeof(packet_t));
    packet->id = id;
    packet->sensor_value = rand() % 100;
    packet->timeStamp = time(NULL);
    printf("new packet: Packet ID: %d, Sensor Value: %d, Timestamp: %lu \n", packet->id, packet->sensor_value, packet->timeStamp);
    return packet;
}


void enqueue( circular_buffer_t *cb, packet_t *packet){
    if(cb->count == BUFFER_SIZE){
        printf(" WARNING: Queue is full, discarding oldest data: %d at %lu \n" , cb->head->id, cb->head->timeStamp);
        discardAtHead(cb); // delete the oldest data at head to make room for new data and adjust the tail pointer
    
    }
    
    cb->count++;
    *cb->tail = *packet;
    cb->tail++; // move tail to the next packet
    if(cb->tail >= cb->buffer + BUFFER_SIZE){
        cb->tail = cb->buffer;
    }
    free(packet);
}
 
//  tail -> 0 head -> 2 3 4 5 
//dequeue returns the packet at the head
packet_t* dequeue( circular_buffer_t *cb){
    if( cb->count == 0){
        printf(" WARNING: Cannot dequeue from empty queue! \n");
        return NULL;
    }
    if(cb->head == cb->tail &&  cb->count == 1){
        packet_t* result = cb->head;
        cb->head = cb->tail = cb->buffer; // head and tail point to the start of the buffer
        cb->count = 0;
        return result;
    }
    packet_t* result = (packet_t*) malloc(sizeof(packet_t));
    *result = *cb->head; // copy the packet at the head
    cb->head++; // move head to the next packet
    if(cb->head >= cb->buffer + BUFFER_SIZE){
        cb->head = cb->buffer;
    }
    cb->count--;
    return result;
}

void discardAtHead( circular_buffer_t *cb){
    if( cb->count == 0){
        printf(" WARNING: Cannot discard from empty queue! \n");
        return;
    }
    cb->count--;
    cb->head++; // move head to the next packet
    if(cb->head >= cb->buffer + BUFFER_SIZE){
        cb->head = cb->buffer;
    }
    return;
}

void print_buffer( circular_buffer_t *cb){
    packet_t *current = cb->head;
    printf("Buffer contents: \n");
    
    for(int i = 0; i < cb->count; i++){
        printf("Packet ID: %d, Sensor Value: %d, Timestamp: %lu \n", current->id, current->sensor_value, current->timeStamp);
        current++;
        if(current >= cb->buffer + BUFFER_SIZE){
            current = cb->buffer;
        }
    }
    printf("\n");
    printf("Head: %d \n", cb->head->id);
    printf("Tail: %d \n", cb->tail->id);
    printf("Count: %d \n", cb->count);
    printf("\n");

}

void delete_buffer(circular_buffer_t *cb){
    free(cb);
}

int main(){
    circular_buffer_t *cb = new_circular_buffer();
    for(int i = 0; i < 10; i++){
        packet_t *packet = create_packet(i);
        enqueue(cb, packet);
    }
    print_buffer(cb);
    for(int i = 0; i < 4; i++){
        packet_t *packet = dequeue(cb);
        printf("Dequeued packet : %d \n", packet->id);
        free(packet);
    }
    print_buffer(cb);
    delete_buffer(cb);
    return 0;

}
