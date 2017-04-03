//output into different files

//FILE * in_file = fopen("input.txt", "r"); read
//FILE * out_file = fopen("output.txt", "w"); write //"a" = append
//FILE creat a data stream

//fscanf(in_file, "%79[^\n]\n", sentence);
//fprintf(out_file, "Don't wear %s with %s", "red", "green");

//fclose(in_file);
//fclose(out_file);

//REMEMBER condition checks
FILE *in;
if (!(in = fopen("dont_exist.txt", "r"))) {
    fprintf(stderr, "Can't open the file.\n");
    return 1;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char line[80];
    
    FILE * in = fopen("spooky.csv", "r");
    FILE * file1 = fopen("ufos.csv", "w");
    FILE * file2 = fopen("dis.csv", "w");
    FILE * file3 = fopen("others.csv", "w");
    
    while(scanf(in, "%79 [^\n]\n", line) == 1){
        if(strstr(line, "UFO"))
            fprintf(file1, "%s\n", line);
        else if(strstre(line, "dis"))
            fprintf(file2, "%s\n", line);
        else
            fprinrf(file3, "%s\n", line);
    }
    fclose(file1);
    fclose(file2);
    fclose(file3);
    fclose(in);
    return 0;
}

//prog will read the spooky and split up the data, line by line into the 3 files

//passing command-line arguments
//./categorize mermaid mermaid.csv Elvis elvises.csv the_rest.csv
//int main(void)
//or


//int main(int argc, char *argv[])
//main function read command-line arguments as an array of character pointers
//./categorize mermaid mermaid.csv Elvis elvises.csv the_rest.csv  <---argv[] char pointer array
//is equivalent to
//argv[0] argv[1] argv[2] argv[3] argv[4] argv[5]
//argc = the number of elements in the array


int main(int argc, char *argv[])
{
    char line[80];
    
    if (argc != 6) {
        fprintf(stderr, "need five arguments");   //note: stderr will always show on terminal even redirect
        return 1;
    }
    
    FILE *in = fopen("spooky.csv", "r");
    FILE *file1 = fopen(argv[2], "w");
    FILE *file2 = fopen(argv[4], "w");
    FILE *file3 = fopen(argv[5], "w");
    
    while (fscanf(in, "%79[^\n]\n", line) == 1) {
        if (strstr(line, argv[1])) {
            fprintf(file1, "%s\n", line);
        }
        else if (strstr(line, argv[3])){
            fprintf(file2, "%s\n", line);
        }
        else
            fprintf(file3, "%s\n", line);
    }
    
    fclose(file1);
    fclose(file2);
    fclose(file3);
    fclose(in);
    return 0;     //alternative way of writing finout
}
