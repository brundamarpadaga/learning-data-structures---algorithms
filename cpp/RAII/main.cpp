#include<iostream>
#include "file-handler.h"


int main(){

    std::string file = "file1";
    std::string writeMode = "w";
    std::string readMode = "r";

    FileHandler fh(file,writeMode);

    fh.write("Hello!!");

    return 0;
}