#include <iostream>

#include "node.h"

using std::cout;
using std::endl;

#ifndef SMART_LIST_INCLUDE
#define SMART_LIST_INCLUDE

//incomplete and doesnt work at all
class BinaryTree {
private:
	node* root = nullptr;

	friend class TestEnv;

public:
	node* insert(int id, int value) {
		node* nodeptr = root;
		//if the tree is empty create the first node in the tree
		if (nodeptr == nullptr) {
			nodeptr = new node;

			nodeptr->id = id;
			nodeptr->value = value;
			root = nodeptr;
			return nodeptr;
		}

		for (;;) {
			//if the id matches
			if (nodeptr->id == id) {
				return nullptr;
			}
			//if the wanted id is larger
			else if (nodeptr->id < id) {
				//if theres no more tree to traverse, create a new node
				if (nodeptr->link_r == nullptr){
					node* newnode = new node;

					newnode->id = id;
					newnode->value = value;
					nodeptr->link_r = newnode;
					return newnode;
				}
				//otherwise just keep going
				else {
					nodeptr = nodeptr->link_r;
					continue;
				}
			}
			//if the wanted id is smaller
			else if (nodeptr->id > id) {
				//if theres no more tree to traverse, create a new node
				if (nodeptr->link_l == nullptr) {
					node* newnode = new node;

					newnode->id = id;
					newnode->value = value;
					nodeptr->link_l = newnode;
					return newnode;
				}
				//otherwise just keep going
				else {
					nodeptr = nodeptr->link_l;
					continue;
				}
			}
			else {
				//I honestly have no idea how to get to this error but the compiler yells at me when its not here
				cout << "you somehow broke this thing" << endl;
				return nullptr;
			}
		}
	}

	node* find(int id) {
		//should probably make this recursive but meh
		node* nodeptr = root;
		for (;;) {
			//if theres a case to end the loop
			if (nodeptr == nullptr || nodeptr->id == id) {
				return nodeptr;
			}
			//if the wanted id is bigger move up and to the right
			else if (nodeptr->id < id) {
				nodeptr = nodeptr->link_r;
				continue;
			}
			//if the wanted id is smaller, move down and to the left
			else if (nodeptr->id > id) {
				nodeptr = nodeptr->link_l;
				continue;
			}
		}
	}
	
	node* remove(int id) {
		node* nodeptr = find(id);

		//if the nodeptr is to the right of it's parent
		if (nodeptr->id > nodeptr->parent->id) {
			//if the selected node has no children
			if (nodeptr->link_r && nodeptr->link_l) {
				nodeptr->parent->link_r = nullptr;
				delete nodeptr;
			}
			//if the selected node has a child to the right
			else if (nodeptr->link_r && !nodeptr->link_l) {
				nodeptr->parent->link_r = nodeptr->link_r;
				nodeptr->link_r->parent = nodeptr->parent;
				delete nodeptr;
			}
			//if the selected nde has a child to the left
			else if (!nodeptr->link_r && nodeptr->link_l) {
				nodeptr->parent->link_r = nodeptr->link_l;
				nodeptr->link_l->parent = nodeptr->parent;
				delete nodeptr;
			}
		}
		else {
			if (nodeptr->link_r && nodeptr->link_l) {
				nodeptr->parent->link_l = nullptr;
				delete nodeptr;
			}
			//if the selected node has a child to the right
			else if (nodeptr->link_r && !nodeptr->link_l) {
				nodeptr->parent->link_l = nodeptr->link_r;
				nodeptr->link_r->parent = nodeptr->parent;
				delete nodeptr;
			}
			//if the selected nde has a child to the left
			else if (!nodeptr->link_r && nodeptr->link_l) {
				nodeptr->parent->link_l = nodeptr->link_l;
				nodeptr->link_l->parent = nodeptr->parent;
				delete nodeptr;
			}
		}

		
	}
};

#endif
