#ifndef FRAME_PARSER
#define FRAME_PARSER

#include<stdint.h>
#include<stdbool.h>

typedef enum {
    STATE_WAIT_SYNC,
    STATE_WAIT_LEN,
    STATE_READ_DATA,
    STATE_WAIT_CHECKSUM
} parser_state_t;


typedef struct {
    parser_state_t state;
    uint8_t  data[64];
    uint8_t  len;
    uint8_t  index;
    uint8_t  checksum;
} frame_parser_t;


// Feed one byte into the parser.
// Returns true when a complete valid frame has been received.
bool parser_feed(frame_parser_t *p, uint8_t byte);


#endif