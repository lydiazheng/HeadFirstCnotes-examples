//HEADER FILE FOR XOR ENCRYPTION

//share code by putting it intoo a separate C file
//put the function declarations in a separate .h header file 
//place header file in every C file that needs to use the shared code for LINKING
//list all the C files needed in the compiler command

//to share variables amongst c files
//  - source code files normally contain their own separate variables
//    to prevent a variable in one file affecting a variable in another file with the same name
//  - to share variables, declare them in the header file and prefix them with keyword extern:
//    ie: extern int passcode;

void encrypt(char *message);