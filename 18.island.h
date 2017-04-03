#include <stdio.h>


typedef struct island{ //name cannot be anonymous!!!
    char *name; //if this is a name array, no need strdup(); it will make copy
    //but char * will not limit the amount of space set aside
    const char *opens;
    const char *closes;
    struct island *next;
}island;

