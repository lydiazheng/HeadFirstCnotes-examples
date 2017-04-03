#include "18.island.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

island* create(char *name)
{
    island *i = malloc (sizeof(island));
    i->name = strdup(name);
    i->opens = "00:00";
    i->closes = "17:00";
    i->next = NULL;
    return i;
    
}

void display(island *t)
{
    island *i = t;
    for(; i != NULL; i = i->next){
        printf("Name: %s open %s-%s\n", i->name, i->opens, i->closes);
    }
}

void release(island *t)
{
    island *i = t;
    island *next = NULL;
    for(; i != NULL; i = next){
        next = i->next;
        if(i->name)
            free(i->name); //need to free the name string created using strup()
        free(i);
    }
}

//island is a type of node
int main()
{
    island *start = NULL;
    island *i = NULL;
    island *next = NULL;
    char name[80];
    for(; fgets(name, 80, stdin) != NULL; i = next){ //cannot use EOF
        //using null and use ctrl-dß
        next = create(name);
        if(start == NULL)
            start = next;
        if(i != NULL)
            i->next = next;
    }
    display(start);
    release(start);
}

//heap is a random pile of data
//garbage collection
//  - NOT in C, but some language track when you allocate data on a heap
//    automatically free data from the heap
//    no automatic garbage collection when C is invented

















