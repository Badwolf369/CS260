#include <iostream>

#include "linked_list.h"
#include "node.h"
#include "return_data.h"

class TestEnv {
private:
	LinkedList* testList = new LinkedList;

	void link_nodes(node* nodeL, node* nodeR)
	{
		//create a proper link between 2 nodes
		nodeL->link_r = nodeR;
		nodeR->link_l = nodeL;
	}

	void set_state_empty()
	{
		testList->start = nullptr;
		testList->end = nullptr;
		testList->len = 0;
	}

	void set_state_1_val()
	{
		node* node1 = new node;
		node1->value = 1;

		testList->start = node1;
		testList->end = node1;
		testList->len = 1;
	}

	void set_state_4_vals()
	{
		node* node1 = new node;
		node* node2 = new node;
		node* node3 = new node;
		node* node4 = new node;

		node1->value = 1;
		node2->value = 2;
		node3->value = 3;
		node4->value = 4;

		link_nodes(node1, node2);
		link_nodes(node2, node3);
		link_nodes(node3, node4);

		testList->start = node1;
		testList->end = node4;
		testList->len = 4;
	}

public:
	int test_push(int condition)
	{


		return 0;
	}

	int test_pull(int condition)
	{
		cout << "testing pull():" << endl;
		int idx;
		return_data* dat;

		//############################################################################

		//test 1: remove item from empty list;
		//starting state: empty
		//item: 0
		//final state: empty
		//return: error 1
		cout << "test 1:" << endl;
		set_state_empty();
		idx = 0;

		cout << "starting ";
		testList->print_state();
		dat = testList->pull(idx);
		if (dat->error == 1)
		{
			cout << "List empty. No values to return." << endl;
		}
		else if (dat->error == 2)
		{
			cout << "Index outside list. Unable to return value." << endl;
		}
		else
		{
			cout << "Item at index " << idx << ": " << dat->value << endl;
		}
		cout << "final ";
		testList->print_state();

		cout << endl;

		//############################################################################

		//test 2: remove item after end of list; index 4
		//starting state: 1 - 2 - 3 - 4
		//item: 4
		//final state: 1 - 2 - 3 - 4
		//return: error 2
		cout << "test 2:" << endl;
		set_state_4_vals();
		idx = 4;

		cout << "starting ";
		testList->print_state();
		dat = testList->pull(idx);
		if (dat->error == 1)
		{
			cout << "List empty. No values to return." << endl;
		}
		else if (dat->error == 2)
		{
			cout << "Index outside list. Unable to return value." << endl;
		}
		else
		{
			cout << "Item at index " << idx << ": " << dat->value << endl;
		}
		cout << "final ";
		testList->print_state();

		cout << endl;

		//############################################################################

		//test 3: remove item before beginning of list; index -1
		//starting state: 1 - 2 - 3 - 4
		//item: -1
		//final state: 1 - 2 - 3 - 4
		//return: error 2
		cout << "test 3:" << endl;
		set_state_4_vals();
		idx = -1;

		cout << "starting ";
		testList->print_state();
		dat = testList->pull(idx);
		if (dat->error == 1)
		{
			cout << "List empty. No values to return." << endl;
		}
		else if (dat->error == 2)
		{
			cout << "Index outside list. Unable to return value." << endl;
		}
		else
		{
			cout << "Item at index " << idx << ": " << dat->value << endl;
		}
		cout << "final ";
		testList->print_state();

		cout << endl;

		//############################################################################

		//test 4: remove item that empties list; index 0
		//starting state: 1
		//item: 0
		//final state: empty
		//return: value 1
		cout << "test 4:" << endl;
		set_state_1_val();
		idx = 0;

		cout << "starting ";
		testList->print_state();
		dat = testList->pull(idx);
		if (dat->error == 1)
		{
			cout << "List empty. No values to return." << endl;
		}
		else if (dat->error == 2)
		{
			cout << "Index outside list. Unable to return value." << endl;
		}
		else
		{
			cout << "Item at index " << idx << ": " << dat->value << endl;
		}
		cout << "final ";
		testList->print_state();

		cout << endl;

		//############################################################################

		//test 5: remove item from beginning of list; index 0
		//starting state: 1 - 2 - 3 - 4
		//item: 0
		//final state: 2 - 3 - 4
		//return: value 1
		cout << "test 5:" << endl;
		set_state_4_vals();
		idx = 1;

		cout << "starting ";
		testList->print_state();
		dat = testList->pull(idx);
		if (dat->error == 1)
		{
			cout << "List empty. No values to return." << endl;
		}
		else if (dat->error == 2)
		{
			cout << "Index outside list. Unable to return value." << endl;
		}
		else
		{
			cout << "Item at index " << idx << ": " << dat->value << endl;
		}
		cout << "final ";
		testList->print_state();

		cout << endl;

		//############################################################################

		//test 6: remove item from end of list; index 3
		//starting state: 1 - 2 - 3 - 4
		//item: 3
		//final state: 1 - 2 - 3
		//return: value 4
		cout << "test 6:" << endl;
		set_state_4_vals();
		idx = 3;

		cout << "starting ";
		testList->print_state();
		dat = testList->pull(idx);
		if (dat->error == 1)
		{
			cout << "List empty. No values to return." << endl;
		}
		else if (dat->error == 2)
		{
			cout << "Index outside list. Unable to return value." << endl;
		}
		else
		{
			cout << "Item at index " << idx << ": " << dat->value << endl;
		}
		cout << "final ";
		testList->print_state();

		cout << endl;

		//############################################################################

		//test 7: remove item from middle of list; index 1
		//starting state: 1 - 2 - 3 - 4
		//item: 1
		//final state: 1 - 3 - 4
		//return: value 2
		

		//############################################################################

		//test 8: remove 2 consecutive items
		//starting state: 1 - 2 - 3 - 4
		//items: 1, 2
		//final state: 1 - 4
		//return: values 2, 3

		//############################################################################

		//test 9: remove 2 non-consecutive items
		//starting state: 1 - 2 - 3 - 4
		//items: 1, 3
		//final state: 1 - 3
		//return: values 2, 4

		//############################################################################

		return 0;
	}

	int test_peek()
	{
		cout << "testing peek():" << endl;
		int idx;
		return_data* dat;

		//############################################################################

		//test 1: empty
		//state: empty
		//returns error code 1
		cout << "test 1:" << endl;
		set_state_empty();
		idx = 0;

		testList->print_state();
		dat = testList->peek(idx);
		if (dat->error == 1)
		{
			cout << "List empty. No values to return." << endl;
		}
		else if (dat->error == 2)
		{
			cout << "Index outside list. Unable to return value." << endl;
		}
		else
		{
			cout << "Item at index " << idx << ": " << dat->value << endl;
		}

		cout << endl;

		//############################################################################

		//test 2: looking after the end of the list
		//state: 1 - 2 - 3 - 4
		//returns error code 2
		cout << "test 2:" << endl;
		set_state_4_vals();
		idx = 5;

		testList->print_state();
		dat = testList->peek(idx);
		if (dat->error == 1)
		{
			cout << "List empty. No values to return." << endl;
		}
		else if (dat->error == 2)
		{
			cout << "Index outside list. Unable to return value." << endl;
		}
		else
		{
			cout << "Item at index " << idx << ": " << dat->value << endl;
		}

		cout << endl;

		//############################################################################

		//test 3: looking before the beginning of the list
		//state: 1 - 2 - 3 - 4
		//returns error code 2
		cout << "test 3:" << endl;
		set_state_4_vals();
		idx = -1;

		testList->print_state();
		dat = testList->peek(idx);
		if (dat->error == 1)
		{
			cout << "List empty. No values to return." << endl;
		}
		else if (dat->error == 2)
		{
			cout << "Index outside list. Unable to return value." << endl;
		}
		else
		{
			cout << "Item at index " << idx << ": " << dat->value << endl;
		}

		cout << endl;

		//############################################################################

		//test 4: look at valid value in list
		//state: 1 - 2 - 3 - 4
		//returns value 3
		cout << "test 4:" << endl;
		set_state_4_vals();
		idx = 3;

		testList->print_state();
		dat = testList->peek(idx);
		if (dat->error == 1)
		{
			cout << "List empty. No values to return." << endl;
		}
		else if (dat->error == 2)
		{
			cout << "Index outside list. Unable to return value." << endl;
		}
		else
		{
			cout << "Item at index " << idx << ": " << dat->value << endl;
		}

		cout << endl;

		//############################################################################

		return 0;
	}


	int test_print_state()
	{
		cout << "testing print_state():" << endl;

		//############################################################################

		//test 1: empty
		//state: empty
		//prints:
		/*
		List state:
			empty
		*/
		cout << "test 1:" << endl;

		set_state_empty();
		testList->print_state();

		cout << endl;

		//############################################################################

		//test 2: single value
		//state: 1
		//prints:
		/*
		List state:
			<null>
			<address1>: 1
			<null>
		*/
		cout << "test 2:" << endl;

		set_state_1_val();
		testList->print_state();

		cout << endl;

		//############################################################################

		//state 3: multivalue
		//state: 1 - 2 - 3 - 4
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
		cout << "test 3:" << endl;

		set_state_4_vals();
		testList->print_state();

		cout << endl;

		//############################################################################

		return 0;
	}
};
