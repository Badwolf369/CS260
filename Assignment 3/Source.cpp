#include <iostream>
#include <string>
#include "struct_linked_list.h"
#include "working_linked_list.h"

using std::string;
//using node::link;


int main(void)
{
	node start = { "starter", 1 };
	node mid = { "middle", 2 };
	start.link = &mid;
	node end = { "end", 3 };
	mid.link = &end;

	node* current = &start;
	for (int i = 0; ; i++)
	{
		std::cout << "value " << current->name << ":" << current->value << std::endl;
		if (current->link != NULL)
		{
			current = current->link;
		}
		else
		{
			break;
		}
	}

	return 0;
}
