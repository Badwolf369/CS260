#include <iostream>
#include <string>
#include "node.h"

using std::string;


class LinkedList {
	//beginning and end for ease of access
	node* start = nullptr;
	node* end = nullptr;


	//attach a node
	node* push(node* newnode)
	{
		//if list is empty then dont try to link
		if (end == nullptr)
		{
			start = newnode;
			end = newnode;
		}
		else
		{
			end->link = newnode;
			end = newnode;
		}
		return newnode;
	}


	//detach and free the first node
	node pop()
	{
		//check if list is empty
		if (start == nullptr)
		{
			//I wonder if I can create a warning to remind me to check that this doesnt return NULL...
			return {'\0', NULL, nullptr};
		}

		else
		{
			//grab and free the old first node
			node oldnode = *start;
			free(start);

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

			return oldnode;
		}
	}


	node* peek()
	{
		//check if list is empty
		if (start == nullptr)
		{
			//HEY! check if this return value is NULL!
			return nullptr;
		}
		else
		{
			return start;
		}
	}
};