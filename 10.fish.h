//struct, structured data type in fish.h

//line2;

typedef struct preferences{
    const char *food;
    float exercise_hours;
}pref;

//line2 end;

//typedef in 11.h
typedef struct fish{   //<struct><fieldname>
    const char *name;  //const char is for input string literals; strings not for change
    const char *species;
    int teeth;
    int age;
    pref care;         //***
}fish;                  //must be included to specify struct name

//declare using fish x1 is fine because of typedef.

//***declare
//fish snappy = {..., ..., ..., ..., {"meat", 7.5}}; //braces within
//or
//snappy.care.food = ....; & snappy.care.exercise_hours = ...;

//struct fish{
//    const char *name;
//    const char *species;
//    int teeth;
//    int age;
//};
//declare using struct fish x1;

void catalog(fish fish); //fish is a struct

//can you put one struct inside another???
//yes, to create more complexity in the object that is represented by a struct

//when creating struct --> creating a new data type --> complex objects
//therefore
//if a struct creates a data type from existing data types
//  - means you can also create structs from other structs --> check line2 & ***;

//page 235 bullet points
//      - structs are fixed length
//      - structs fields are stored in memory in the same order they appear in the code
//      - nest structs is allowed
//      - typedef creates an alias for a data type
//      - anonymous struct is allowed typedef struct{...}spider_man;

//REMEMBER c is pass by value, so use pointers to alter struct values as well
//void function (fish *t) & function(&specific fish struct);

//IMPORTANT NOTE page240
//*t in the function for struct must be addressed properly
//(*t).age = t->age is the parameter pointer to the struct's value
//*t.age, the contents of the memory location given by t.age; dereferencing t.age as a var