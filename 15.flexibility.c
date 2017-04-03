//LINKED LIST
#include <stdio.h>
//data structure
//  - linked list: insert things quickly
//  - array: direct access to items
//  - combination: is a possible solution to achieve both desired functioning

//create a recursive structure
//  - each one of the structs in the list will need to connect to the one next to it
//    a struct that contains a link to another struct of the same type
//    IS CALLED a recurvsive structure

//recursive structure
//  - contain pointers to other structures of the same type

//***
//C struct cannot contain a whole recursive struct inside itself
//  - C needs to know the exact amount of space a struct will occupy in memory
//    if it allowed full recursive copies of the same struct
//    then one piece of data would be different size than another
//    THUS only pointer to another struct is allowed
typedef struct island{
    char *name;
    char *opens;
    char *closes;
    struct island *next;
}island;


//***
//if the typedef command is used
//normally skip giving the struct a proper name
//but in a recursive structure
//need to include a pointer to the same type
//C syntax will not allow typedef alias without proper name
//thus, no anonyous struct allowed

//pointer to the address of the next island to visit

//create islands in C

//island amity = {"amity", "09:00", "17:00", NULL};
//island santa = {"amity", "09:00", "17:00", NULL};
//
//amity.next = &santa;  //link them together

void display(island *start)
{
    island *i = start;
    
    //i is initialized, thus no need any extra code @ the start of the loop
    for(; i != NULL; i = i->next){
        printf("Name: %s open %s-%s\n", i->name, i->opens, i->closes);
    }
}



int main()
{
    island amity = {"amity", "09:00", "17:00", NULL};
    island craggy = {"craggy", "09:00", "17:00", NULL};
    island isla_nublar = {"isla nublar", "09:00", "17:00", NULL};
    island shutter = {"shutter", "09:00", "17:00", NULL};
    amity.next = &craggy;
    craggy.next = &isla_nublar;
    isla_nublar.next = &shutter;
    
    island skull = {"skull", "09:00", "17:00", NULL};
    
    isla_nublar.next = &skull;
    skull.next = &shutter;
    display(&amity);
}


//declares a new variable skull right in the middle of the code
//only allowed in C99 and C11
//in ANSI C
//need to declare all local variables at the top of the function












































