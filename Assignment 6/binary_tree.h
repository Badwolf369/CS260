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
	node* insert_rr(int id, int value, node* nodeptr = nullptr) {
		if (nodeptr == nullptr)
		{
			return insert_rr(id, value, root);
		}
		else if (nodeptr->id == id)
		{
			return nullptr;
		}
		else if (id > nodeptr->id)
		{
			return insert_rr(id, value, nodeptr->link_r);
		}
		else if (id < nodeptr->id)
		{
			traverse_rr(nodeptr->link_l, id);
		}
	}

	node* find(int id) {

	}
	
	node* remove(int id) {

	}
};

#endif
