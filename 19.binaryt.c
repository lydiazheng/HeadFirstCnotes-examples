//BINARY TREE data structure

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char *question;      //question, this is not a string literal
    struct node *no;     //no
    struct node *yes;    //yes
}node;

//take the question string
int yes_no(char *question)
{
    char ans[3];
    printf("please answer the following question(y/n): %s\n", question);
    fgets(ans, 3, stdin);
    return ans[0] == 'y';
}

node* create(char *info) //take question
{
    node *i = malloc(sizeof(node));
    i->question = strdup(info);
    i->no = NULL;
    i->yes = NULL;
    return i;
    
}

void release(node *rel)  //release the node
{
    if(rel){
        
        if(rel->question)
            free(rel->question);
        if(rel->no)
            free(rel->no);
        if(rel->yes)
            free(rel->yes);
        
    }
    free(rel);  //don't forget to release rel itself
}

//basic structure defined
int main() {
    char question[80];
    char suspect[20];
    node *start_node = create("Does suspect have a mustache");
    start_node->no = create("Loretta Barnsworth");
    start_node->yes = create("Vinny the Spoon");
    node *current;
    do {
        current = start_node;
        while (1) {
            if (yes_no(current->question)) {
                if (current->yes) {  //run through the suspect list
                    current = current->yes;
                }
                else {     //if there is no continuation of suspect list, then suspect is identified
                    printf("SUSPECT IDENTIFIED\n");
                    break;
                }
            }
            else if (current->no) {
                current = current->no;
            }
            
            
            //if yes_no is not identified
            else {
                /* Make the yes-node the new suspect name */
                printf("Who's the suspect? ");
                fgets(suspect, 20, stdin);
                node *yes_node = create(suspect);
                current->yes = yes_node;
                /* Make the no-node a copy of this question */
                node *no_node = create(current->question);
                current->no = no_node;
                /* Then replace this question with the new question */
                printf("Give me a question that is TRUE for %s but not for %s? ", suspect, current->question);
                fgets(question, 80, stdin);
                //free(current->question);
                current->question = strdup(question);
                break;
            }
        }
    }
    while(yes_no("Run again"));
    release(start_node);
    //release(current);
    return 0;
}

//if suspect y, else if suspect n, else new suspect ... is the process
//the program builds a tree of suspects
//  - records data using a binary tree
//    allows each piece of data to conect to two other pieces of data



//HOW TO TRACK MEMORY LEAKS?

//one tool used on the LINUX operating system is called
//  - valgrind  //only works in LINUX
//    it monitor the pieces of data that are allocated space on the heap
//    works by creating its own fake version of malloc()
//    when the program wants to allocate some heap memory
//    valgrind will intercept the call & runs its own version
//    will take note of which piece of code is calling it and which peice of meomory is allocated
//    when ends, will report data left on the heap & where the code is created

//to maximize valgrind
//make sure the executable contains debug information
//  - debug information
//    is the extra data that gets packed into the xecutable when it is compiled
//    things like the line number in the source file that a particular piece of code was compiled from

//if the debug info is present
//valgrind will be able to provide more details about the source of memory leak

//to add debug info into the executable
//recompile the source with the -g switch
//  --> gcc -g spies.c -o spies
//      tells the compiler to record the line numbers against the code it compiles
//  --> valgrind --leak-check=full ./try







































