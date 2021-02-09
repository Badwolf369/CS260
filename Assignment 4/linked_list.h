#include <iostream>
#include <string>

#include "node.h"
#include "return_data.h"

#ifndef LINKED_LIST_INCLUDE
#define LINKED_LIST_INCLUDE

using std::string;
using std::cout;
using std::endl;

class LinkedList
{
private:
	node* start;
	node* end;
	int len = 0;

	node* locate(int index)
	{
		//refactor indexing into an i counter

		//if its not in the list
		if (index > len || index < 0)
		{
			//equivalent to an error
			return nullptr;
		}

		//if its in the first half of the list
		else if (index <= (len / 2))
		{
			//start at the beginning
			node* nodeptr = start;
			int i = 0;

			//then walk forwards until you find the correct position
			while (i != index)
			{
				nodeptr = nodeptr->link_r;
				i++;
			}

			return nodeptr;
		}

		//if its in the second half of the list
		else if (index > (len / 2))
		{
			//start at the end
			node* nodeptr = end;
			int i = len;

			//then walk backwards until you find the correct position
			while (i != index)
			{
				nodeptr = nodeptr->link_l;
				i--;
			}

			return nodeptr;
		}
	}

	void link_nodes(node* nodeL, node* nodeR)
	{
		//create a proper link between 2 nodes
		nodeL->link_r = nodeR;
		nodeR->link_l = nodeL;
	}


	friend class TestEnv;


public:
	node* push(int value, int index = -1)
	{
		//create new node
		node* newnode = new node;
		newnode->value = value;

		//create list structure if the list was empty
		if (len == 0) {
			start = newnode;
			end = newnode;

			len++;
			return newnode;
		}

		//if index unspecified 
		if (index < 0)
		{
			//attach node to the end
			link_nodes(end, newnode);
			end = newnode;

			len++;
			return newnode;
		}
		//if index outside list
		else if (index > len)
		{
			//attach node to end
			link_nodes(end, newnode);
			end = newnode;

			len++;
			return newnode;
		}
		//if index is valid
		else
		{
			//shove node into specified index and shift the list to the right
			node* oldNodeR = locate(index);
			node* oldNodeL = oldNodeR->link_l;

			link_nodes(oldNodeL, newnode);
			link_nodes(newnode, oldNodeR);

			len++;
			return newnode;
		}
	}

	return_data* pull(int index)
	{
		return_data* dat = new return_data;
		//error 0: no error
		//error 1: empty list
		//error 2: index outside list
		//error 3: undefined error

		//check if list is empty
		if (len == 0)
		{
			//return error
			dat->error = 1;
			return dat;
		}

		//verify index is in list
		if (index < 0 || index > len)
		{
			//return error
			dat->error = 2;
			return dat;
		}
		else
		{
			//locate the node, pop it out, patch the hole, then delete it
			node* nodeptr = locate(index);
			link_nodes(nodeptr->link_l, nodeptr->link_r);
			dat->value = nodeptr->value;
			free(nodeptr);
			len--;

			return dat;
		}

		//if you somehow made it here, return error
		dat->error = 3;
		return dat;
	}

	return_data* peek(int index)
	{
		return_data* dat = new return_data;
		//error 0: no error
		//error 1: empty list
		//error 2: index outside list
		//error 3: undefined error

		//check if list is empty
		if (len == 0)
		{
			//return 'empty list' error
			dat->error = 1;
			return dat;
		}

		//verify index is in list
		if (index < 0 || index > len)
		{
			//return 'index outside list' error
			dat->error = 2;
			return dat;
		}
		else
		{
			//locate specified index and return data without error tag
			node* nodeptr = locate(index);
			dat->value = nodeptr->value;
			return dat;
		}

		//if you somehow made it here, return 'undefined error' error
		dat->error = 3;
		return dat;
	}

	void print_state()
	{
		cout << "List state(len " << len << "):" << endl;

		if (len <= 0)
		{
			cout << "	empty" << endl << endl;
		}
		else
		{
			node* nodeptr = start;

			//print each item with a link
			for (int i = 0; i < len - 1; i++)
			{
				cout << "	" << nodeptr->link_l << endl;
				cout << "	" << nodeptr << ": " << nodeptr->value << endl;
				cout << "	" << nodeptr->link_r << endl;
				cout << "	    |" << endl;
				nodeptr = nodeptr->link_r;
			}
			//print last item without a forwards link
			cout << "	" << nodeptr->link_l << endl;
			cout << "	" << nodeptr << ": " << nodeptr->value << endl;
			cout << "	" << nodeptr->link_l << endl;
		}
	}
};

#endif