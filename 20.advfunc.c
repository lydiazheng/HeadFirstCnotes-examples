#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//char ADS[][80] = {  //an array of char arrays; 2-D array; fixed length
//    "hello",
//    "hi"
//};

//somewhat equivalent, but one cannot update string literals (they are read-only)

//char *ads[] = {  //pointer array; an array of pointers to string literals
//    "hello",
//    "hi"
//};

int NUM_ADS = 7;
char *ADS[] = {
    "William: SBM GSOH likes sports, TV, dining",
    "Matt: SWM NS likes art, movies, theater",
    "Luis: SLM ND likes books, theater, art",
    "Mike: DWM DS likes trucks, sports and bieber",
    "Peter: SAM likes chess, working out and art",
    "Josh: SJM likes sports, movies and theater",
    "Jed:DBM likes theater, books and dining"
};

//use functions correctly to do more things without writing more code

int main()
{
    int i;
    puts("Search results:");
    puts("--------------------------------");
    
    for(i = 0; i < NUM_ADS; i++){
        if(strstr(ADS[i], "sports") && !strstr(ADS[i], "bieber"))
            printf("%s\n", ADS[i]);
    }
    puts("--------------------------------");
}


//Every Function Name is a Pointer to the Function

//the name of a function (in the CONSTANT MEM)
//  - it is a way of referring to the piece of code
//    --> basically a pointer; referring to something in the memory

//  - in C, function names are also pointer variables
//    the name contains the address of the function

//  - BUT there is no function data type
//    because the type of function is defined by a combination of things

///HOW TO CREATE FUNCTION POINTERS

int (*wrap_fn)(int);
//declare a function pointer first
//func type/ creating function pointer/ input of the function

wrap_fn = go_to_wrap_speed;
//set declared pointer to the function name

wrap_fn(4);
//providing input to the pointer to the function
//just like calling the function itself

//another example
char** (*name_fn)(char*, int);
names_fn = album_names;
char** results = names_fn("Sacha Distel", 1972);
//char** is a pointer normally used to point to an array of strings

//MUST tell C
//  - the return type & the parameter types the function will take
//    once the function pointer vairable is declared,
//    can be used like any other variables



























































