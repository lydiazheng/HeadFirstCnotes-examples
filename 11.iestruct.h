//typedef - give a type, a new name
//#define - a C-directive which is also usd to define the aliases for various data types
//          similar to typefef but with the following differences

//          typedef is limited to giving symbolic names to types only
//          #define can be sued to define alias for values as well

//          typedef interpretation is performed by the compiler
//          #define statements are processed by the pre-processor

//          use #define as the following
//          #define TRUE 1         //now TRUE is 1
//          #define FALSE 0        //now FALSE is 0

typedef struct exercise{    //<struct><fieldname>
    const char *description;
    float duration;
}exer;

typedef struct meal{
    const char *ingredients;
    float weight;
}meal;

typedef struct preferences{
    meal food;
    exer exercise;
}pref;

typedef struct fish{
    const char *name;
    const char *species;
    int teeth;
    int age;
    pref care;
}fish;

