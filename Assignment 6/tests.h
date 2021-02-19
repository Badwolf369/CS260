#include "binary_tree.h"


#ifndef TESTS_INCLUDE
#define TEST_INCLUDE

class TestEnv {
private:
	BinaryTree* testList = new BinaryTree;

	void set_state_empty() {
		delete testList->root->link_r->link_r;
		delete testList->root->link_r->link_l;
		delete testList->root->link_l->link_r;
		delete testList->root->link_l->link_l;

		delete testList->root->link_r;
		delete testList->root->link_l;

		delete testList->root;

		testList->root = nullptr;
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
		testList->find();
	}
};

#endif