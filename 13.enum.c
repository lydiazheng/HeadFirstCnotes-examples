//ENUM
//  an enum variable stores a symbol
//  enum create a list of symbols
//      ---> enum colors {RED, GREEN, PUCE};
//           possible colors in the enum are seprated by commas
//           could have given the type a proper name with typedef

//***structs and unions separate items with semicolons(;), but enums use commas(,).

//any variable that is defined with a type of enum colors
//can then only be set to one of the keywords in the list
//      ---> enum colors favorite = PUCE;
//under the covers, the computer will assign numbers to each of the symbols in the list
//and the enum will just store a number
//C code can refer to the symbols

//how do enum track unions?

#include <stdio.h>

typedef enum{
    COUNT, POUNDS, PINT
}unit_m;

typedef union{
    short count;
    float weight;
    float volume;
}quantity;

typedef struct{
    const char *name;
    const char *country;
    quantity amount;
    unit_m units;
}fruit_order;

void display(fruit_order order)
{
    printf("This order contains ");
    
    if(order.units == PINT)
        printf("%2.2f pints of %s\n", order.amount.volume, order.name);
    else if(order.units == POUNDS)
        printf("%2.2f pounds of %s\n", order.amount.weight, order.name);
    else
        printf("%d count of %s\n", order.amount.count, order.name);
}

//struct declaration is like an array declaration but dot operator can also be used

int main()
{
    fruit_order apples = {"apples", "england", .amount.count=144, COUNT};
    
    fruit_order pear = {"pear", "spain", .amount.weight=17.6, POUNDS};
    
    fruit_order oj = {"orange", "US", .amount.volume=10.5, PINT};
    
    display(apples);
    display(pear);
    display(oj);
    
    return 0;
}















