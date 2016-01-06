#include <stdio.h>
#include "array_utils.h"
#include <stdlib.h>

ArrayUtil create(int typeSize, int length){
     ArrayUtil final_array;
     final_array.base = calloc(typeSize,length);
     final_array.typeSize = typeSize;
     final_array.length = length;
     return final_array;
};
int areEqual (ArrayUtil first_array,ArrayUtil second_array){
     if(first_array.length == second_array.length &&
         first_array.typeSize == second_array.typeSize){
         return 1;
     };
     return 0;
};

void dispose (ArrayUtil array){
    free(array.base);
};

ArrayUtil resize (ArrayUtil Array , int length){
    int size_required = (length *Array.typeSize);
    Array.base = realloc(Array.base , size_required);
    Array.length = length;
    return Array;
};
