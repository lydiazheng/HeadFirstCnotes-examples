#include <stdio.h>
#include "10.fish.h"  //check this for struct details



int main(){

    //struct fish x1 = {"snappy", "piranha", 69, 4};
    
    //or
    
    fish x1;
    x1.name = "snappy";
    //must insert other data for struct items as well
    //...
    
    catalog(x1);
    return 0;
}

void catalog(fish fish)
{
    printf("x1's name is %s\n", fish.name);
}

//when you assign one struct to another

//fish gnasher = snappy;

//the contents of the struct will be copied
//NOT pointers, the assignment will just copy the pointer values --> both point to the the same address