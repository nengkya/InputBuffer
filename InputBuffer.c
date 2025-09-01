/*
buffer is a memory area

size_t is an unsigned integer.
it can only represent non-negative values (0 and positive integers).
it is suitable for representing sizes, counts, and indices, which are inherently non-negative.

You can use int or long int data types, however ssize_t is a system data type that should be used for cross-platform portability.
The fundamental types (such as 'int') can be different sizes on different implementations.
Usually what happens is the system type (in this case ssize_t) takes advantage of C's typedef feature so that the machine-specific data type size is used,
e.g. typedef signed ssize_t (this is part of SUSv3 standard data types --Single UNIX Specification).
It is good practice to use system data types, where possible, when implementing any kind of system-level programming.

*/
#include <stddef.h>    /*size_t*/
#include <sys/types.h> /*ssize_t*/
#include <stdlib.h> /*malloc()*/

typedef struct {
    char *  charPointerCommand;
    size_t  memoryLength;
    ssize_t inputLength;
} InputMemory;

InputMemory newInputMemory() {

    /*
    the error "conversion to non-scalar type requested" typically arises in C when an attempt is made to assign a pointer to a non-pointer type,
    or when a cast is applied to a non-scalar type
    (like a struct or class instance) where only scalar types (arithmetic types and pointers) are permitted for direct casting.

    a scalar refers to a data type that holds a single, indivisible (not divisible) value.
    this contrasts with aggregate types like arrays and structures, which can hold multiple values or collections of data.
    scalar types in C include:
    arithmetic types:
    these include char, short, int, long, float, double, and their signed and unsigned variations.
    these types represent numerical values, either whole numbers or floating-point numbers.
    enumeration types (enum):
    these allow you to define a set of named integer constants. While they represent a single value from a defined set, they are considered scalar.
    Pointer types:
    Pointers store memory addresses, which are single values that point to the location of other data.

    non-scalar types are data types that can hold multiple values or have an internal structure, unlike scalar types which represent a single, atomic value.
    the primary non-scalar types in c are:
    arrays:
    collections of elements of the same data type, stored contiguously in memory and accessed by an index.
    structures (struct):
    user-defined data types that group together variables of different data types under a single name.
    members of a struct are accessed using the dot operator (.).
    union:
    similar to structs, but all members share the same memory location. Only one member of a union can hold a value at any given time.
    Pointers to non-scalar types:
    while pointers themselves are considered scalar, a pointer that points to an array, struct, or union is often used to manipulate these non-scalar types.

    InputMemory inputMemory = (InputMemory)malloc(sizeof(InputMemory));
    */
    InputMemory inputMemory;
    inputMemory.charPointerCommand = NULL;
    inputMemory.memoryLength = 0;
    inputMemory.inputLength  = 0;

    return inputMemory;

}


int main() {

}
