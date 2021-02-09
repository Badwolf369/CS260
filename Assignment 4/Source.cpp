#include <iostream>
#include <string>

#include "linked_list.h"
#include "node.h"
#include "tests.h"

using std::string;
using std::cout;
using std::endl;


int main()
{
	TestEnv* tests = new TestEnv;

	tests->test_print_state();

	tests->test_peek();

	return 0;
}
