#include <iostream>
#include <string>
#include "linked_stack.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

//using node::link;

int get_stack_state(Stack* stack)
{
	node* nodePtr = stack->start;

	cout << "Current Stack State:" << endl;

	if (nodePtr == nullptr)
	{
		cout << "Empty" << endl;
		return 0;
	}

	int i = 0;
	while (nodePtr->link != nullptr)
	{
		cout << nodePtr->value << " - ";
		i++;
		nodePtr = nodePtr->link;
	}
	cout << nodePtr->value << endl;
	nodePtr = nodePtr->link;

	return i + 1;
}


int main(void)
{
	Stack* testStack = new Stack;
	int* p; //temporary variable to catch the returns of pop() and peek()

	// new stack state: empty
	cout << "Length of stack: " << get_stack_state(testStack) << endl << endl;

	//test peek()
	//01: returns error/null; stack state remains unchanged
	cout << "peeking..." << endl;
	p = testStack->peek();
	if (p == nullptr)
	{
		cout << "Error peeking: Stack empty" << endl;
	}
	else
	{
		cout << "Peeked value:" << (int)p << endl;
	}
	cout << "Length of stack: " << get_stack_state(testStack) << endl << endl;

	
	//test pop()
	//01: should return error/null; stack state remains unchanged
	cout << "popping..." << endl;
	p = testStack->pop();
	if (p == nullptr)
	{
		cout << "Error popping: Stack empty" << endl;
	}
	else
	{
		cout << "Popped value:" << (int)p << endl;
	}
	cout << "Length of stack: " << get_stack_state(testStack) << endl << endl;


	//test push()
	//01: new stack state: 1; length 1
	cout << "pushing value 1" << endl;
	testStack->push(1);
	cout << "Length of stack: " << get_stack_state(testStack) << endl << endl;
	//02: new stack state: 1 - 2; length 2
	cout << "pushing value 2" << endl;
	testStack->push(2);
	cout << "Length of stack: " << get_stack_state(testStack) << endl << endl;
	//03: new stack state: 1 - 2 - 4 - 8 - 16; legth 5
	cout << "pushing values 4, 8, and 16" << endl;
	testStack->push(4);
	testStack->push(8);
	testStack->push(16);
	cout << "Length of stack: " << get_stack_state(testStack) << endl << endl;

	//test peek()
	//02: returns 1; stack state remains unchanged;
	cout << "peeking..." << endl;
	p = testStack->peek();
	if (p == nullptr)
	{
		cout << "Error peeking: Stack empty" << endl;
	}
	else
	{
		cout << "Peeked value:" << (int)p << endl;
	}
	cout << "Length of stack: " << get_stack_state(testStack) << endl << endl;


	//test pop()
	//02: returns 1; new stack state: 2 - 4 - 8 - 16; length 4
	cout << "popping" << endl;
	p = testStack->peek();
	if (p == nullptr)
	{
		cout << "Error popping: Stack empty" << endl;
	}
	else
	{
		cout << "Popped value:" << (int)p << endl;
	}
	cout << "Length of stack: " << get_stack_state(testStack) << endl << endl;


	return 0;
}
