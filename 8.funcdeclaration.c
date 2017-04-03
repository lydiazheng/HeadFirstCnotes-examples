//ORDER & FUNCTION DECLARATION

//mutually recursive functions
//two functions that call each other
//then one of them will always be called in the file before it is defined

//function declaration:
//                      float add_with_tax();
//it is a function signature:
//record of what the function will be called, its parameters and type of data it will return
//once a function is declared, the compiler will not make any assumptions


//(ie: compiler assumes that a function's return type is int)
//so it is ok to place the function after main() if its return type is an int
//however, function declarations is preferred to make things clearly

//gcc tool does preproprecessing and compilation
//  - source code into assembly code


//so it will not matter if you define the function after you call it

//HEADER FILE
//C allows you to take a whole set of declarations out and put them in a header file

#include <stdio.h>
#include "8.header.h"  //personal header must be with double quotes

//double quotes & angle brackets difference
// angle brackets:
//  - assumes it will find the header file somewhere off in the directories where the library code live
// double quote (personal header file):
//  - is in the same directory as its .c file (it tells the compiler to look for a local file)
//#include is a preprocessor instruction
//  - the compiler will read the contents of the header file
//  - just as if it had been typed into the code

//read through the stdio.h file on a Unix-style machine in
//  - /usr/include/stdio.h
//for MinGW compiler
//  - C:\MinGW\include\stdio.h

//separation of the declarations into a separate header file is organized

float total = 0.0;
short count = 0;
short tax_percent = 6;


int main()
{
    float val;
    printf("Price of item:");
    while(scanf("%f", &val) == 1){
        printf("Total so far: %.2f\n", add_with_tax(val));
        printf("Price of item:");
    }
    printf("\nFinal total: %.2f\n", total);
    printf("Number of items: %hi\n", count);
    return 0;
}

//a function; order does not matter when declaration is made in the included header file
float add_with_tax(float f)
{
    float tax_rate = 1 + tax_percent / 100.0; //must add the .0 decimal, result will be float
    total = total + (f * tax_rate);
    count = count + 1;
    return total;
}

