#ifndef NODE_INCLUDE
#define NODE_INCLUDE

struct node {
	int id = 0;
	int value;

	node* parent = nullptr;
	node* link_l = nullptr;
	node* link_r = nullptr;
};

#endif
