//CONTROL at the BIT LEVEL

//creating a struct with a series of shorts or ints
//will take up more space than the single bit need for 0/1 values --> wasteful
//BETTERto createa struct that could hold a sequence of single bits for the values --> bitfields

//when dealing with binary value, better to specifying the 1s and 0s in a literal
//C does not support binary literals
//C SUPPORTS hexadecimal literals
//every time C sees a number beginning with 0x
//  - treats the number as base 16
//    int x = 0x54;                 5 -> 0101, 4 -> 0100
//    int x = 01010100;

//bitfields store a custom number of bits
//    - it allow specification of how many bits an individual field will store


//each field should be an unsigned int
typedef struct{
    unsigned int low_pass_vcf:1;     //means that field will only use 1 bit of storage
    unsigned int filter_coupler:1;
    unsigned int reverb:1;
    unsigned int sequential:1;
}synth;

//BITFIELDS can sae space if they are collected together in a struct
//  - but if the compiler finds a single bitfield on its own
//    it might still have to pad it out to the size of a word
//    that is why bitfields are usually grouped together

//therefore, if a sequence of bitfields is present
//the computer can squash them together to save space
//  - if eight single-bit bitfields, the computer can store them in a single byte

//bitfields can be sued to store a sequence of 0/1 values
//they are also useful for other short-range values
//  - ie. month in a struct is 0-11 --> 4 bits --> allows 0-15; 16 values(2^4 is 16)
//                                      3 bits --> only store 0-7(2^3 is 8)
// unsigned int month_no:4;

//PRACTICE

typedef struct{
    unsigned int first_visit:1;   //true or false
    unsigned int come_again:1;
    unsigned int fingers_lost:4;
    unsigned int shark_attack:1;
    unsigned int days_a_week:3;
}survey;





























