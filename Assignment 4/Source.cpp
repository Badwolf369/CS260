#include <iostream>
#include <string>

#include "linked_list.h"
#include "node.h"

using std::string;
using std::cout;
using std::endl;


int main()
{
	LinkedList* mylist = new LinkedList;

	mylist->print_state();

	mylist->push(1);

	mylist->print_state();

	mylist->push(2);
	mylist->push(3);
	mylist->push(4);
	mylist->push(5);

	mylist->print_state();

	return 0;
}
