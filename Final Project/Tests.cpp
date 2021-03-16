#include "tests.h"

int main() {
	TestEnv testing_environment;

	testing_environment.test_add_vertex();
	testing_environment.test_remove_vertex();
	testing_environment.test_add_edge();
	testing_environment.test_remove_edge();

	return 0;
}
