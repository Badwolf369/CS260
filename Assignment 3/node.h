#include <iostream>
#include <string>

using std::string;

struct node {
	string name;
	int value;

	node *link = nullptr;
};

