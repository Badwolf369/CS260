# Final Project: Graphs n' Stuff
A graph that is able to add vertices and edges, locate a particular vertex quickly, and locate the shortest path between given vertices.

---
## Useful stuff

### Struct *vertex*
**int** *value* = 0;  
The integer value contained within the vertex. Depending on the use of the graph there can be as many or as little values in each vertex as needed.

**string** *id* = ***NULL***;  
Identifying integer to help find this vertex and differenciate it from other vertices.

**edge Vector** *edges* = [];  
A vector containing pointers to each adjacent vertex. In the case of weighted edges, this is a vector of pairs, with each pair containing the adjacent vertex pointer and the weight of the edge.

---
## Class Graph
### Structure 
**vertex Vector** *vertices* = [];  
A vector containing every vertex within the graph.

### int add_edge(vertex *from*, vertex *to*, int *weight*)
Adds the vertex that *to* points to into the vertex that *from* points to with the value of *weight*.
Returns 1 on success, 0 if the edge already exists, -1 on unknown error.

### int add_vertex(string *name*, int *value*)
Allocates space for a vertex with name *name* and value *value*, but with no edges.
Returns 1 on9 success, 0 if vertex with *name* already exists, -1 on unknown error.

### inf remove_vertex(string *name)
Locates and deletes the vertex specified with *name*.
Returns 1 on success, 0 if no vertex with *name* exists, -1 on unknown error.

### int remove_edge()
Removes edge pointing to *to* from vertex *from*.
Returnz 1 on success, 0 if no edge matching criteria exists, -1 on unknown error.



### vertex Vector generate_minimum_tree(vertex *start*)
