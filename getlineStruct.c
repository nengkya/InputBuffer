#include <stdlib.h>
#include <stddef.h>    /*size_t*/
#include <sys/types.h> /*ssize_t is a long int*/
#include <stdio.h>

/*
It's called a "prepared statement" because the database prepares or pre-compiles a SQL statement before it's fully executed, creating an optimized template with placeholders for data.
This allows the database to parse, optimize, and plan the statement once,
and then execute it multiple times by simply sending the data to fill the placeholders, which improves performance and security. 
The Preparation Process
Application sends the statement string: An application sends the SQL statement to the database server. 
Database parses and optimizes: The database then parses the statement, checks for syntax and semantic errors, and creates an execution plan. 
Server-side object created:
    This process results in a pre-compiled template or server-side object, known as the prepared statement, that is ready for execution. 
Why This is Done
Performance:
    By preparing the statement only once, the database avoids repeated parsing, analysis,
    and optimization work each time the query is executed, leading to faster execution, especially for frequently used queries. 
Security:
    Prepared statements help prevent SQL injection vulnerabilities because they separate the SQL code from the data being inserted.
    The data is treated as literal values, not as executable code, even if it contains malicious commands. 
Efficiency:
    The data values are often sent separately from the statement itself, which can be more efficient in terms of network communication and data handling
*/
typedef enum {
    metaCommandSuccess,
    metaCommandUnrecognizedCommand
} MetaCommandResult;

typedef enum {
    prepareSuccess,
    prepareUnrecognizedCommand
} PrepareResult;


typedef struct {
    char *  charPointerCommand;
    size_t  memoryLength;
    ssize_t inputLength;
} InputMemory;


InputMemory newInputMemory() {

    InputMemory inputMemory;

    /*char * must initialize 0 (NULL) or segfault coredump will raised*/
    inputMemory.charPointerCommand = (void *)NULL;

    return inputMemory;

}


void printPrompt() {printf("database > ");}


size_t readInput(InputMemory inputMemory) {

    /*size_t getline(char ** charDoublePointerLine, size_t * allocatedCharLength, FILE * stream)*/
    size_t bytesRead = getline(&inputMemory.charPointerCommand, &inputMemory.memoryLength, stdin);

    return bytesRead;

}


int main() {

    size_t bytesRead;

    InputMemory inputMemory = newInputMemory();

    while (1) {

	printPrompt();

	bytesRead = readInput(inputMemory);

	printf("%s %ld %ld %ld\n", inputMemory.charPointerCommand, inputMemory.memoryLength, inputMemory.inputLength, bytesRead);

    }

}
