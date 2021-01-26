#include <iostream>
#include <string>
#include "node.h"

using std::string;


class Stack {
public:
	//beginning and end for ease of access
	node* start = nullptr;
	node* end = nullptr;

	int len = 0;

	//attach a node
	node* push(int value)
	{
		node* newnode = new node;
		newnode->value = value;
		//if list is empty then dont try to link
		len++;
		if (end == nullptr)
		{
			start = newnode;
			end = newnode;
			return newnode;
		}
		else
		{
			end->link = newnode;
			end = newnode;
			return newnode;
		}
		//equivalent to an error
		return nullptr;
	}


	//detach and free the first node
	int* pop()
	{
		//check if list is empty
		if (start == nullptr)
		{
			//equivalent to an error
			return nullptr;
		}

		else
		{
			//grab and free the old first node
			node oldnode = *start;
			free(start);
			len--;

			//adjust the wrapper
			if (oldnode.link == nullptr)
			{
				start = nullptr;
				end = nullptr;
			}
			else
			{
				start = oldnode.link;
			}

			//I dont know how this works but it does so ¯\_('-')_/¯
			return (int*) oldnode.value;
		}
	}


	int* peek()
	{
		//check if list is empty
		if (start == nullptr)
		{
			//equivalent to an error
			return nullptr;
		}
		else
		{
			return (int*) start->value;
		}
	}
};