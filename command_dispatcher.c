/*
Every firmware has a debug CLI over UART. Function pointer tables are a core C pattern 
— expect this in interviews.

Register commands like "set", "get", "reset". Feed it strings like "set led 1", 
tokenize on spaces, look up and call the handler. Test with 3-4 commands.
*/

#include<string.h>
#include <stdlib.h>
#include <stdio.h>

#define NUM_COMMANDS 4
typedef void (*funcPtr)(int argc, char** argv);

typedef struct {
    const char *name;
    void (*handler)(int argc, char **argv);
} cmd_t;

void set( int argc, char **argv){
    printf("set func called\n");
}

void get( int argc, char **argv){
    printf("get func called\n");
}

void reset( int argc, char **argv){
    printf("reset func called\n");
}

void preset( int argc, char **argv){
    printf("preset func called\n");
}


void cmd_dispatch(const cmd_t *table, int count, char *line){

    printf(" size of line = %ld bytes \n", sizeof(line));

    char* tokens[20]; // array of char pointers - each pointer points to a token in the line
    int argc = 0;
    
    char** argv ; // it is a pointer to char array argv[0] = "led" argv[1] "1"

    argv = tokens; // argv points to the first element of tokens array
    tokens[argc] = strtok(line, " "); // first token is the command name
    argc++;

    while((tokens[argc] = strtok(NULL, " ")) != NULL){
        argc++;
    }

    for( int i = 0; i < count; i++){
        if(strcmp(table[i].name, tokens[0]) == 0){
            table[i].handler(argc, argv);
            return;
        }
    }
    printf(" command not found \n ");
}
    

void cmd_init(cmd_t *table, char* name, funcPtr f ){
    static int current_cmd_index = 0;

    if( current_cmd_index < NUM_COMMANDS ){
        table[current_cmd_index].name = name;
        table[current_cmd_index].handler = f;
        current_cmd_index++;
    }
    else{
        printf("TABLE INIT ERROR: new command could not be initialised! \n");
    }


}


int main(int argc, char** argv){
    
    cmd_t* cmd_table = (cmd_t*) malloc( NUM_COMMANDS * sizeof(cmd_t));

    cmd_init(cmd_table, "set", set );
    cmd_init(cmd_table, "get", get );
    cmd_init(cmd_table, "reset", reset );
    cmd_init(cmd_table, "preset", preset );

    char line[] = "set led 2"; // only char arrays can be passed to functions as pointers, not string literals because they are read-only
    printf(" size of line = %ld bytes \n", sizeof(line));
    cmd_dispatch(cmd_table, NUM_COMMANDS, line);
    char line2[] = "get led 2";
    cmd_dispatch(cmd_table, NUM_COMMANDS, line2);
    char line3[] = "reset led 2";
    cmd_dispatch(cmd_table, NUM_COMMANDS, line3);
    char line4[] = "preset led 2";
    cmd_dispatch(cmd_table, NUM_COMMANDS, line4);

    free(cmd_table);

}