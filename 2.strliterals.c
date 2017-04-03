#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//don't set a simple char pointer to a string literal
//if no modification needed use: const char * s = "..." can be used
int main()
{
    char * cards = "JQK";  //string literal cannot be updated
    char card[] = "JQK";   //char array can
    printf("%c %c \n", *(cards), card[1] );
    card[1] = card[2];
    printf("%c %c \n", *(cards), card[1] );
    return 0;
}
