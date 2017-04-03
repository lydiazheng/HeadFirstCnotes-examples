//CODE USING PIECE of XOR encryption

#include <stdio.h>
#include "9.XOR.h" //this is also included in the encrypt.c, so header file links all the pieces

//

//gcc message_hider.c encrypt.c -o message_hider
int main()
{
    char msg[80];
    while(fgets(msg, 80, stdin)){
        encrypt(msg);
        printf("%s", msg);
    }
}

//compiling lots of c files will slow the the compilation process ---> reduce efficiency
//DON't recompile every file
//  - save copies of the compiled code
//    if a file does change, recreate the object code for that one file
//    then pass the whole set of object files to the compiler so they can be linked
//    c source file --> compiler --> object code file --> linker --> excutable

//Process
//*的意思是把所有名字都打出来 --> ie: gcc -c x.c y.c & gcc x.o y.o -o try
//gcc -c *.c //create object code for every file
             //the operating system will replace *.c with all the C filenames
             //the *.c will match every C file in the currenty directory
             //the -c will tell the compiler that you want to create an object file for each source file
             //  - yet, don't want to link them together into a full executable program
//gcc *.o -o launch
             //*  -> match all the object files in the directory
             //-o -> instead of C source files, list the object files

//remember to update the changed files or use automate the process
//***if .o is newer than .c then no need to recompile, otherwise recompile

//AUTOMATE
//make
//  - is a tool that can run the compile command for you
//    will check the timestamps of the source files and the generated files
//    only recompile the files if things are out of date
//    requires target(compiling files), any file that is generated from some other files
//    can be zip archive that is generated from the set of files that need to be compressed
//    dependencies and the recipe form a rule

//    .c is a dependency, .o is the target
//    see page 200 for makefile specification