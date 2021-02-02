#ifndef NODE_H_INCLUDE
#define NODE_H_INCLUDE

struct node {
	int value;

	node* link_l = nullptr;
	node* link_r = nullptr;
};

#endif