#pragma once

#include <iostream>
#include <string>

#include "graph.h"
#include "vertex.h"

using std::map;
using std::endl;
using std::cout;
using std::string;
using std::next;

class TestEnv
{
private:
	Graph testGraph;

	void print_state() {
		if (testGraph.vertices.empty()) {
			cout << "Empty" << endl;
			return;
		}
		else {
			map<string, vertex>* vertices = &(testGraph.vertices);
			map<string, vertex>::iterator vert;

			for (vert = vertices->begin(); vert != vertices->end(); vert++) {
				cout << "(" << vert->first << ")";

				map<string, int>* edges = &(vert->second.edges);
				map<string, int>::iterator edge;

				if (edges->size() == 0) {
					cout << endl;
				}
				else {
					for (edge = edges->begin(); next(edge) != edges->end(); edge++) {
						cout << "--" << edge->second << "-->(" << edge->first << ")";
					}

					cout << "--" << edge->second << "-->(" << edge->first << ")" << endl;
				}
			}
		}
	}

	void set_state_0() {
		testGraph.vertices.clear();
	}

	void set_state_1() {
		//Make sure the graph is empty beforehand
		testGraph.vertices.clear();

		//Create the new vertex
		vertex newVertex = { 1, "A" };

		//Add the vertex to the graph
		testGraph.vertices.emplace(newVertex.id, newVertex);
	}

	void set_state_2() {
		//Make sure the graph is empty beforehand
		testGraph.vertices.clear();

		//Create all the vertices
		vertex newVertexA = { 1, "A" };
		vertex newVertexB = { 2, "B" };
		vertex newVertexC = { 3, "C" };
		vertex newVertexD = { 4, "D" };
		vertex newVertexE = { 5, "E" };

		//Add A's edges
		newVertexA.edges.emplace("B", 1);
		newVertexA.edges.emplace("C", 1);
		newVertexA.edges.emplace("D", 1);

		//Add B's edges
		newVertexB.edges.emplace("C", 1);

		//Add C's edges
		newVertexC.edges.emplace("A", 1);
		newVertexC.edges.emplace("D", 1);

		//Add D's edges
		newVertexD.edges.emplace("E", 1);

		//Add E's edges
		newVertexE.edges.emplace("C", 1);

		//Add all the vertices to the graph
		testGraph.vertices.emplace(newVertexA.id, newVertexA);
		testGraph.vertices.emplace(newVertexB.id, newVertexB);
		testGraph.vertices.emplace(newVertexC.id, newVertexC);
		testGraph.vertices.emplace(newVertexD.id, newVertexD);
		testGraph.vertices.emplace(newVertexE.id, newVertexE);
	}

public:
	//Test add_vertex()
	void test_add_vertex() {
		string inp1;
		int inp2;

		int err;

		//Test 1: Add to empty graph
		//Test State : Empty
		//Input : "A", 1
		//Output : 0
		//Output State :
		//	(A)
		inp1 = "A";
		inp2 = 1;
		set_state_0();

		cout << endl << "Test 1: Add vertex to empty graph" << endl;
		cout << "Starting test state:" << endl;
		print_state();
		cout << "Input: \"" << inp1 << "\", " << inp2 <<endl;
		cout << "Output: ";

		err = testGraph.add_vertex(inp1, inp2);
		if (err == 1) {
			cout << "Error: Vertex already exists" << endl;;
		}
		else {
			cout << "Success!" << endl;
		}

		cout << "Output state:" << endl;
		print_state();


		//Test 2: Add to graph with other items
		//Test State : 5 vertices & 8 edges(unweighted)
		//Input : "F", 6
		//Output : 0
		//Output State :
		//	(A)--1-- > (B)--1-- > (C)--1-- > (D)
		//	(B)--1-- > (C)
		//	(C)--1-- > (A)--1-- > (D)
		//	(D)--1-- > (E)
		//	(E)--1-- > (C)
		//	(F)
		inp1 = "F";
		inp2 = 6;
		set_state_2();

		cout << endl << "Test 2: Add to graph with other items" << endl;
		cout << "Starting test state:" << endl;
		print_state();
		cout << "Input: \"" << inp1 << "\", " << inp2 << endl;
		cout << "Output: ";

		err = testGraph.add_vertex(inp1, inp2);
		if (err == 1) {
			cout << "Error: Vertex already exists" << endl;;
		}
		else {
			cout << "Success!" << endl;
		}

		cout << "Output state:" << endl;
		print_state();


		//Test 3: Add vertex that already exists
		//Test State : 5 vertices & 8 edges(unweighted)
		//Input : "D", 4
		//Output : 1
		//Output State : Unchanged
		inp1 = "D";
		inp2 = 4;
		set_state_2();

		cout << endl << "Test 3: Add vertex that already exists" << endl;
		cout << "Starting test state:" << endl;
		print_state();
		cout << "Input: \"" << inp1 << "\", " << inp2 << endl;
		cout << "Output: ";

		err = testGraph.add_vertex(inp1, inp2);
		if (err == 1) {
			cout << "Error: Vertex already exists" << endl;;
		}
		else {
			cout << "Success!" << endl;
		}

		cout << "Output state:" << endl;
		print_state();
	}

	//Test remove_vertex()
	void test_remove_vertex() {
		string inp;

		int err;

		//Test 1 : Remove vertex from graph with multiple vertices
		//Test State : 5 vertices & 8 edges(unweighted)
		//Input : "C"
		//Output : 0
		//Output State :
		//	(A)--1-- > (B)--1-- > (D)
		//	(B)
		//	(D)--1-- > (E)
		//	(E)
		inp = "C";
		set_state_2();

		cout << endl << "Test 1: Remove vertex from graph with multiple vertices" << endl;
		cout << "Starting test state:" << endl;
		print_state();
		cout << "Input: \"" << inp << "\"" << endl;
		cout << "Output: ";

		err = testGraph.remove_vertex(inp);
		if (err == 1) {
			cout << "Error: No such vertex exists" << endl;
		}
		else {
			cout << "Success!" << endl;
		}

		cout << "Output state:" << endl;
		print_state();

		//Test 2: Remove vertex from graph with only 1 vertex
		//Test State : 1 vertex
		//Input : "A"
		//Output : 0
		//Output State : Empty
		inp = "A";
		set_state_1();

		cout << endl << "Test 2: Remove vertex from graph with only 1 vertex" << endl;
		cout << "Starting test state:" << endl;
		print_state();
		cout << "Input: \"" << inp << "\"" << endl;
		cout << "Output: ";

		err = testGraph.remove_vertex(inp);
		if (err == 1) {
			cout << "Error: No such vertex exists" << endl;
		}
		else {
			cout << "Success!" << endl;
		}

		cout << "Output state:" << endl;
		print_state();

		//Test 3 : Remove vertex that does not exist
		//Test State : Empty
		//Input : "A"
		//Output : 1
		//Output State : Unchanged
		inp = "A";
		set_state_0();

		cout << endl << "Test 3: Remove vertex that does not exist" << endl;
		cout << "Starting test state:" << endl;
		print_state();
		cout << "Input: \"" << inp << "\"" << endl;
		cout << "Output: ";

		err = testGraph.remove_vertex(inp);
		if (err == 1) {
			cout << "Error: No such vertex exists" << endl;
		}
		else {
			cout << "Success!" << endl;
		}

		cout << "Output state:" << endl;
		print_state();
	}

	//Test add_edge()
	void test_add_edge() {
		string inp1;
		string inp2;
		int inp3;

		int err;

		//Test 1 : Add edge properly
		//Test State : 5 vertices & 8 edges(unweighted)
		//Input : B, D, 1
		//Output : 0
		//Output State :
		//	(A)--1-- > (B)--1-- > (C)--1-- > (D)
		//	(B)--1-- > (C)--1-- > (D)
		//	(C)--1-- > (A)--1-- > (D)
		//	(D)--1-- > (E)
		//	(E)--1-- > (C)
		inp1 = "B";
		inp2 = "D";
		inp3 = 1;
		set_state_2();

		cout << endl << "Test 1: Add edge properly" << endl;
		cout << "Starting test state:" << endl;
		print_state();
		cout << "Input: \"" << inp1 << "\", \"" << inp2 << "\", " << inp3 << endl;
		cout << "Output: ";

		err = testGraph.add_edge(inp1, inp2, inp3);
		if (err == 1) {
			cout << "Error: Edge already exists" << endl;
		}
		else if (err == 2) {
			cout << "Error: Vertex \"" << inp2 << "\" does not exist" << endl;
		}
		else if (err == 3) {
			cout << "Error: Vertex \"" << inp1 << "\" does not exist" << endl;
		}
		else {
			cout << "Success!" << endl;
		}

		cout << "Output state:" << endl;
		print_state();

		//Test 2: Add edge that already exists
		//Test State : 5 vertices & 8 edges(unweighted)
		//Input : B, C, 1
		//Output : 1
		//Output State : Unchanged
		inp1 = "B";
		inp2 = "C";
		inp3 = 1;
		set_state_2();

		cout << endl << "Test 1: Add edge that already exists" << endl;
		cout << "Starting test state:" << endl;
		print_state();
		cout << "Input: \"" << inp1 << "\", \"" << inp2 << "\", " << inp3 << endl;
		cout << "Output: ";

		err = testGraph.add_edge(inp1, inp2, inp3);
		if (err == 1) {
			cout << "Error: Edge already exists" << endl;
		}
		else if (err == 2) {
			cout << "Error: Vertex \"" << inp2 << "\" does not exist" << endl;
		}
		else if (err == 3) {
			cout << "Error: Vertex \"" << inp1 << "\" does not exist" << endl;
		}
		else {
			cout << "Success!" << endl;
		}

		cout << "Output state:" << endl;
		print_state();

		//Test 3 : Add edge where destination does not exist
		//Test State : 5 vertices & 8 edges(unweighted)
		//Input : C, F, 1
		//Output : 2
		//Output State : Unchanged
		inp1 = "C";
		inp2 = "F";
		inp3 = 1;
		set_state_2();

		cout << endl << "Test 1: Add edge where destination does not exist" << endl;
		cout << "Starting test state:" << endl;
		print_state();
		cout << "Input: \"" << inp1 << "\", \"" << inp2 << "\", " << inp3 << endl;
		cout << "Output: ";

		err = testGraph.add_edge(inp1, inp2, inp3);
		if (err == 1) {
			cout << "Error: Edge already exists" << endl;
		}
		else if (err == 2) {
			cout << "Error: Vertex \"" << inp2 << "\" does not exist" << endl;
		}
		else if (err == 3) {
			cout << "Error: Vertex \"" << inp1 << "\" does not exist" << endl;
		}
		else {
			cout << "Success!" << endl;
		}

		cout << "Output state:" << endl;
		print_state();

		//Test 4 : Add edge where source does not exist
		//Test State : 5 vertices & 8 edges(unweighted)
		//Input : F, A, 1
		//Output : 3
		//Output State : Unchanged
		inp1 = "F";
		inp2 = "A";
		inp3 = 1;
		set_state_2();

		cout << endl << "Test 1: Add edge where source does not exist" << endl;
		cout << "Starting test state:" << endl;
		print_state();
		cout << "Input: \"" << inp1 << "\", \"" << inp2 << "\", " << inp3 << endl;
		cout << "Output: ";

		err = testGraph.add_edge(inp1, inp2, inp3);
		if (err == 1) {
			cout << "Error: Edge already exists" << endl;
		}
		else if (err == 2) {
			cout << "Error: Vertex \"" << inp2 << "\" does not exist" << endl;
		}
		else if (err == 3) {
			cout << "Error: Vertex \"" << inp1 << "\" does not exist" << endl;
		}
		else {
			cout << "Success!" << endl;
		}

		cout << "Output state:" << endl;
		print_state();
	}

	//Test remove_edge()
	void test_remove_edge() {
		string inp1;
		string inp2;

		int err;

		//Test 1 : Remove edge properly
		//Test State : 5 vertices & 8 edges(unweighted)
		//Input : B, C
		//Output : 0
		//Output State :
		//	(A)--1-- > (B)--1-- > (C)--1-- > (D)
		//	(B)
		//	(C)--1-- > (A)--1-- > (D)
		//	(D)--1-- > (E)
		//	(E)--1-- > (C)
		inp1 = "B";
		inp2 = "C";
		set_state_2();

		cout << endl << "Test 1: Remove edge properly" << endl;
		cout << "Starting test state:" << endl;
		print_state();
		cout << "Input: \"" << inp1 << "\", \"" << inp2 << "\"" << endl;
		cout << "Output: ";

		err = testGraph.remove_edge(inp1, inp2);
		if (err == 1) {
			cout << "Error: No edge with destination \"" << inp2 << "\" exists" << endl;
		}
		else if (err == 2) {
			cout << "Error: Vertex \"" << inp1 << "\" does not exist" << endl;
		}
		else {
			cout << "Success!" << endl;
		}

		cout << "Output state:" << endl;
		print_state();

		//Test 2: Remove edge where source does not exist
		//Test State : 5 vertices & 8 edges(unweighted)
		//Input : F, A
		//Output : 1
		//Output State : Unchanged
		inp1 = "F";
		inp2 = "A";
		set_state_2();

		cout << endl << "Test 2: Remove edge where source does not exist" << endl;
		cout << "Starting test state:" << endl;
		print_state();
		cout << "Input: \"" << inp1 << "\", \"" << inp2 << "\"" << endl;
		cout << "Output: ";

		err = testGraph.remove_edge(inp1, inp2);
		if (err == 1) {
			cout << "Error: No edge with destination \"" << inp2 << "\" exists" << endl;
		}
		else if (err == 2) {
			cout << "Error: Vertex \"" << inp1 << "\" does not exist" << endl;
		}
		else {
			cout << "Success!" << endl;
		}

		cout << "Output state:" << endl;
		print_state();

		//Test 3 : Remove edge that does not exist
		//Test State : 5 vertices & 8 edges(unweighted)
		//Input : C, E
		//Output : 2
		//Output State : Unchanged
		inp1 = "C";
		inp2 = "E";
		set_state_2();

		cout << endl << "Test 1: Remove edge that does not exist" << endl;
		cout << "Starting test state:" << endl;
		print_state();
		cout << "Input: \"" << inp1 << "\", \"" << inp2 << "\"" << endl;
		cout << "Output: ";

		err = testGraph.remove_edge(inp1, inp2);
		if (err == 1) {
			cout << "Error: No edge from \"" << inp1 << "\" to \"" << inp2 << "\" exists" << endl;
		}
		else if (err == 2) {
			cout << "Error: Vertex \"" << inp1 << "\" does not exist" << endl;
		}
		else {
			cout << "Success!" << endl;
		}

		cout << "Output state:" << endl;
		print_state();
	}
};

