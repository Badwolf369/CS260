# Final Project: Graphs n' Stuff
A graph that is able to add vertices and edges, locate a particular vertex quickly, and locate the shortest path between given vertices.

---
## Struct *vertex*
### Variables
**int** *value* = 0;  
The integer value contained within the vertex. Depending on the use of the graph there can be as many or as little values in each vertex as needed.

**string** *id* = ***NULL***;  
Identifying string to help find this vertex and differenciate it from other vertices.

**map <string, pair <vertex\*, int>>** *edges*;  
A map containing every adjacent vertex's name and the edge's weight

---
## Class Graph
### private variables 
**map <string, vertex>** *vertices*;  
A map containing every vertex within the graph, identified by its *vertex.name* variable.

### public functions
#### int add_vertex(string *name*, int *value*)
Allocates space for a vertex with name *name* and value *value*, but with no edges.
Returns:
- 0 - success
- 1 - vertex with *name* already exists
- -1 - unknown error.

<div class="mermaid">
     graph TD
    a(Verify vertex does not already exist)--Vertex already exists-->b(Return 1)
    a--else-->c(Add vertex to the map of vertices)-->d(Return 0)
</div>

#### int remove_vertex(string *name*)
Locates and deletes the vertex specified with *name* and also removes all edges pointing to it.
Returns:
- 0 - success
- 1 - no vertex with *name* exists
- -1 - unknown error.

<div class="mermaid">
     graph TD
    a(Verify vertex exists)--Vertex does not exist-->b(Return 1)
    a--else-->c(loop through each vertex in vertices and if it has an edge pointing to this one, delete that edge)-->d(delete vertex)-->e(return 0)
</div>

#### int add_edge(string *source*, string *desination*)
Adds the vertex with name *desination* to the vertex with name *source*'s edge list with the attached weight of *weight*.
Returns:
- 0 - success
- 1 - edge already exists with same weight (note: if weights of duplicate edges are different then the new weight will override the old weight and function will return success)
- 2 - destination does not exist
- 3 - source does not exist
- -1 - unknown error.

<div class="mermaid">
     graph TD
    a(Verify that source exists)--source does not exist-->b(Return 3)
    a--else-->c(Verify that destination exists)--destination does not exist-->d(Return 2)
    c--else-->e(make sure the edge is not a duplicate)--source is a duplicate-->f(Return 1)
    e--else-->g(add proper information to edges in source)-->h(Return 0)
</div>




#### int remove_edge(string *source*, string *desination*)
Removes edge which points to vertex with name *destination* from vertex with name *source*
Returns:
- 0 - success
- 1 - no edge pointing to *desination* exists
- 2 - source does not exist
- -1 - unknown error.

<div class="mermaid">
     graph TD
    a(Verify that source exists)--source does not exist-->b(Return 2)
    a--else-->c(Verify that edge with destination exists within source)--edge with destination does not exist-->d(Return 1)
    c--else-->e(remove edge from edges in source)-->h(Return 0)
</div>


### vertex Vector generate_minimum_tree(vertex *start*)
