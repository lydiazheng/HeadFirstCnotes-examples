//MAIL-merge program to send out different types of messages to different people

//use a data struct like thiss

#include <stdio.h>
#include <stdlib.h>

//the three types of meassges that will be sent to people
enum response_type{DUMP, SECOND_CHANCE, MARRIAGE};

//struct, people's names and their email type
typedef struct{
    char *name;
    enum response_type type;
}response;

//since we create a struct type
//now we can have functions to represent the types of emails
void dump(response r)
{
    printf("Dear %s, \n", r.name);
    puts("Unforutnately your last date contacted us to");
    puts("say that they will not be seeing you again");
}

void second_chance(response r)
{
    printf("Dear %s, \n", r.name);
    puts("Good news: your last date has asked us to");
    puts("arrange another meeting. Please call ASAP");
}

void marriage(response r)
{
    printf("Dear %s, \n", r.name);
    puts("Congratulations! Your last date has contacted");
    puts("us with a proposal of marriage");
}

int main()
{
    response r[] = {
        {"Mike", DUMP}, {"Luis", SECOND_CHANCE}, {"Matt", SECOND_CHANCE}, {"Will", MARRIAGE}
    };
    int i;
    for(i = 0; i < 4; i++){
        switch(r[i].type){     //testing the mail type each time
            case DUMP:
                dump(r[i]);
                break;
            case SECOND_CHANCE:
                second_chance(r[i]);
                break;
            default:
                marriage(r[i]);
        }
    }
    return 0;
}

//it is not convenient to use a for-loop to call the array every time to check

//use an array of cuntion pointers
//to match the different response types

//replies[] = {dump, second_chance, marriage};

//NOTE: that to make an array pointer, we need

//return type(* pointer variable)(function parameter types)

void(*replies[])(response) = {dump, second_chance, marriage}；

//each function in the aray will be a void function
//the variable will be called "replies"
//it is not just a function pointer; whole array of them
//parameters

enum response_type{DUMP, SECOND_CHANCE, MARRIAGE};

//the enum gives each of the symbols a number(index)
//get a pointer to one of your sets of functions using a response_type

replies[SECOND_CHANCE] == second_chance

//the function pointers, SECOND_CHANCE has the value 1
//it is equal to the name of the second_chance function

void(*replies[])(response) = {dump, second_chance, marriage};

int main()
{
    response r[] = {
        {"Mike", DUMP}, {"Luis", SECOND_CHANCE}, {"Matt", SECOND_CHANCE}, {"Will", MARRIAGE}
    };
    int i;
    for(i = 0; i < 4; i++){
        (replies[r[i].type])(r[i]);
    }
    return 0;
}






















