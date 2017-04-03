//ENCRYPTIION (XOR)

//file_hider
//  - read the contents of a file and create an encrypted version using XOR encryption
//message_hider
//  - read a series of strings from the standard input
//    and display an encrypted version on the standard output using XOR encryption

//void = no return; pass a pointer to a char array into the function

#include "9.XOR.h"  //include the header inside the c file
#include <stdio.h>

//encryo twice to get the original message; CHECK C operators
void encrypt(char *message)  //pass by value needs pointer to actually modify data in the char array
{
    char c;
    while(*message){
        *message = *message ^ 31; //XOR each character with the number 31; char is numeric data type
        message++;
    }
}

//COMPILATION
//  1. preprocessing: fix the source ---> #include directive(command)
//                                        #define & #ifdef
//  2. compilation: translate into assembly
//  3. assembly: generate the object code(binary code) ---> to be executed by the circuits inside the CPU
//  4. linking: encapsulation ---> form the executable program
//     the compiler will connect the code in one piece of object code that calls a function in another piece
//     also  ensure the prog is able to call library code properly
//     generate excutable prpogram file using supported format for the OS