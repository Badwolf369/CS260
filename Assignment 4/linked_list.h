#include <iostream>
#include <string>

#include "node.h"

#ifndef LINKED_LIST_H_INCLUDE
#define LINKED_LIST_H_INCLUDE

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
		if (index > len)
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

	node* link_nodes(node* nodeL, node* nodeR)
	{
		//create a proper link between 2 nodes
		nodeL->link_r = nodeR;
		nodeR->link_l = nodeL;

		return NULL;
	}


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

	int pull(int index)
	{
		//check if list is empty
		if (len == 0)
		{
			//return error
			return -1;
		}

		//verify index is in list
		if (index < 0 || index > len)
		{
			//return error
			return -1;
		}
		else
		{
			//locate the node, pop it out, patch the hole, then delete it
			node* nodeptr = locate(index);
			link_nodes(nodeptr->link_l, nodeptr->link_r);
			free(nodeptr);
			len--;
			return 0;
		}
	}

	int* peek(int index)
	{
		//check if list is empty
		if (len == 0)
		{
			//return error
			return nullptr;
		}

		//verify index is in list
		if (index < 0 || index > len)
		{
			//return error
			return nullptr;
		}
		else
		{
			//locate specified index and return pointer to value
			node* nodeptr = locate(index);
			return &(nodeptr->value);
		}
	}

	void print_state()
	{
		cout << "List state:" << endl;

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
				cout << "		|" << endl;
				nodeptr = nodeptr->link_r;
			}
			//print last item without a forwards link
			cout << "	" << nodeptr->link_l << endl;
			cout << "	" << nodeptr << ": " << nodeptr->value << endl;
			cout << "	" << nodeptr->link_l << endl << endl;
		}
	}

	node* set_state(node* newStart, node* newEnd, int newLen)
	{
		start = newStart;
		end = newEnd;
		len = newLen;
	}
};

#endif