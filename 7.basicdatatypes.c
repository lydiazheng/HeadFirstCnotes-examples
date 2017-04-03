//DATA TYPES

//char, int
//short - half space of an int - %hi
//long - maximum size of a long is guaranteed to be at least 32 bits
//     - long long is c99 and c11 only (-std=99 compile to the c99 standard)
//double - floatx2 to store decimal places

//(float) - 强制转type
//unsigned - positive

#include <stdio.h>
#include <limits.h> //contains the values for the integer types like int and char
// INT_MAX INT_MIN
#include <float.h> //contains the values for floats and doubles
// FLT_MAX FLT_MIN

//global memory spaces

float total = 0.0;
short count = 0;
short tax_percent = 6;

//a function
float add_with_tax(float f)
{
    float tax_rate = 1 + tax_percent / 100.0; //must add the .0 decimal, result will be float
    total = total + (f * tax_rate);
    count = count + 1;
    return total;
}

int main()
{
    float val;
    printf("Price of item:");
    while(scanf("%f", &val) == 1){
        printf("Total so far: %.2f\n", add_with_tax(val));
        printf("Price of item:");
    }
    printf("\nFinal total: %.2f\n", total);
    printf("Number of items: %hi\n", count);
    return 0;
}

