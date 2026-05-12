#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <cstdio>
#include <string>

class FileHandler {
public:
    // Acquire the resource (open the file)
    FileHandler(const std::string& filename, const std::string& mode);
    
    // Release the resource (close the file)
    ~FileHandler();

    // Delete copy constructor and assignment operator!
    // We don't want two objects pointing to the same file trying to close it twice.
    FileHandler(const FileHandler&) = delete;
    FileHandler& operator=(const FileHandler&) = delete;

    void write(const std::string& text);

private:
    std::FILE* filePtr; // std::FILE* is a pointer to a FILE object, which represents an open file in C.
};



// RAII - Resource Acquisition Is Initialization 
// RAII is a programming idiom used in C++ to manage resources such as memory, file handles, and network connections.
// The idea is to tie the lifecycle of a resource to the lifetime of an object. When an object is created, it acquires the resource, 
// and when the object goes out of scope, it automatically releases the resource. 
// This helps to prevent resource leaks and ensures that resources are properly cleaned up even in the presence of exceptions.


#endif