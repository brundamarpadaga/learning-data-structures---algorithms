#include "file-handler.h"
#include <stdexcept>
#include <iostream>

FileHandler::FileHandler(const std::string& filename, const std::string& mode) {
    // std::fopen is a C function that opens a file and returns a pointer to a FILE object. 
    // It takes the filename and mode (e.g., "r" for read, "w" for write) as arguments.
    
    filePtr = std::fopen(filename.c_str(), mode.c_str()); if (!filePtr) {   // .c_str() converts std::string to C-style string (const char*) which is required by std::fopen                      
        throw std::runtime_error("Failed to open file: " + filename);
    }
    std::cout << "File opened successfully (Resource Acquired).\n"; 
}

FileHandler::~FileHandler() {
    if (filePtr) {
        std::fclose(filePtr);
        std::cout << "File closed successfully (Resource Released).\n";
    }
}

void FileHandler::write(const std::string& text) {
    if (filePtr) {
        std::fputs(text.c_str(), filePtr); // fputs is c library func to write a string to file
                                           // int fputs(const char* str, FILE* stream);
    } else {
        std::cout << "Warning: Attempted to write to an unopened file.\n";
    }
}