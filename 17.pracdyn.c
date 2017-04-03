#include "17.pracdyn.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//create function that returns a pointer
island* create(char *name)
{
    island *i = malloc(sizeof(island));
    i->name = strdup(name);  //*** ***
    i->opens = "00:00";
    i->closes = "17:00";
    i->next = NULL;
    return i;
}

int main()
{
    char name[80];
    fgets(name, 80, stdin);
    island *p = create(name);
    
    
    //char hello[80];  //***see below
    fgets(name, 80, stdin);
    island *p1 = create(name);
    p->next = p1;
    
    printf("%s\n%s",  strtok((char *)p->name, "\n"), p->next->name);  //强制转成char * in order for strtok to work
    
    
}

//***
//if the hello array does not exist
//meaning p1 also uses the name array
//then the two islands share the sama name string
//as soon as the local name variable gets updated
//the two island names change simutaneously

//to make copies of string
//  - calling malloc() function to create a space on the heap
//    manually copying each character from the string to the space on the heap
//OR
//  - strdup()
//    reproduce a complete copy of the string somewhere on the heap
//    the function works out how long the string is
//    then calls the malloc() function to allocate the correct number of char on heap
//    it then copies each of the char to the new space on the heap
//    char *s = "MONA LISA";
//    char *copy = strdup(s);  //save the process of creating pointers and manually copy each char

//*** ***
//why only put te strdup() function on the name field?
//  - we are setting the opens & closes fields to string literals
//    string literals are stored in read-only area
//    always set opens and closes fields to constant values
//    no need for defensive copy of them, they will never change
//    name array need defensive copy
//    because something might come and update it later

//each time the user enters the name of an island
//create() function is storing it in a brand-new string


















