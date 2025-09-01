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

Error Handling:
The primary distinction lies in ssize_t's explicit design for error indication through negative values.
long int does not carry this implicit meaning for error conditions.
Domain:
ssize_t is specifically for sizes, counts, and return values of I/O operations where errors need to be distinguished from valid data sizes.
long int is for general-purpose integer storage when a wider range than int is required.
Guarantees:
ssize_t is guaranteed to be able to represent the maximum size of any object, which is a stronger guarantee than long int's minimum size.
In summary:
Use ssize_t when dealing with sizes or counts that might also convey error information (e.g., return values from system calls like read() or write()).

*/
#include <stddef.h>    /*size_t*/
#include <sys/types.h> /*ssize_t is a long int*/
#include <stdio.h>

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
    inputMemory.inputLength  = 31;

    return inputMemory;

    /*
    The difference between a struct and a pointer to a struct lies in what they represent and how they are handled in memory.
    1. struct (Value Type):
       A struct directly represents a composite data type, grouping together related data members under a single name.
       When you declare a variable of a struct type, memory is allocated directly for all its members.
       Passing a struct to a function or assigning it to another struct variable results in a copy of the entire structure's data.
       Modifications to the copy within a function will not affect the original struct.
    2. pointer to a struct (Reference Type):
       A pointer to a struct is a variable that stores the memory address of a struct instance. It does not store the struct itself.
       Memory for the struct pointed to must be allocated separately (e.g., using malloc or by declaring a struct variable and taking its address).
       Passing a pointer to a struct to a function means passing only the memory address.
       This allows the function to directly access and modify the original struct's data without copying the entire structure.

    https://stackoverflow.com/questions/61600147/why-use-pointer-to-struct-and-not-use-the-struct-directly-c
    "why would I pass a variable as an argument to my function instead of just keeping it as a global variable?",
    Pointers are helpful because you can "move them around" more easily.
    Instead of having to copy over the whole stucture each time, you can just leave it where it is in memory and instead pass a pointer to it around.
    passing a pointer means you can modify "a" without having to copy it back, since the stucture resides in only one place in memory.

    book->author;
    (*book).author;

    Why Use Struct Pointers?
    You want to avoid copying large amounts of data.
    Instead of copying a whole struct, you can just pass a pointer. This makes your program faster and uses less memory.

    You want to change values inside a function.
    If you pass a pointer to a struct into a function, the function can change the original values.

    You want to create structs dynamically using memory allocation.
    With pointers, you can use malloc() to create structs while the program is running.
    */

}


int main() {

    InputMemory inputMemory = newInputMemory();

    printf("%ld\n", inputMemory.inputLength);

}

















