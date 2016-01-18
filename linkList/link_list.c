#include "link_list.h"
#include "stdlib.h"
#include "stdio.h"

void initialize(List *array) {
	array->first =  NULL;
	array->last = NULL;
	array->length = 0;
};

List createList(void){
	List dummy_list;
	initialize(&dummy_list);
	return dummy_list;
};

int add_to_list(List * dummy_list,void * pushed_element){
	element *node;
	node = (element *)malloc(sizeof(element));
	node->value = pushed_element;
	node->next = NULL;
	if(dummy_list->length==0){
		dummy_list->first = dummy_list->last =  node;
	}
	else{
		dummy_list->last->next = node;
		dummy_list->last = node;
	}
	dummy_list->length++;
	return dummy_list->length;
}

void * get_first_element(List dummy_list){
	return (element *)(dummy_list.first)->value;
};

void *get_last_element(List dummy_list){
	return (element *)(dummy_list.last)->value;
};

void forEach(List dummy_list, ElementProcessor edit_function){
	element * node = (element *)(dummy_list.first);
	while(node != NULL){
		edit_function(node->value);
		node=node->next;
	};
};

void * getElementAt(List dummy_list, int position){
	int counter = 0;
	element * node = (element *)(dummy_list.first);
	while(counter<position){
		node = node->next;
		counter++;
	};
	return node->value;
};

int indexOf(List dummy_list, void * value_pointer){
	int counter = 0;
	element * node = (element *)(dummy_list.first);
	while(node != NULL){
		if(node->value==value_pointer)
			return counter;
		node = node->next;
		counter++;
	};
	return -1;
};
