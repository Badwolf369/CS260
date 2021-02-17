#ifndef NODE_INCLUDE
#define NODE_INCLUDE

struct node {
	int value;

	node* parent;
	node* link_l;
	node* link_r;
};

#endif
