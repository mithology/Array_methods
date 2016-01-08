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
	numbers[0]=1;
	numbers[1]=2;
	int first_element = 1;
	int second_element = 2;
	int extra_element = 3;
	assert(findIndex(array,&first_element)==0);
	assert(findIndex(array,&extra_element)==-1);
	dispose(array);
};

int isEven(void *hint, void *item){
    int *numbers = (int *)item;
    return !(*numbers % 2);
}
int isDivisible(void* hint, void* item){
    int *numerator = (int *)item;
    int *denomenator = (int *)hint;
    return !(*numerator % *denomenator);
};
void test_for_find_first(){
    ArrayUtil array;
    array = create (sizeof(int),6);
    int *numbers = (int *) (array.base);
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    numbers[3] = 5;
    numbers[4] = 14;
    numbers[5] = 16;

void * hint = NULL;
   int * value = (int *)findFirst(array ,&isEven, hint);
   assert(*value == 2);

   hint = (void *)&numbers[1];
   value = (int *)findFirst(array, &isDivisible, hint);
   assert(*value == 2);
};
void test_for_find_last(){
    ArrayUtil array;
    array = create (sizeof(int),8);
    int *numbers = (int *) (array.base);
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    numbers[3] = 5;
    numbers[4] = 14;
    numbers[5] = 16;
    numbers[6] = 15;
    numbers[7] = 11;


void * hint = NULL;
   int * value = (int *)findLast(array ,&isEven, hint);
   assert(*value == 16);

   hint = (void *)&numbers[2];
   value = (int *)findLast(array, &isDivisible, hint);
   assert(*value == 15);
};

int main(){
    test_for_create();
    test_for_areEqual();
    test_for_resize();
    test_dispose();
    test_for_find_index();
    test_for_find_first();
    test_for_find_last();

};
