#include <stdio.h>
#include "Array_utils.h"

ArrayUtil create(int typeSize, int length);{
     ArrayUtil final_array;
     final_array.base = calloc(typeSize,length);
     final_array.typeSize = typeSize;
     final_array.length = length;
     return final_array;
};
