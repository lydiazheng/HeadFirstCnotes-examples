//SORTING

#include <stdio.h>
#include <stdlib.h>

//qsort() function looks like
qsort(void *array, size_t length, size_t item_size, int(*compar)(const void*, const void*));
//a pointer to an array
//the length of the array
//the size of each element in th array
//function pointer to the function compares two items in the array
//  - void* pointer can point to anything

//the function compares pairs of values over and over
//  - if wrong order --> switch
//  - the comparator funtion is for returning three values to indicate the order
//    +ve, first value is greater
//    -ve, first value is smaller
//    0, the two value are equal

//a VOID POINTER can store the address of any knid of data
//  BUT, need to cast the specific type before proper usage

int compare_scores(const void* score_a, const void* score_b)
{
    ...
}

//though the values in the parameter of the function are void pointers
//WE MUST...
//when values are passed to the function as pinters
//cast...

int a = *(int*)score_a;
int b = *(int*)score_b;
//cast the void pointer to an integer pointer
//since pointer provides address, we must deference to get the value

//to return the three values...we must
//subtract the two inputed values

return a - b; || return b - a;

qsort(scores, 7, sizeof(int), compare_scores);  //here we are passing in function pointer to use the comp func