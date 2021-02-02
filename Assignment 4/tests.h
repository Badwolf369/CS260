#include <iostream>

#include "linked_list.h"
#include "node.h"

int test_push(int condition)
{


	return 0;
}

int test_pull(int condition)
{


	return 0;
}

int test_peek()
{
	LinkedList* TPKlist = new LinkedList();

	
	//test 1: empty
	//returns -1


	return 0;
}

int test_print_state()
{
	LinkedList* TPSlist = new LinkedList();


	//test 1: empty
	//prints:
	/*
	List state:
		empty
	*/
	TPSlist->print_state();

	
	//test 2: single value
	//prints:
	/*
	List state:
		<null>
		<address1>: 1
		<null>
	*/
	node* node1 = new node;
	node1->value = 1;

	TPSlist->set_state(node1, node1, 1);
	TPSlist->print_state();


	//state 3: multivalue
	//prints:
	/*
	List state:
		<null>
		<address1>: 1
		<address2>
			|
		<address1>
		<address2>: 2
		<address3>
			|
		<address2>
		<address3>: 3
		<address4>
			|
		<address3>
		<address4>: 4
		<null>
	*/

	//very crude manually set list state
	node* node2 = new node;
	node* node3 = new node;
	node* node4 = new node;

	node1->value = 1;
	node2->value = 2;
	node3->value = 3;
	node4->value = 4;

	node1->link_r = node2; node2->link_l = node1;
	node2->link_r = node3; node3->link_l = node2;
	node3->link_r = node4; node4->link_l = node3;

	TPSlist->set_state(node1, node4, 4);
	TPSlist->print_state();
}

//unable to test automatically; can be tested here by pausing and verifying memory state
int test_set_state()
{

}