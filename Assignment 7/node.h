#include <string>

using std::string;

#ifndef NODE_H_INCLUDE
#define NODE_H_INCLUDE

struct node {
	unsigned long id = 0;
	string CollisionCode = "";

	int value = 0;

	node* parent = nullptr;
	node* child_r = nullptr;
	node* child_l = nullptr;
	node* sibling_r = nullptr;
	node* sibling_l = nullptr;
};

#endif