//QSORT() practice

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//sort integer scoares in ascending order
int comp_score(const void* score_a, const void* score_b)
{
    int a = *(int*)score_a;
    int b = *(int*)score_b;
    return a - b;
}

//desceding order
int comp_scores_desc(const void* score_a, const void* score_b)
{
    int a = *(int*)score_a;
    int b = *(int*)score_b;
    return b - a;
}

typedef struct{
    int width;
    int height;
}rectangle;

//sort the rectangles in area order, ascending
int comp_areas(const void*a, const void* b)
{
    rectangle* aa = (rectangle*)a;
    rectangle* bb = (rectangle*)b;
    int aaa = ((aa->height) * (aa->width));
    int bbb = ((bb->height) * (bb->width));

    return aaa - bbb;
    
}

//descending
int comp_a_d(const void*a, const void* b)
{
    return comp_areas(b, a);  //by switching the order, the return value wil be different
}

//sort a list of names in alphabetical order, case-sensitive
int compare_names(const void* a, const void* b)
{
    char** sa = (char**)a;
    char** sb = (char**)b;
    return strcmp(*sa, *sb);  //compare strings
}

//descending
int compare_n_d(const void*a, const void* b)
{
    return compare_names(b, a);  //by switching the oder, the return value will be different
}


int main()
{
    int scores[] = {543, 323 , 32, 554, 11, 3 ,112};
    int i;
    
    qsort(scores, 7, sizeof(int), comp_scores_desc);
    puts("These are the scores in order:");
    for(i = 0; i < 7; i++){
        printf("Score = %d\n", scores[i]);
    }
    
    char *names[] = {"Karen", "Mark", "Brett", "Molly"};
    qsort(names, 4, sizeof(char*), compare_names);
    for(i = 0; i < 4; i++){
        printf("%s\n", names[i]);
    }
    return 0;
}


//char**
//  - each item in a string array is a char*
//    need pointers-to-pointers-to-char

//strcmp(*sa, *sb)
//  - sa & sb are of type char**
//    but strcmp() function needs values of type char*
//    thus, dereference

//qsort() actually modifies the original array instead of make a copy


















