#include <stdio.h>
#include "array_utils.h"
#include <assert.h>

void test_for_create(){
    ArrayUtil sample1=create(sizeof(char),5);
    assert(sample1.length==5);
    assert(sample1.typeSize==1);
    ArrayUtil sample2=create(sizeof(int),66);
    assert(sample2.length==66);
    assert(sample2.typeSize==4);
    ArrayUtil sample3=create(sizeof(double),12);
    assert(sample3.length==12);
    assert(sample3.typeSize==8);
    ArrayUtil sample4=create(sizeof(float),5);
    assert(sample4.length==5);
    assert(sample4.typeSize==4);

};
void test_for_resize(){
    ArrayUtil Array;
    Array = create(2,4);
    assert(Array.length ==4);

    Array = resize(Array,3);
    assert(Array.length ==3);

    Array = resize (Array,8);
    assert(Array.length ==8);


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
void test_dispose() {
    ArrayUtil array1,array2;
    array1 = create(1, 10);
    dispose (array1);
    array2 = create (sizeof(double),4);
    dispose (array2);
};

void test_for_find_index(){
	ArrayUtil array;
	array = create(4,2);
	int * numbers = (int *)(array.base);
	numbers[0]='1';
	numbers[1]='2';
	int first_element = '1';
	int second_element = '2';
	int extra_element = '3';
	assert(findIndex(array,&first_element)==0);
	assert(findIndex(array,&second_element)==1);
	assert(findIndex(array,&extra_element)==-1);
	dispose(array);
}
int main(){
    test_for_create();
    test_for_areEqual();
    test_for_resize();
    test_for_find_index();
};
