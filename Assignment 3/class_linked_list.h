#include <iostream>
#include <string>

using std::string;

class Node {
	string name;
	int value;

	Node* link = NULL;

	Node* enqueue(Node* newlink)
	{
		if (link == NULL)
		{
			link = newlink;
			return newlink;
		}
		else
		{
			return link->enqueue(newlink);
		}
	}
};
