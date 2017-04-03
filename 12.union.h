//every time you create an instance of a struct
//the computer will lay out the fields in memoy, one after the other
//which will allocate unwanted space

//UNION
//  - a union will use the space for just one of the fileds in its definition
//  - ie: there are pieces of data that don't have a single data type
//        quantities can be integer/floating point (count, kg, etc)
//    computer will give the union enough space for its largest field
//      - leave it up to you which value will store in there


typedef union{
    short count;
    float weight;
    float volume;
}quantity;

//instead of

typedef struct{
    short count;
    float weight;
    float volume;
}fruitq;

//how do you use a union?

//C89 style for the first aid
//  - if the union is going to store a value for the first field
//    C89 notation: quantity q = {4}; //only the first field

//designated initializers set other values
//  - a designated initializer sets a union field value by name
//    quantity q = {.weight = 1.5};

//set the value with dot notation
//  - quantity q;
//    q.volume = 3.7;

//REMEMBER
// whichever way you set the union's value,
// there will only ever be one piece of data stored
// the union gives a way of creating a variabale that support several different data tyepes

//unions are often used with structs