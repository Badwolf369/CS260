#include "node.h"


#ifndef SMART_LIST_INCLUDE
#define SMART_LIST_INCLUDE

class BinaryTree {
private:
	node* root = nullptr;

	node* traverse_rr(node* nodeptr, int id) {
		if (nodeptr == nullptr)
		{
			return nullptr;
		}
		else if (nodeptr->id == id)
		{
			return nodeptr;
		}
		else if (id > nodeptr->id)
		{
			traverse_rr(nodeptr->link_r, id);
		}
		else if (id < nodeptr->id)
		{
			traverse_rr(nodeptr->link_l, id);
		}
	}

	friend class TestEnv;

public:
	node* insert(int id, int value) {
		//check if node is equal
		//no: check node relativity
		//bigger: recurse right
		//smaller: recurse left
	}

	node* find(int id) {

	}
	
	node* remove(int id) {

	}
};

#endif
