#include <stdio.h>

struct string {
    char * charPointer;
};


struct string processString(struct string stringParameter) {

    stringParameter.charPointer = "inside";

    return stringParameter;

}

int main() {

    struct string myString;

    myString.charPointer = "test";

    myString = processString(myString);

    printf("%s\n", myString.charPointer);

}
