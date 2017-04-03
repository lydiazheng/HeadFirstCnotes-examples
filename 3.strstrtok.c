#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char tracks[][80] = {  //puting it in global scope
    "I left my heart in Harvard Med School",
    "Newark, Newark - a wonderful town",
    "Dancing with a Dork",
    "From here to maternity",
    "The girl from Iwo Jima",
};

void find_track(char search_for[])
//the parametre is a pter same as char* search_for
//but in a function, it is an array--->not pter to a string literal
{
    int i;
    //    char s[80];
    //    for (i=0; i<strlen(search_for)-2; i++)  //eliminate \n
    //    {
    //        s[i]=search_for[i];
    //    }
    //printf("%s", s);
    for (i = 0; i < 5; i++){
        //printf("%s \n", tracks[i]);
        char * pt = strstr(tracks[i], strtok(search_for, "\n"));
        //strtok works on non-empty str only; fgets will have \n
        //"\n" is the delimiter replaced by a null character
        //many limitation
        if (pt != NULL)
        {printf ("Track %i: '%s' \n", i, tracks[i]);}
        //else
        //{puts("not found");}
    }
}

int main()
{
    char search_for[80];
    printf("Search for: ");
    fgets(search_for, 80, stdin); //will get \n
    //scanf("%s", search_for);  //succeed
    //puts(search_for);  //will \n
    printf("%s", search_for);
    find_track(search_for);
    return 0;
    
}