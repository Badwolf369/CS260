#ifndef NODE_INCLUDE
#define NODE_INCLUDE

struct node {
	int id;
	int Value;

	node* parent;
	node* link_l;
	node* link_r;
};

#endif
