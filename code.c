// i2c write - recieve an address of the register , and then the data

clk = 1
data = 1



int i2cWrite(uint32_t *devAddrs, uint32_t* regAddrs,uint32_t data, size_t size) // dont use address (local) address size

    // send a start bit
    // send teh address intending which device
    // r/w but appended by i2cWrite
    // send stop

    // start bit
    // data bytes - size bytes 
    // stop


    
    if( clk == 1){
        data = 0; // start bit
    }

    

    for ( int i = 7; i >= 0; i--){
        bit = (*devAddrs>>i) & 1U; // masking LSB 0x10  001 0000
        *devAddrs = *devAddrs >> 1; // a register 

    }

    for (int j = 7 ; i>= 0; i--){
        for(int j = 0; j< size ; j++{
            // 
        }
    }


}