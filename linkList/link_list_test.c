#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "link_list.h"

void test_for_createList(){
    List dummy_list ;
    dummy_list = createList();

    assert(NULL == dummy_list.last);
    assert(dummy_list.first == NULL);
    assert(dummy_list.length == 0);
};

void test_for_add_to_list(){
    List dummy_list;
    int value1 =50,value2 = 10;
    dummy_list = createList();
    int length = add_to_list(&dummy_list , &value1);
    assert(1 == length);
    assert(1 == dummy_list.length);

    element * result = (element *)(dummy_list.first);

	assert(*(int *)(result -> value) == 50);
	assert(result -> value == &value1);
	assert(result -> next == NULL);
	assert((element *)(dummy_list.last) == result);

	length = add_to_list(&dummy_list, &value2);

	assert(length == 2);
	assert(dummy_list.length == 2);

	result = (element *)(dummy_list.last);

	assert(*(int *)(result -> value) == 10);
    assert(result -> value == &value2);
	assert(result -> next == NULL);
	assert((element *)(dummy_list.last) == result);
};

void test_for_get_first_element(){
	List dummy_list;
	dummy_list = createList();
	int first = 20;
	add_to_list(&dummy_list, &first);
	int second = 10;
	add_to_list(&dummy_list, &second);
    int third = 30;
    add_to_list(&dummy_list,&third);
    int fourth = 40;
    add_to_list(&dummy_list,&fourth);
    int fifth = 50;
    add_to_list(&dummy_list,&fifth);
    int sixth = 60;
    add_to_list(&dummy_list,&sixth);
	assert(*(int *)(dummy_list.first)->value == 20);
};

void test_for_get_last_element(){
	List dummy_list;
	dummy_list = createList();
	int first = 20;
	add_to_list(&dummy_list, &first);
	int second = 10;
	add_to_list(&dummy_list, &second);
    int third = 30;
    add_to_list(&dummy_list,&third);
    int fourth = 40;
    add_to_list(&dummy_list,&fourth);
    int fifth = 50;
    add_to_list(&dummy_list,&fifth);
    int sixth = 60;
    add_to_list(&dummy_list,&sixth);
	assert(*(int *)(dummy_list.last)->value == 60);
};

void add_ten_with_each(void * element){
	*(int *)element += 10;
}

void test_for_forEach(){
	List dummy_list;
	dummy_list = createList();
	int first = 20;
	int second = 10;
	int third = 0;

	add_to_list(&dummy_list, &first);
	add_to_list(&dummy_list, &second);
	add_to_list(&dummy_list, &third);

	forEach(dummy_list, &add_ten_with_each);

	assert(*(int *)dummy_list.first->value == 30);
	assert(*(int *)dummy_list.last->value == 10);
};


void test_for_getElementAt(){
	List dummy_list;
	dummy_list = createList();
	int first = 20;
	int second = 10;
	int third = 0;

	add_to_list(&dummy_list, &first);
	add_to_list(&dummy_list, &second);
	add_to_list(&dummy_list, &third);

	int * result = (int *)getElementAt(dummy_list,1);
	assert(*result == 10);
	result = (int *)getElementAt(dummy_list,2);
	assert(*result == 0);
}

void test_for_indexOf(){
	List dummy_list;
	dummy_list = createList();
	int first = 20;
	int second = 10;
	int third = 0;

	add_to_list(&dummy_list, &first);
	add_to_list(&dummy_list, &second);
	add_to_list(&dummy_list, &third);
	assert(indexOf(dummy_list,&second)==1);
	assert(indexOf(dummy_list,&first)==0);
}
