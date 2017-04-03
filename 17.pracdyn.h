#include <stdio.h>


typedef struct island{ //name cannot be anonymous!!!
    char *name; //if this is a name array, no need strdup(); it will make copy
    //cannot free const char* because they are string literal in the constant memory area, not heap
    //but char * will not limit the amount of space set aside
    const char *opens;
    const char *closes;
    struct island *next;
}island;

