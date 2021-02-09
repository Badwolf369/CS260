//learned about the include guards here (first answer by Adam Zalcman): https://stackoverflow.com/questions/12928919/including-a-header-file-twice-in-c
//learned how to use them from here: https://riptutorial.com/cplusplus/example/3525/include-guards

#ifndef NODE_H_INCLUDE
#define NODE_H_INCLUDE

struct node {
	int value = 0;

	node* link_l = nullptr;
	node* link_r = nullptr;
};

#endif