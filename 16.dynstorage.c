//DYNAMIC STORAGE

//most declared memory are local; used in the stack

//STACK
//  - stack is the area of memory used for local variables
//    data stored in a variable disappears when it leaves the function
//    it is hard to get more storage on the stack @ runtime
//HEAP
//  - heap is the place where a proram stores data that will need to be available longer term
//    will not automatically clear like var stored in the stack memory
//    good place to store data structures


//How to allocate space on heap?

//MALLOC()
//  - intake how much memory spaces needed
//    OS will set the memory aside in the heap for future usage
//  - malloc() function then RETURNS A POINTER to the new heap space
//    which allows access to the memory
//    can also be used to keep track of the storage that is been allocated

//MEMORY LAYOUT
//stack (memory allocates/releases automatically)
//heap (need malloc & free)
//globals
//constants (string literals)
//code (top level)

//release memory back when finished
//  - the heap has only a fixed amount of storage available
//    MEMORY LEAK happens when a programs asks for more memory without releasing old ones

//FREE()
//  - release the allocated memory by malloc() back to the heap for other uses
//    although when program stops running, all of its heap storage will be released
//    GOOD PRACTICE to explicitly call free() on every allocated dynamic memory

//SIZEOF()
//  - always usd malloc() with an operator call sizeof

#include <stdio.h>
#include <stdlib.h>  //need to include this for malloc() and free()

typedef struct{
    const char *name;
    const char *color;
    int weight;
}cat;

int main()
{
    cat *tabby = malloc(sizeof(cat));
    
    tabby->name = "tabby";
    tabby->color = "red";
    tabby->weight = 12;
    
    printf("the cat's name is %s\ncolor is %s\nits weight is %d\n", tabby->name, tabby->color, tabby->weight);
    
    free(tabby);
}

































