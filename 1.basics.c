#include <stdio.h>
#include <stdlib.h>


//Base64

int main()
{
    char card_name[3];//creating array of char; strings
    puts("Enter the car_name: ");
    scanf("%2s", card_name); //showing 2 in front of decimal pt
    int val = 0;
    if (card_name[0] == 'K'){
        val = 12;
    }
    else if (card_name[0] == 'Q'){
        val = 11;
    }
    else if (card_name[0] == 'J'){
        val = 10;
    }
    else if (card_name[0] == 'A'){
        val = 13;
    }
    else{
        val = atoi (card_name); //converts the string argument str to int
    }
    printf("The card value is: %d \n", val);
    
    //check if the value is 3 to 6
    if (val > 2 && val < 7)
        puts("Count has gone up");
    //otherwise check if the card was 10, j, q, or k
    else if (val == 10)
        puts("Count has gone down");
    return 0;
}
