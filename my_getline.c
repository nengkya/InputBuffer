#include <stdio.h>
#include <stdlib.h>

/*
size_t getline(char ** linePointer, size_t * n, FILE * stream)

linePointer: a pointer to a character pointer.
this will be updated by getline() to point to the dynamically allocated buffer containing the read line.
if *linePointer is initially NULL and *n is 0, getline() will allocate the buffer.
if a buffer is already provided, getline() will reallocate it if necessary to fit the line.

n: a pointer to a size_t variable. this will be updated by getline() to reflect the size of the allocated buffer.

stream: the input stream from which to read the line (e.g., stdin for keyboard input, or a FILE * for a file). 
*/


int main() {

    /*
    why not using char ** charDoublePointerLine ?
    you will get null in printf(%s is pointer to a char); or segfault coredump
    */
    char * charPointerLine;
    
    size_t bytesRead;

    size_t * allocatedCharLength = (size_t *)malloc(sizeof(size_t));

    printf("Enter a line of text : ");

    while (bytesRead = getline(&charPointerLine, allocatedCharLength, stdin)) {

        printf("byte read: %ld\n", bytesRead);

    }


}
