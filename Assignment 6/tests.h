#include <iostream>


#include "binary_tree.h"


using std::cout;
using std::endl;


#ifndef TESTS_INCLUDE
#define TEST_INCLUDE

class TestEnv {
private:
	BinaryTree* testList = new BinaryTree;

	void set_state_empty() {
		// yeah this function is garbage and inneficient but its just for testig so I cant be bothered to fix it.
		if (testList->root != nullptr)
		{
			if (testList->root->link_r != nullptr)
			{
				if (testList->root->link_r->link_r != nullptr)
				{
					delete testList->root->link_r->link_r;
				}
				if (testList->root->link_r->link_l != nullptr)
				{
					delete testList->root->link_r->link_l;
				}

				delete testList->root->link_r;
			}
			if (testList->root->link_l != nullptr)
			{
				if (testList->root->link_l->link_r != nullptr)
				{
					delete testList->root->link_l->link_r;
				}
				if (testList->root->link_l->link_l != nullptr)
				{
					delete testList->root->link_l->link_l;
				}

				delete testList->root->link_l;
			}

			delete testList->root;
			testList->root = nullptr;
		}
	}

	void set_state_1_item() {
		set_state_empty();

		node* startNode = new node;
		startNode->id = 1;
		startNode->value = 1;

		testList->root = startNode;
	}

	void set_state_consecutive() {
		set_state_empty();

		node* startNode = new node;
		startNode->id = 4;
		startNode->value = 4;

		testList->root = startNode;

		node* node1 = new node;
		node1->id = 1;
		node1->value = 1;
		node* node2 = new node;
		node2->id = 2;
		node2->value = 2;
		node* node3 = new node;
		node3->id = 3;
		node3->value = 3;
		node* node5 = new node;
		node5->id = 5;
		node5->value = 5;
		node* node6 = new node;
		node6->id = 6;
		node6->value = 6;
		node* node7 = new node;
		node7->id = 7;
		node7->value = 7;

		startNode->link_l = node2;
		node2->parent = startNode;
		node2->link_l = node1;
		node1->parent = node2;
		node2->link_r = node3;
		node3->parent = node2;

		startNode->link_r = node6;
		node6->parent = startNode;
		node6->link_l = node5;
		node5->parent = node6;
		node6->link_r = node7;
		node7->parent = node6;
	}

	void set_state_unconsecutive() {
		set_state_empty();

		node* startNode = new node;
		startNode->id = 4;
		startNode->value = 4;

		testList->root = startNode;

		node* node1 = new node;
		node1->id = 0;
		node1->value = 0;
		node* node2 = new node;
		node2->id = 1;
		node2->value = 2;
		node* node3 = new node;
		node3->id = 3;
		node3->value = 3;
		node* node5 = new node;
		node5->id = 6;
		node5->value = 6;
		node* node6 = new node;
		node6->id = 7;
		node6->value = 7;
		node* node7 = new node;
		node7->id = 9;
		node7->value = 9;

		startNode->link_l = node2;
		node2->parent = startNode;
		node2->link_l = node1;
		node1->parent = node2;
		node2->link_r = node3;
		node3->parent = node2;

		startNode->link_r = node6;
		node6->parent = startNode;
		node6->link_l = node5;
		node5->parent = node6;
		node6->link_r = node7;
		node7->parent = node6;
	}

	void set_state_missing() {
		set_state_empty();

		node* startNode = new node;
		startNode->id = 4;
		startNode->value = 4;

		testList->root = startNode;

		node* node2 = new node;
		node2->id = 2;
		node2->value = 2;
		node* node5 = new node;
		node5->id = 5;
		node5->value = 5;
		node* node6 = new node;
		node6->id = 6;
		node6->value = 6;

		startNode->link_l = node2;
		node2->parent = startNode;

		startNode->link_r = node6;
		node6->parent = startNode;
		node6->link_l = node5;
		node5->parent = node6;
	}

	void print_node_rr(int lvl, node* nodeptr) {
		//works closely with, in fact only with print_state()
		//reeeeeally wish I could use nested functions
		if (nodeptr == nullptr)
		{
			//add proper spacing for the level of the item
			for (int i = 0; i < lvl; i++)
			{
				cout << "	";
			}
			//signify this node is null
			cout << "x" << endl;
			//end this chain
			return;
		}
		else
		{
			//move to the right end of this chain
			print_node_rr(lvl + 1, nodeptr->link_r);
			//add proper spacing and print this item
			for (int i = 0; i < lvl; i++)
			{
				cout << "	";
			}
			cout << nodeptr->id << ": " << nodeptr->value << endl;
			//move to the left half of this chain
			print_node_rr(lvl + 1, nodeptr->link_l);
		}
	}

	void print_state() {

		cout << "list state:" << endl;

		if (testList->root == nullptr)
		{
			cout << "	Empty" << endl;
		}
		else
		{
			print_node_rr(0, testList->root);
		}
	}


public:
	void test_data_structure() {
		node* startNode = new node;
		startNode->id = 4;
		startNode->value = 4;

		testList->root = startNode;

		node* node1 = new node;
		node1->id = 1;
		node1->value = 1;
		node* node2 = new node;
		node2->id = 2;
		node2->value = 2;
		node* node3 = new node;
		node3->id = 3;
		node3->value = 3;
		node* node5 = new node;
		node5->id = 5;
		node5->value = 5;
		node* node6 = new node;
		node6->id = 6;
		node6->value = 6;
		node* node7 = new node;
		node7->id = 7;
		node7->value = 7;

		startNode->link_l = node2;
		node2->parent = startNode;
		node2->link_l = node1;
		node1->parent = node2;
		node2->link_r = node3;
		node3->parent = node2;

		startNode->link_r = node6;
		node6->parent = startNode;
		node6->link_l = node5;
		node5->parent = node6;
		node6->link_r = node7;
		node7->parent = node6;
		//add breakpoint right here. run in debug mode and check each of the node variables.
		//startnode should link left to node2 and right to node6
		//node2 should link left to node1 and right to node3
		//node6 should link left to node5 and right to node7
	}
	void test_find() {
		int inp;
		node* out;

		cout << endl << "Testing find()" << endl;

		//Test 1: find item in empty tree
		//starting state: empty
		//input: 1
		//output: error
		cout << "Test 1" << endl;

		set_state_empty();
		cout << "starting";
		print_state();
		inp = 1;
		cout << "input: " << inp << endl;

		out = testList->find(inp);
		if (out == nullptr)
		{
			cout << "Error, unable to find item with id: " << inp << endl;
		}
		else
		{
			cout << "Returned value: " << out->value << endl;
		}

		//Test 2: find item not in tree
		//tree state : consecutive
		//input: 9
		//output: error
		cout << "Test 2" << endl;

		set_state_consecutive();
		print_state();
		inp = 9;
		cout << "input: " << inp << endl;

		out = testList->find(inp);
		if (out == nullptr)
		{
			cout << "Error, unable to find item with id: " << inp << endl;
		}
		else
		{
			cout << "Returned value: " << out->value << endl;
		}

		//Test 3: find root
		//starting state: consecutive
		//input: 4
		//output: 4
		cout << "Test 3" << endl;

		set_state_consecutive();
		print_state();
		inp = 4;
		cout << "input: " << inp << endl;

		out = testList->find(inp);
		if (out == nullptr)
		{
			cout << "Error, unable to find item with id: " << inp << endl;
		}
		else
		{
			cout << "Returned value: " << out->value << endl;
		}

		//Test 4: find item in middle layers
		//starting state: consecutive
		//input: 6
		//output: 6
		cout << "Test 4" << endl;

		set_state_consecutive();
		print_state();
		inp = 6;
		cout << "input: " << inp << endl;

		out = testList->find(inp);
		if (out == nullptr)
		{
			cout << "Error, unable to find item with id: " << inp << endl;
		}
		else
		{
			cout << "Returned value: " << out->value << endl;
		}

		//Test 5: find item on a final layer
		//starting state: consecutive
		//input: 3
		//output: 3
		cout << "Test 5" << endl;

		set_state_consecutive();
		print_state();
		inp = 3;
		cout << "input: " << inp << endl;

		out = testList->find(inp);
		if (out == nullptr)
		{
			cout << "Error, unable to find item with id: " << inp << endl;
		}
		else
		{
			cout << "Returned value: " << out->value << endl;
		}
	}

	void test_insert()
	{
		int inp;
		node* out;

		cout << endl << "Testing insert()" << endl;

		//Test 1: insert item in empty tree
		//starting state: empty
		//final state:
		//	1
		//input: 1
		//output: 1
		cout << "Test 1" << endl;

		set_state_empty();
		print_state();
		inp = 1;
		cout << "input: " << inp << endl;

		out = testList->insert(inp, inp);
		if (out == nullptr)
		{
			cout << "Error, unable to insert item with id: " << inp << endl;
		}
		else
		{
			cout << "Returned value: " << out->value << endl;
		}

		print_state();

		//Test 2: insert item already in tree
		//starting state: consecutive
		//final state: unchanged
		//input: 3
		//output: 3
		cout << "Test 2" << endl;

		set_state_consecutive();
		print_state();
		inp = 3;
		cout << "input: " << inp << endl;

		out = testList->insert(inp, inp);
		if (out == nullptr)
		{
			cout << "Error, unable to insert item with id: " << inp << endl;
		}
		else
		{
			cout << "Returned value: " << out->value << endl;
		}

		print_state();

		//Test 3: insert item normally
		//starting state: consecutive
		//final state:
		//				8
		//			7
		//		6
		//			5
		//	4
		//			3
		//		2
		//			1
		//input: 8
		//output: 8
		cout << "Test 3" << endl;

		set_state_consecutive();
		print_state();
		inp = 8;
		cout << "input: " << inp << endl;

		out = testList->insert(inp, inp);
		if (out == nullptr)
		{
			cout << "Error, unable to insert item with id: " << inp << endl;
		}
		else
		{
			cout << "Returned value: " << out->value << endl;
		}

		print_state();
	}

	void test_remove()
	{
		int inp;
		node* out;

		cout << endl << "Testing find()" << endl;

		//Test 1: Remove item from empty list
		//starting state: state 1
		//final state: unchanged
		//input: 1
		//output: error
		cout << "Test 1" << endl;

		set_state_empty();
		print_state();
		inp = 1;
		cout << "input: " << inp << endl;

		out = testList->insert(inp, inp);
		if (out == nullptr)
		{
			cout << "Error, unable to remove item with id: " << inp << endl;
		}
		else
		{
			cout << "Returned value: " << out->value << endl;
		}

		print_state();

		//Test 2: Remove item that doesnt exist in list
		//starting state: state 3
		//final state: unchanged
		//input: 8
		//output: error
		cout << "Test 2" << endl;

		set_state_consecutive();
		print_state();
		inp = 8;
		cout << "input: " << inp << endl;

		out = testList->insert(inp, inp);
		if (out == nullptr)
		{
			cout << "Error, unable to remove item with id: " << inp << endl;
		}
		else
		{
			cout << "Returned value: " << out->value << endl;
		}

		print_state();

		//Test 3: Remove item with no children
		//starting state: state 5
		//final state:
		//		6
		//	4
		//		2
		//input: 5
		//output: 5
		cout << "Test 3" << endl;

		set_state_missing();
		print_state();
		inp = 5;
		cout << "input: " << inp << endl;

		out = testList->insert(inp, inp);
		if (out == nullptr)
		{
			cout << "Error, unable to remove item with id: " << inp << endl;
		}
		else
		{
			cout << "Returned value: " << out->value << endl;
		}

		print_state();

		//Test 4: Remove item with 1 child
		//starting state: state 5
		//final state:
		//		5
		//	4
		//		2
		//input: 6
		//output: 6
		cout << "Test 4" << endl;

		set_state_missing();
		print_state();
		inp = 6;
		cout << "input: " << inp << endl;

		out = testList->insert(inp, inp);
		if (out == nullptr)
		{
			cout << "Error, unable to remove item with id: " << inp << endl;
		}
		else
		{
			cout << "Returned value: " << out->value << endl;
		}

		print_state();

		//Test 5 : Remove item with 2 children
		//starting state : state 3
		//final state :
		//		6
		//	5
		//		2
		//input : 4
		//output : 4
		cout << "Test 5" << endl;

		set_state_missing();
		print_state();
		inp = 4;
		cout << "input: " << inp << endl;

		out = testList->insert(inp, inp);
		if (out == nullptr)
		{
			cout << "Error, unable to remove item with id: " << inp << endl;
		}
		else
		{
			cout << "Returned value: " << out->value << endl;
		}

		print_state();
	}
};

#endif