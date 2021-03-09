# Final Project: Graphs n' Stuff
### **Struct** *vertex*

**int** *value* = 0;  
The integer value contained within the vertex. Depending on the use of the graph there can be as many or as little values in each vertex as needed.

**int** *id* = 0;  
Identifying integer to help find this vertex and differenciate it from other vertices.

**edge Vector** *edge* = [];  
A vector containing a pointer to each edge connected to this vertex.

### **Struct** *edge*

**int** *id* = 0;  
Identifying integer to help find this edge and differentiate it from other edges.

**int** *weight* = 0;  
Integer value containing the cost of traveling along this edge, assuming weight is even being considered.

**vertex** *end* = [];
Pointer indicating which vertex this edge connects to. 

