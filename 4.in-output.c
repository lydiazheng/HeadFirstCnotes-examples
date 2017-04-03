#include <stdio.h>

int main()
{
    float lat;
    float lon;
    char info[80];
    int started = 0;
    
    puts("data = [");
    //scanf returns the # of values it reads
    //scanf needs pointers to the addresses
    while (scanf("%f, %f, %79[^\n]", &lat, &lon, info) == 3){
        if (started)
            printf(", \n");
        else
            started = 1;
        if(lat < -90.0 || lat > 90){
            puts("invalid lat");
            //fprintf(stderr, "invalid lat: %f \n", lat); will display on terminal even if redirect
            return 2;
        }
        
        if(lon < 180.0 || lon > 180.0){
            puts("invalid lon");
            return 2;
        }
        
        printf("{lat: %f, lon: %f, info: '%s'}", lat, lon, info);
    }
    puts("\n]");
    return 0;
}

//in order to read data from an output source into the input use: <
//in order to transfer output data into another file use: > xxx.file format
//echo $ allows the terminal to check for error status if the prog fails to run properly on unix system

//standard error
//every process has one Standard Input
//two outputs: Standard Output and Stand Error
//any messages sent down the Standard Error will still be visible on the screen8

//printf("I like cats"); = fprintf(stdout, "I like cats");
//fprintf() can send text to stdout or stderr

//fscanf(stdin, ...) allows us to read stdin and specify data stream

//> redirects standard output >2 redirects standard error in 4.in-output.c

// (./output | ./in-output) < spooky.csv > output.json
// | makes the output in output as the input for in-output

