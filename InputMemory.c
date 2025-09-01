#include <stddef.h>    /*size_t*/
#include <sys/types.h> /*ssize_t is a long int*/
#include <stdio.h>

typedef struct {
    char *  charPointerCommand;
    size_t  memoryLength;
    ssize_t inputLength;
} InputMemory;


InputMemory newInputMemory() {

    InputMemory inputMemory;
    inputMemory.charPointerCommand = NULL;
    inputMemory.memoryLength = 0;
    inputMemory.inputLength  = 31;

    return inputMemory;

}


void printPrompt() {printf("database > ");}

void readInput(InputMemory inputMemory) {




}






int main() {

    InputMemory inputMemory = newInputMemory();

    printPrompt();

    printf("%ld\n", inputMemory.inputLength);

}

















