#pragma once

#include <string>
#include <map>

#include "vertex.h"

using std::map;
using std::string;

class Graph {
private:
	map<string, vertex> vertices;

	friend class TestEnv;

public:
	int add_vertex(string name, int value) {
		//Allocate space for a vertex with name 'name' and value 'value', but with no edges.
		//Return:
		//	0 - success
		//	1 - vertex with 'name' already exists
		// -1 - unknown error

		if (vertices.find(name) != vertices.end()) {
			return 1;
		}
		else {
			vertex newVertex = { value, name };
			vertices.emplace(name, newVertex);
			return 0;
		}
	}

	int remove_vertex(string name) {
		//Locate and delete the vertex specified with 'name' and also remove all edges pointing to it.
		//Return:
		//	0 - success
		//	1 - no vertex with 'name' exists
		// -1 - unknown error

		if (vertices.find(name) == vertices.end()) {
			return 1;
		}
		else {
			map<string, vertex>::iterator it;

			for (it = vertices.begin(); it != vertices.end(); it++) {
				if (it->second.edges.find(name) != it->second.edges.end()) {
					it->second.edges.erase(name);
				}
			}

			vertices.erase(name);
		}
	}

	int add_edge(string source, string destination, int weight) {
		//Add the vertex with name 'desination' to the vertex with name 'source''s edge list with the attached weight of 'weight'.
		//Return:
		//	0 - success
		//	1 - edge already exists
		//	2 - 'destination' does not exist
		//	3 - 'source' does not exist
		// -1 - unknown error

		//verify 'source' and 'destination' exist
		if (vertices.find(source) == vertices.end()) {
			return 3;
		}
		else if (vertices.find(destination) == vertices.end()) {
			return 2;
		}
		else
		{
			map<string, int>* sourceEdges = &(vertices[source].edges);
			if (sourceEdges->find(destination) != sourceEdges->end()) {
				return 1;
			}
			else {
				sourceEdges->emplace(destination, weight);
				return 0;
			}
		}
	}

	int remove_edge(string source, string destination) {
		//Remove edge which points to vertex with name 'destination' from vertex with name 'source'.
		//Return:
		//    0 - success
		//	  1 - no edge pointing to 'desination' exists
		//	  2 - source does not exist
		//   -1 - unknown error

		if (vertices.find(source) == vertices.end()) {
			return 2;
		}
		else {
			map<string, int>* sourceEdges = &(vertices[source].edges);

			if (sourceEdges->find(destination) == sourceEdges->end()) {
				return 1;
			}
			else {
				sourceEdges->erase(destination);
			}
		}
	}
};