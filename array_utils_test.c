#include <stdio.h>
#include "array_utils.h"
#include <assert.h>

void test_for_create(){
    ArrayUtil sample=create(4,5);
    assert(sample.length==5);
    assert(sample.typeSize==4);
};
void test_for_areEqual (){
    ArrayUtil array1,array2,array3;
    array1 = create(2,5);
    array2 = create(2,5);
    array3 = create (3,6);
    int *num=(int *)array1.base;
    num[0]=12;
    assert(areEqual(array1, array2) == 1);
    assert(areEqual(array1 ,array3) == 0);
    assert(areEqual(array2, array3) == 0);

};

int main(){
    test_for_create();
    test_for_areEqual();
}
