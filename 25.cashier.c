#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef enum drink{
    VODKA, GIN
}liquor;

double price (liquor drink)
{
    switch(drink){
        case VODKA:
            return 5.25;
        case GIN:
            return 6.15;
    }
    return 0;
}

//what about a function called total() that will accept a count of the drinks
//then a list of drink names
//total(3, VODKA, GIN)
//will accept a count of the drinks and then a list of drink names


//variadic functions
//  - functions that take varying number of arguments
//    the C Standard Library contains a set of macros to create such functions

//macro
//  - used to rewrite your code before it is compiled
//    tells the preprocessor to generate more codes behind the scene

//print_ints(3, 79, 101, 32);

//print out the inputed numbers

//void print_ints(int args, ...)
//{
//    va_list ap;
//    va_start(ap, args);    //args contains a count of how many variables there are
//    int i;
//    for(i = 0; i < args; i++){
//        print_f("argument: %d \n", va_arg(ap, int));
//    }
//    va_end(ap);
//}

//CREATE A VARIADIC FUNCTIONS

//1.
//#include <stdarg.h>   //need this library to execute variadic macros

//2. ellipsis(省略号)
//  - an ellipsisi after the argument of a function means there are more arguments to come

//3. create a va_list
//  - a va_list will be used to store the extra arguments that are passed to the function

//4. set the variable arguments starting point
//  - need to identify the last fixed argument (args in the print_ints case)

//5. read off the variable arguments, one at a time
//  - arguments inputed  are all stored in the va_list,
//  - va_arg will read them
//          : va_arg takes two values
//            the va_list and the type of the next argument  (int in this case)

//6. end the list
//  - va_end to indicate all the arguments are read; finished

//7. call the function

//NOTE:
//  - need to have at least one fixed argument in order to pass its name to va_start
//    otherwise random error will occur
//    be sure to use the correct variable type

//total()

double total(int args, ...)
{
    double total = 0;
    va_list ap;
    va_start(ap, args);    //args; contains the number of inputed arguments
    int i;
    //printf("%d \n", args);
    for(i = 0; i < args; i++){
        liquor d = va_arg(ap, liquor);
        total = total + price(d);
    }
    va_end(ap);
    return total;
}

int main(){
    printf("price is %.2f\n", total(2, VODKA, GIN));
    return 0;
}

//always need to know the data type of every parameter read into the function















