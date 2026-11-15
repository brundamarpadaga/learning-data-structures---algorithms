/*
Every firmware has a debug CLI over UART. Function pointer tables are a core C pattern 
— expect this in interviews.

Register commands like "set", "get", "reset". Feed it strings like "set led 1", 
tokenize on spaces, look up and call the handler. Test with 3-4 commands.
*/

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

    funcPtr f = table[count].handler;

    for(int i=0; i<sizeof(line); i++){
        if
    }

}

void cmd_init(cmd_t *table, char* name, funcPtr f ){
    static int current_cmd_index = 0;

    if( current_cmd_index < NUM_COMMANDS ){
        table[current_cmd_index].name = name;
        table[current_cmd_index].handler = f;
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



    

}