#pragma once

#include <string>
#include <map>

using namespace std;

struct vertex {
	int value = 0;

	string id = "";

	map<string, int> edges;
};
