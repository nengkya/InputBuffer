#include <stdlib.h>
#include <stddef.h>    /*size_t*/
#include <sys/types.h> /*ssize_t is a long int*/
#include <stdint.h>    /*uint32_t*/
#include <stdio.h>

typedef enum {
    metaCommandSuccess,
    metaCommandUnrecognizedCommand
} MetaCommandResult;

typedef enum {
    prepareSuccess,
    prepareUnrecognizedCommand
} PrepareResult;

typedef enum {
    statementInsert,
    statementSelect
} StatementType;

typedef struct{
    uint32_t id;
    char * username, * email;
} Row;

typedef struct{
    StatementType type;
    Row rowToInsert;
} Statement;

typedef struct {
    char *  charPointerCommand;
    size_t  memoryLength;
    ssize_t inputLength;
} InputMemory;

PrepareResult prepareStatement(InputMemory * inputMemory, Statement * statement) {
}

MetaCommandResult doMetaCommand() {
}

InputMemory * newInputMemory() {
    InputMemory * inputMemory = (InputMemory *)malloc(sizeof(InputMemory));
    return inputMemory;
}

void printPrompt() {printf("database > ");}

void readInput(InputMemory * inputMemory) {
    /*size_t getline(char ** charDoublePointerLine, size_t * allocatedCharLength, FILE * stream)*/
    getline(&(*inputMemory).charPointerCommand, &(*inputMemory).memoryLength, stdin);

}


int main() {

    InputMemory * inputMemory = newInputMemory();
    Statement * statement;

    while (1) {

	printPrompt();
	readInput(inputMemory);
	printf("%s %ld %ld\n", (*inputMemory).charPointerCommand, (*inputMemory).memoryLength, (*inputMemory).inputLength);

	switch (prepareStatement(inputMemory, statement)) {
	}

    }


}

















