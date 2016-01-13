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
};
int isDivisible(void* hint, void* item){
    int * numerator = (int *)(item);
	int * denominator = (int *)(hint);
	if(( *numerator % *denominator ) == 0) return 1;
	return 0;
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
void test_for_count(){
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

void * hint_of_even = NULL;
int count_even_no = count(array, &isEven, hint_of_even);
assert(count_even_no == 3);

int hint_of_divide = 5;
int count_divided_value  = count(array, &isDivisible, &hint_of_divide);
assert(count_divided_value  == 2);
dispose(array);
};

void multiply(void* hint, void* firstItem, void* lastItem){
	int * multiply_hint = (int *)hint;
	int * first = (int *)firstItem;
	*(int *)lastItem = (* multiply_hint) * (*first);
};

void test_for_map(){
	ArrayUtil first_array = create(4,5);
	ArrayUtil last_array = create(4,5);

	int *numbers = (int *)(first_array.base);

	numbers[0] = 1;
	numbers[1] = 3;
	numbers[2] = 6;
	numbers[3] = 8;
	numbers[4] = 5;

	int multiply_hint = 3;
	map(first_array, last_array, &multiply, & multiply_hint);
	int * last_numbers = (int *)(last_array.base);
	assert(last_numbers[0]==3);
	assert(last_numbers[1]==9);
	assert(last_numbers[2]==18);
	assert(last_numbers[3]==24);
	assert(last_numbers[4]==15);
	dispose(first_array);
	dispose(last_array);
};

void * add (void *hint ,void *item){
    int * add_hint  =(int *) hint;
    *(int *)item = *(int *)item + *add_hint;
};

void test_for_forEach(){
    ArrayUtil array = create (4,5);
    int *numbers = (int *)(array.base);

    numbers[0] = 1;
	numbers[1] = 3;
	numbers[2] = 6;
	numbers[3] = 8;
	numbers[4] = 5;

    int add_hint = 5;
    forEach(array, &add ,&add_hint);
    assert(numbers[0]==6);
	assert(numbers[1]==8);
	assert(numbers[2]==11);
	assert(numbers[3]==13);
	assert(numbers[4]==10);
	dispose(array);
};

void test_for_filter () {
    ArrayUtil array = create (4,10);
    int *numbers = (int *)(array.base);

    numbers[0] = 1;
	numbers[1] = 2;
	numbers[2] = 6;
	numbers[3] = 8;
	numbers[4] = 3;
    numbers[5] = 4;
	numbers[6] = 5;
	numbers[7] = 7;
	numbers[8] = 80;
	numbers[9] = 59;

    ArrayUtil destination_array_isEven = create (4,10);
	void * even_hint = NULL;
	int maxItems = 10;
	int size = filter(array, &isEven , even_hint, destination_array_isEven.base ,maxItems);
	assert(((int **)destination_array_isEven.base)[0] == &numbers[1]);
	assert(((int **)destination_array_isEven.base)[1] == &numbers[2]);
    assert(((int **)destination_array_isEven.base)[2] == &numbers[3]);
	assert(((int **)destination_array_isEven.base)[3] == &numbers[5]);
    assert(((int **)destination_array_isEven.base)[4] == &numbers[8]);
	assert(size = 5);
	dispose(array);
	dispose(destination_array_isEven);
};


void* sum(void* hint, void* previousItem, void* item){
	*(int *)previousItem += *(int *)item;
	return previousItem;
};

void test_for_reduce(){
	ArrayUtil array = create(4,5);
	int *numbers = (int *)(array.base);

	numbers[0] = 1;
	numbers[1] = 3;
	numbers[2] = 6;
	numbers[3] = 8;
	numbers[4] = 5;

	void *hint = NULL;
	int intialValue = 4;
	int * result = (int *)reduce(array, &sum, hint, &intialValue);
	assert(* result == 27);
};
