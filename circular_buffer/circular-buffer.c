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
        printf(" WARNING: Queue is full, discarding oldest data: %d at %lu \n" , cb->tail->sensor_value, cb->tail->timeStamp);
        discardAtHead(cb); // delete the oldest data at head to make room for new data
    
    }
    cb->count++;
     
    if(cb->tail == cb->buffer + BUFFER_SIZE){ // if tail reaches the end of the buffer, wrap around to the start
        cb->tail = cb->buffer;
        *cb->tail = *packet;
        return;
    }
    cb->tail+=1;
    *cb->tail = *packet;
    free(packet);
}
 
//  tail -> 0 head -> 2 3 4 5 

packet_t* dequeue( circular_buffer_t *cb){
    if( cb->count == 0){
        printf(" WARNING: Cannot dequeue from empty queue! \n");
        return NULL;
    }
    if(cb->head == cb->tail){
        packet_t* result = cb->head;
        cb->head = cb->tail = cb->buffer; // head and tail point to the start of the buffer
        cb->count = 0;
        return result;
    }
    packet_t* result = cb->head;
    cb->head += 1; // move head to the next packet
    cb->count--;
    return result;
}

void discardAtHead( circular_buffer_t *cb){
    if( cb->count == 0){
        printf(" WARNING: Cannot discard from empty queue! \n");
        return;
    }
    if(cb->head == cb->tail){
        cb->head = cb->tail = cb->buffer;
        cb->count = 0;
        return;
    }
    cb->head += 1;
    cb->count--;
    return;
}

void print_buffer( circular_buffer_t *cb){
    packet_t *current = cb->buffer;
    printf("Buffer contents: \n");
    
    for(int i = 0; i < cb->count; i++){
        printf("Packet ID: %d, Sensor Value: %d, Timestamp: %lu \n", current->id, current->sensor_value, current->timeStamp);
        current++;
    }
}

void delete_buffer(circular_buffer_t *cb){
    packet_t* current = cb->head;
    for(int i = 0; i < cb->count; i++){
        packet_t* temp = current;
        free(temp);
        current++;
    }
    free(cb);

}

int main(){
    circular_buffer_t *cb = new_circular_buffer();
    for(int i = 0; i < 7; i++){
        packet_t *packet = create_packet(i);
        enqueue(cb, packet);
    }
    print_buffer(cb);
    delete_buffer(cb);
    return 0;

}
